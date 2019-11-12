//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Block.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[46][100])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(46 * 100));
}

//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	aaa = 0;
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_BLOCK, 1);
}
//アクション
void CObjBlock::Action()
{
	
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();



}
//ドロー
void CObjBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//ブロック表示
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;

			dst.m_top = i*64.0f + l_scroll;
			dst.m_left = j*64.0f + m_scroll;
			dst.m_right = dst.m_left + 64.0f;
			dst.m_bottom = dst.m_top + 64.0f;

			if (m_map[i][j] == 1)
			{
				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
		}
	}
}


//ブロックとの当たり判定関数(BlockHit関数)
//引数1  float* x          ;判定を行うobjectのx位置
//引数2  float* y          ;判定を行うobjectのy位置
//引数3  bool*  up         ;上下左右判定の上部分に当たっているかどうかを返す
//引数4  bool*  down       ;上下左右判定の下部分に当たっているかどうかを返す
//引数5  bool*  left       ;上下左右判定の左部分に当たっているかどうかを返す
//引数6  bool*  right      ;上下左右判定の右部分に当たっているかどうかを返す
//引数7  bool   smoke      ;煙玉かを判定する(true:煙玉)
//引数8  float* vx         ;左右判定時の反発による移動方向・力の値変えて返す
//引数9  float* vy         ;上下判定時による自由落下運動の移動方向・力の値変えて返す
//判定を行うobjectとブロック64＊64限定で、当たり判定と上下左右半手を行う
//その結果は引数3～8に返す
void CObjBlock::BlockHit
(
	float* x, float* y, bool s,
	bool*up, bool* down, bool* left, bool* right,bool smoke,
	float *vx, float *vy
)
{
	//主人公の衝突確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] == 1)
			{
				//要素番号を座標に変更
				float bx = j*64.0f;
				float by = i*64.0f;

				float m_s=0;
				float l_s=0;

				if (s == true)
				{
					CObjScroll * scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
					m_s = scroll->GetScroll();
					l_s = scroll->GetYScroll();
				}

				//オブジェクトとブロックの当たり判定
				if ((*x + (-m_s) + 64.0f > bx) && (*x + (-m_s)<bx + 64.0f) && (*y + (-l_s) + 64.0f>by) && (*y + (-l_s)<by + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-m_s)) - bx;
					float rvy = (*y + (-l_s)) - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy * rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						//煙玉か判定
						if (smoke == false)
						{
							//角度で上下左右を判定
							if ((r < 45 && r>0) || r > 315)
							{
								//右
								*right = true;//主人公の左の部分が衝突しているか
								*x = bx + 64.0f + (m_s);//ブロックに位置-主人公の幅
								*vx = -(*vx)*0.1f;//-VX*反発係数
							}

							if (r > 45 && r < 135)
							{
								//上
								*down = true;//主人公の下の部分が衝突しているか
								*y = by - 64.0f + (l_s);//ブロックに位置-主人公の幅
								*vy = 0.0f;
							}

							if (r > 135 && r < 225)
							{
								//左
								*left = true;//主人公の右の部分が衝突しているか
								*x = bx - 64.0f + (m_s);//ブロックに位置-主人公の幅
								*vx = -(*vx)*0.1f;//-VX*反発係数
							}

							if (r > 225 && r < 315)
							{
								//下
								*up = true;//主人公の上の部分が衝突しているか
								*y = by + 64.0f + (l_s);//ブロックの位置+主人公の幅
								if (*vy < 0)
								{
									*vy = 0.0f;
								}
							}
						}
						else
						{
							//角度で上下左右を判定
							if ((r < 45 && r>0) || r > 315)
							{
								//右
								*right = true;//煙玉の左の部分が衝突しているか
								*x = bx + 64.0f + (m_s);//ブロックに位置-煙玉の幅
								*vx = -(*vx)*0.0f;//-VX*反発係数
							}

							if (r > 45 && r < 135)
							{
								//上
								*down = true;//主人公の下の部分が衝突しているか
								*y = by - 64.0f + (l_s);//ブロックに位置-主人公の幅
								*vy = 0.0f;
								CObjSmokeball* smokeball = (CObjSmokeball*)Objs::GetObj(OBJ_SMOKEBALL);
								smokeball->Setmodecheck(true);
							}

							if (r > 135 && r < 225)
							{
								//左
								*left = true;//煙玉の右の部分が衝突しているか
								*x = bx - 64.0f + (m_s);//ブロックに位置-煙玉の幅
								*vx = -(*vx)*0.0f;//-VX*反発係数
							}

							if (r > 225 && r < 315)
							{
								//下
								*up = true;//煙玉の上の部分が衝突しているか
								*y = by + 64.0f + (l_s);//ブロックの位置+煙玉の幅
								if (*vy < 0)
								{
									*vy = 0.0f;
								}
							}
						}
					}
				}
			}
		}
	}
}

