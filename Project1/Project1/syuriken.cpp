//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"syuriken.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjSyuriken::CObjSyuriken(int x,int y,int m)
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	m_x = x - m_scroll;
	m_y = y - l_scroll;
	m_muki = -m;

	if (m == 0) {
		m_muki = 1;
	}
}

//イニシャライズ
void CObjSyuriken::Init()
{
	m_vx = 10 * m_muki;
	m_vy = 0;
	m_posture = 1.0f;//右向き0.0ｆ、左向き1.0f

	syuriken_time = 0.0f;

	spen = 0;
	t_h = false;

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Animation = false;

	Hits::SetHitBox(this, m_x + m_scroll, m_y + l_scroll + 16, 64, 32, ELEMENT_ITEM, OBJ_SYURIKEN, 1);
}

//アクション
void CObjSyuriken::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	CObjEnemy* en = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	m_x += m_vx;
	m_y += m_vy;

	if (Animation == false) {
		//m_vx += 1.0f;
		spen -= 30.0f;
		hit = Hits::GetHitBox(this);
	}

	else {
		m_vy += 9.8f / 16.0f;
		spen -= 60.0f;
	}

	//ブロックとの当たり判定
	if (Animation == false)
	{
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_x, &m_y,false,false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
			&m_vx, &m_vy
		);
	}

	if (m_hit_left == true || m_hit_right == true || m_hit_up == true)
	{
		Hits::DeleteHitBox(this);
		m_hit_left = false;
		m_hit_right = false;
		m_hit_up = false;
		Animation = true;

		Audio::Start(17);

		m_vx = -4.0f*m_muki;
		m_vy = -10.0f;
		m_y += m_vy;
		syuriken_time = 0;
	}

	syuriken_time++;

	if (syuriken_time==120.0f)
	{
		Hits::DeleteHitBox(this);
		this->SetStatus(false);
		syuriken_time = 0;
	}
	
	if (t_h == true)
	{
		Hits::DeleteHitBox(this);
		this->SetStatus(false);
	}
	hit->SetPos(m_x + m_scroll, m_y + l_scroll + 16);
}

//ドロー
void CObjSyuriken::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f*(m_muki);
	src.m_right = 32.0f*(m_muki);
	src.m_bottom = 32.0f;

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	Draw::Draw(3, &src, &dst, c, spen);
}