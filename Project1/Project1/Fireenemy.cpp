//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"Fireenemy.h"

//使用するネームスペース
using namespace GameL;

CObjFireEnemy::CObjFireEnemy(int x, int y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjFireEnemy::Init()
{
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;//右向き0.0f　左向き1.0f
	m_posture_time = 0;
	m_ani_time = 0;
	m_ani_frame = 1; //静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション間隔幅

	m_move = true;    //true=左　false=右

					  //blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	crhitbox = true;
	de = false;
}

//アクション
void CObjFireEnemy::Action()
{
	if (crhitbox == true && m_move == true)
	{
		Hits::DeleteHitBox(this);
		Hits::SetHitBox(this, m_px, m_py, 192, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);
		crhitbox = false;
	}
	else if (crhitbox == true && m_move == false)
	{
		Hits::DeleteHitBox(this);
		Hits::SetHitBox(this, m_px, m_py, 192, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);
		crhitbox = false;
	}

	//ブロックとの当たり判定
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
		&m_vx, &m_vy
	);


	//ブロック衝突で向きを変更
	if (m_hit_left == true && m_hit_right == false || m_posture_time>150 && m_move == false)
	{
		m_move = true;
		crhitbox = true;
		m_posture_time = 0;
	}

	if (m_hit_right == true && m_hit_left == false || m_posture_time>150 && m_move == true)
	{
		m_move = false;
		crhitbox = true;
		m_posture_time = 0;
	}
	//通常速度
	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	//方向
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 1;
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	m_posture_time += 1;
	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
	CHitBox* hit = Hits::GetHitBox(this);
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (m_move == true)
	{
		hit->SetPos(m_px + block->GetScroll() - 128, m_py + block->GetYScroll());
	}
	else if (m_move == false)
	{
		hit->SetPos(m_px + block->GetScroll(), m_py + block->GetYScroll());
	}
	//ブロック衝突で向きを変更
	/*	if (hit->CheckObjNameHit(OBJ_HAMUTARO) != nullptr && m_move == false)
	{
	m_move = true;
	crhitbox = true;
	m_posture_time = 0;
	}
	else if (hit->CheckObjNameHit(OBJ_HAMUTARO) != nullptr && m_move == true)
	{
	m_move = false;
	crhitbox = true;
	m_posture_time = 0;
	}*/
	if (hit->CheckObjNameHit(OBJ_HINOTAMA) != nullptr)
	{
		CObjHinotama* sy = (CObjHinotama*)Objs::GetObj(OBJ_HINOTAMA);
		sm_x = sy->GetX();
		p = sy->GetP();
		if (m_move == true)//敵左向き
		{
			if (p == true)//手裏剣左向き
			{
				Audio::Start(14);
				CObjDsyuriken*objn = new CObjDsyuriken(m_px, m_py);
				Objs::InsertObj(objn, OBJ_DSYURIKEN, 3);
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				sy->SetT(true);
			}
			else//手裏剣右向き
			{
				if (sm_x + 2.0 >= m_px)
				{
					Audio::Start(14);
					CObjDsyuriken*objn = new CObjDsyuriken(m_px, m_py);
					Objs::InsertObj(objn, OBJ_DSYURIKEN, 3);
					this->SetStatus(false);
					Hits::DeleteHitBox(this);
					sy->SetT(true);
				}
			}
		}
		else//敵右向き
		{
			if (p == true)//手裏剣左向き
			{
				if (sm_x - 2.0 <= m_px)
				{
					Audio::Start(14);
					CObjDsyuriken*objn = new CObjDsyuriken(m_px, m_py);
					Objs::InsertObj(objn, OBJ_DSYURIKEN, 3);
					this->SetStatus(false);
					Hits::DeleteHitBox(this);
					sy->SetT(true);
				}
			}
			else//手裏剣右向き
			{
				Audio::Start(14);
				CObjDsyuriken*objn = new CObjDsyuriken(m_px, m_py);
				Objs::InsertObj(objn, OBJ_DSYURIKEN, 3);
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				sy->SetT(true);
			}
		}
	}
}

//ドロー
void CObjFireEnemy::Draw()
{
	int AniData[4] =
	{
		0,1,0,1,
	};

	//描画カラー情報
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

				//切り取り位置の設定
	src.m_top = 65.0f;
	src.m_left = 448.0f*AniData[m_ani_frame] - 64;
	src.m_right = 448.0f*AniData[m_ani_frame];
	src.m_bottom = 128.0f;

	//ブロック情報を持ってくる
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);

	//表示位置の設定
	dst.m_top = 0.0f + m_py + scroll->GetYScroll();
	dst.m_left = (64 - 64.0f*m_posture) + m_px + scroll->GetScroll();
	dst.m_right = (64.0f*m_posture) + m_px + scroll->GetScroll();
	dst.m_bottom = 64.0f + m_py + scroll->GetYScroll();

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);

	RECT_F srcs; //描画元切り取り位置
	RECT_F dsts; //描画先表示位置
	if (m_move == true)
	{
		srcs.m_top = 0.0f;
		srcs.m_left = 0.0f;
		srcs.m_right = 300.0f;
		srcs.m_bottom = 300.0f;
		//表示位置の設定
		dsts.m_top = dst.m_top;
		dsts.m_left = dst.m_left - 230.0f;
		dsts.m_right = dst.m_right + 64;
		dsts.m_bottom = dst.m_bottom;
	}
	else
	{
		srcs.m_top = 0.0f;
		srcs.m_left = 300.0f;
		srcs.m_right = 0.0f;
		srcs.m_bottom = 300.0f;
		//表示位置の設定
		dsts.m_top = dst.m_top;
		dsts.m_left = dst.m_left;
		dsts.m_right = dst.m_right + 166.0f;
		dsts.m_bottom = dst.m_bottom;
	}
	//描画
	Draw::Draw(32, &srcs, &dsts, c, 0.0f);
	/*if(find==true)
	{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py + scroll->GetYScroll()+64;
	dst.m_left = (64 - 64.0f*m_posture) + m_px + scroll->GetScroll();
	dst.m_right = (64.0f*m_posture) + m_px + scroll->GetScroll();
	dst.m_bottom = 64.0f + m_py + scroll->GetYScroll()+64;

	//描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
	}*/
}