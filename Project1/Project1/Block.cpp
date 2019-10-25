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

CObjBlock::CObjBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_BLOCK, 1);
}
//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//敵の位置を取得
	CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	float ex = enemy->GetX();
	float ey = enemy->GetY();

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	//要素番号を安俵に変更
	float x = m_x;
	float y = m_y;

	//主人公とブロックの当たり判定
	if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + (-l_scroll) + 64.0f > y) && (hy + (-l_scroll) < y + 64.0f))
	{
		//上下左右判定

		//vectorの作成
		float vx = (hx + (-m_scroll)) - x;
		float vy = (hy + (-l_scroll)) - y;
		//長さを求める
		float len = sqrt(vx*vx + vy*vy);

		//角度を求める
		float r = atan2(vy, vx);
		r = r * 180 / 3.14;
		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//lenがある一定の長さのより短い場合判定に入る
		if (len < 88.0f) {
			//角度で上下左右を判定
			if ((r < 45 && r>=0) || r > 315)
			{
				//右
				hero->SetRight(true);//主人公の左の部分が衝突している
				hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
				hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
			}
			else if (r > 45 && r < 135)
			{
				//上
				hero->SetDown(true);//主人公から見て下の部分が衝突している
				hero->SetY(y - 64.0f + (l_scroll));//ブロックの位置-主人公の幅
				hero->SetVY(0.0f);
			}
			else if (r > 135 && r < 225)
			{
				//左
				hero->SetLeft(true);//主人公の右の部分が衝突している
				hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置+主人公の幅
				hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
			}
			else if (r > 225 && r < 315)
			{
				//下
				hero->SetUP(true);//主人公から見て上の部分が当たっている
				hero->SetY(y + 64.0f + (l_scroll));//ブロックの位置+主人公の幅
				if (hero->GetVY() < 0)
				{
					hero->SetVY(0.0f);
				}
			}
		}
	}

	//主人公とブロックの当たり判定
	if ((ex + (-m_scroll) + 64.0f > x) && (ex + (-m_scroll) < x + 64.0f) && (ey + (-l_scroll) + 64.0f > y) && (ey + (-l_scroll) < y + 64.0f))
	{
		//上下左右判定

		//vectorの作成
		float evx = (ex + (-m_scroll)) - x;
		float evy = (ey + (-l_scroll)) - y;
		//長さを求める
		float elen = sqrt(evx*evx + evy*evy);

		//角度を求める
		float er = atan2(evy, evx);
		er = er * 180 / 3.14;
		if (er <= 0.0f)
			er = abs(er);
		else
			er = 360.0f - abs(er);

		//lenがある一定の長さのより短い場合判定に入る
		if (elen < 88.0f) {
			//角度で上下左右を判定
			if ((er < 45 && er >= 0) || er > 315)
			{
				//右
			    enemy->SetRight(true);//敵の左の部分が衝突している
				enemy->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
				enemy->SetVX(-enemy->GetVX()*0.1f);//-VX*反発係数
			}
			else if (er > 45 && er < 135)
			{
				//上
				enemy->SetDown(true);//敵から見て下の部分が衝突している
				enemy->SetY(y - 64.0f + (l_scroll));//ブロックの位置-主人公の幅
				enemy->SetVY(0.0f);
			}
			else if (er > 135 && er < 225)
			{
				//左
				enemy->SetLeft(true);//敵の右の部分が衝突している
			    enemy->SetX(x - 64.0f + (m_scroll));//ブロックの位置+主人公の幅
				enemy->SetVX(-enemy->GetVX()*0.1f);//-VX*反発係数
			}
			else if (er > 225 && er < 315)
			{
				//下
				enemy->SetUP(true);//敵から見て上の部分が当たっている
				enemy->SetY(y + 64.0f + (l_scroll));//ブロックの位置+主人公の幅
				if (enemy->GetVY() < 0)
				{
					enemy->SetVY(0.0f);
				}
			}
		}
	}

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll, m_y + l_scroll);
}
//ドロー
void CObjBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//ブロック表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
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