void CObjBlock::UBlockHit
(
	float* x, float* y, bool* flag,
	bool*up, bool* down, bool* left, bool* right,
	float *vx, float *vy
)
{
	//主人公の衝突確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] != 7)
			{
				//要素番号を座標に変更
				float bx = j*64.0f;
				float by = i*64.0f;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-m_scroll) + 64.0f > bx) && (*x + (-m_scroll) < bx + 64.0f) && (*y + (-l_scroll) + 64.0f > by) && (*y + (-l_scroll) < by + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-m_scroll)) - bx;
					float rvy = (*y + (-l_scroll)) - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy * rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);

					else
						r = 360.0f - abs(r);

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
						//角度で上下左右を判定
						if ((r < 45 && r>=0) || r > 315)
						{
							//右
							*right = true;//主人公の左の部分が衝突しているか
							*x = bx + 64.0f + (m_scroll);//ブロックに位置-主人公の幅

							if (*flag == false)
							{
								scroll->SetScrooll(m_scroll - 64);
								*flag = true;
							}
							else
							{
								*vx = -(*vx)*0.0f;//-VX*反発係数
							}
						}

						//if (r > 45 && r < 135)
						//{
						//	//上
						//	*down = true;//主人公の下の部分が衝突しているか
						//	*y = by - 64.0f + (l_scroll);//ブロックに位置-主人公の幅
						//	*vy = 0.0f;
						//}

						if (r > 135 && r < 225)
						{
							//左
							*left = true;//主人公の右の部分が衝突しているか

							if (*flag == false)
							{
								scroll->SetScrooll(m_scroll + 64);
								*flag = true;
							}

							else
							{
								*vx = -(*vx)*0.0f;//-VX*反発係数
							}

							*x = bx - 64.0f + (m_scroll);//ブロックに位置-主人公の幅
						}
					}
				}
			}
		}
	}
}
////内積関数
////引数1,2float ax,ay:Aベクトル
////引数3,4float bx,by:Bベクトル
////戻り値　float :射影
////内容　AベクトルとBベクトルで内積を行い射影を求める
//float CObjBlock::Dot(float ax, float ay, float bx, float by)
//{
//	float t = 0.0f;
//	t = ax*bx + ay*by;
//	return t;
//}
//
////外積関数
////引数1,2float ax,ay:Aベクトル
////引数3,4float bx,by:Bベクトル
////戻り値　float :射影
////内容　AベクトルとBベクトルで外積を行い射影を求める
//float CObjBlock::Cross(float ax, float ay, float bx, float by)
//{
//	float t = 0.0f;
//	t = ax*by + ay*bx;
//	return t;
//}
////符号を求めるマクロ
//#define SGN(x)1-(x<=0)-(x<0)
//
////線と線と交差判定
////引数 float 1,2 a1x,a1y:軸ベクトルAの始点
////引数 float 3,4 a2x,a2y:軸ベクトルAの終点
////引数 float 5,6 b1x,b1y:ベクトルBの始点
////引数 float 7,8 b2x,b2y:ベクトルBの終点
////引数 float 9,10 out_px,out_py :交差するベクトルの交点位置
////戻り値 bool :true=交点あり false=なし
////内容:っ引数のA・Bベクトルの交点を見つけ、out_pxとout_pyに返す
//bool CObjBlock::LineCrossPoint(
//	float a1x, float a1y, float a2x, float a2y,
//	float b1x, float b1y, float b2x, float b2y,
//	float* out_px, float* out_py
//)
//{
//	//エラーコード
//	*out_px - 9999.0f; *out_py = -9999.0f;
//
//	//Aベクトル作成(a2←a1)
//	float ax = a2x - a1x; float ay = a2y - a1y;
//
//	//Bベクトル作成(b2←b1)
//	float bx = b2x - b1x; float by = b2y - b1y;
//
//	//Cベクトル作成(b1←a1)
//	float cx = b1x - a1x; float cy = b1y - a1y;
//
//	//Dベクトル作成(b2←a1)
//	float dx = b2x - a1x; float dy = b2y - a1y;
//
//	//A*Cの射影とA*Bの射影を求める
//	float t1 = Cross(ax, ay, cx, cy);
//	float t2 = Cross(ax, ay, dx, dy);
//
//	//符号が同じ方向になっているかどうかをチェック
//	if (SGN(t1) == SGN(t2))
//		return false;
//
//	//射影を絶対値化
//	t1 = abs(t1); t2 = abs(t2);
//
//	//交点を求める
//	float px = bx*(t1 / (t1 + t2)) + b1x;
//	float py = by*(t1 / (t1 + t2)) + b1y;
//
//	//APベクトル(p←a1)
//	float apx = px - a1x; float apy = py - a1y;
//
//	//BPベクトル(p←a2)
//	float bpx = px - a2x; float bpy = py - a2y;
//
//	//A・APの射影とA・Bの射影を求める
//	float w1 = Dot(ax, ay, apx, apy);
//	float w2 = Dot(ax, ay, bpx, bpy);
//
//	//符号チェック
//	if (SGN(w1) == SGN(w2))
//		return false;//交点が外
//
//	//交点を返す
//	*out_px = px; *out_py = py;
//	return true;
//}
//
////主人公と壁の交差安定関数
////引数1,2 float x,y:主人公の位置
////引数3,4 float vx,vy:主人公の移動ベクトル
////引数5,6 float* out_x,out_y:Blockとの交点
////引数7 float* out:位置から交点までの距離
////主人公の位置+移動ベクトルと各ブロックの辺で交点判定を行い
////最も近い交点の位置と距離を返す
//bool CObjBlock::HeroBlockCrossPoint(
//	float x, float y, float vx, float vy,
//	float *out_px, float *out_py, float* out_len
//)
//{
//	bool pb = false;//交点確認用
//	float len = 89999.0f;
//	//ブロックの辺ベクトル
//	float edge[4][4] =
//	{
//		{ 0,0,64, 0 },//上辺
//		{ 64,0,64,64 },//右辺
//		{ 64,64,0,64 },//下辺
//		{ 0,64,0,0 },//左辺
//	};
//
//	for (int k = 0; k < 4; k++)
//	{
//		//交点を探す
//		float px, py;
//		bool b;
//		float l = 0.0f;
//		b = LineCrossPoint(x, y, x + vx, y + vy,
//			64 + edge[k][0], 64 + edge[k][1], 64 + edge[k][2], 64 + edge[k][3],
//			&px, &py);
//		//交点チェック
//		if (b == true)
//		{
//			//交点との距離を求める
//			l = sqrt((px - x)*(px - x) + (py - y)*(py - y));
//
//			//見つけた交点の中で最も距離が短いものを探す
//			if (len > l)
//			{
//				len = l;
//				*out_px = px;
//				*out_py = py;
//				pb = true;
//			}
//		}
//	}
//
//	*out_len = len;
//	return pb;
//}