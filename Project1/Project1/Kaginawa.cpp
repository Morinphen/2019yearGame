//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Kaginawa.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjKaginawa::CObjKaginawa(int x, int y,int a)
{
	m_muki = -a;

	if (a == 0) {
		m_muki = 1;
	}

	sm_x = m_x = x + (300 * m_muki);
	sm_y = m_y = y;
}

//イニシャライズ
void CObjKaginawa::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	m_vx = 1.0f;
	m_vy = 1.0f;

	direction = 1;//方向初期化
	D_Count = 0;
	D_Suiti = false;

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_KAGINAWA, 1);
}
//アクション
void CObjKaginawa::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	float r = 3.14f / 180.0f;

	float bm_x = m_x - (h->GetX() + 200);
	float bm_y = m_y - (h->GetY());

	m_x = h->GetX() + 200;
	m_y = h->GetY();

	if (D_Suiti == false) {
		m_vx = m_vx*cos(r) - m_vy*sin(r);
		m_vy = m_vy*cos(r) + m_vx*sin(r);

		m_x += (m_vx*m_muki) * 2 + bm_x;
		m_y += -m_vy * 2.5 + bm_y;
	}

	else {
		m_vx = m_vx*cos(-r) - m_vy*sin(-r);
		m_vy = m_vy*cos(-r) + m_vx*sin(-r);

		m_x += -(m_vx*m_muki) * 2 + bm_x;
		m_y += m_vy* 2.5 + bm_y;
	}

	D_Count++;

	if (D_Count == 1) {
		if (D_Suiti == false)
			direction++;

		else
			direction--;
		D_Count = 0;
	}

	if (direction >= 120)
		D_Suiti = true;
	else if (direction <= 0) {
		m_x = sm_x;
		m_y = sm_y;
		m_vx = 1.0f;
		m_vy = 1.0f;
		D_Suiti = false;
	}

	if (Input::GetVKey('A'))
	{
		float a = abs(m_x - h->GetX());
		float b = abs(m_y - h->GetY());
		CObjNagenawa* obj_s = new CObjNagenawa(h->GetX(), h->GetY(), m_muki, a, b);
		Objs::InsertObj(obj_s, OBJ_NAGENAWA, 10);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	hit->SetPos(m_x, m_y);
}
//ドロー
void CObjKaginawa::Draw()
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

	Draw::Draw(9, &src, &dst, c, 0.0f);
}