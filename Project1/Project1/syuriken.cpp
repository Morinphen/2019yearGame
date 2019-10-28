//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"syuriken.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjSyuriken::CObjSyuriken(int x,int y,int m)
{
	m_x = x;
	m_y = y;
	m_muki = -m;

	if (m == 0) {
		m_muki = 1;
	}
}

//イニシャライズ
void CObjSyuriken::Init()
{
	m_vx = 15 * m_muki;
	m_vy = 0;
	m_posture = 1.0f;//右向き0.0ｆ、左向き1.0f

	spen = 0;

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Animation = false;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_PLAYER, OBJ_SYURIKEN, 1);
}
//アクション
void CObjSyuriken::Action()
{
	m_x += m_vx;
	m_y += m_vy;

	if (Animation == false) {
		//m_vx += 1.0f;
		hit = Hits::GetHitBox(this);
	}

	else {
		m_vy += 9.8f / 16.0f;
		spen += 30.0f;
	}

	//ブロックとの当たり判定
	if (Animation == false)
	{
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_x, &m_y,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
			&m_vx, &m_vy
		);
	}

	if (m_hit_left == true || m_hit_right == true || m_hit_up == true)
	{
		m_hit_left = false;
		m_hit_right = false;
		m_hit_up = false;
		Animation = true;

		m_vx = -4.0f*m_muki;
		m_vy = -10.0f;
		m_y += m_vy;
	}

	if (m_x > 2000 || m_x<-200 || m_y > 700)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	hit->SetPos(m_x, m_y);
}
//ドロー
void CObjSyuriken::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(3, &src, &dst, c, spen);
}