//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hinotama.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjHinotama::CObjHinotama(int x, int y, int m)
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	m_x = x - m_scroll;
	m_y = y - l_scroll;
	m_muki = -m;

	if (m == 0) {
		m_muki = 1;
		spen = 90;
	}
	else {
		spen = 270;
	}
}

//イニシャライズ
void CObjHinotama::Init()
{
	m_vx = 5 * m_muki;
	m_vy = 0;
	m_posture = 1.0f;//右向き0.0ｆ、左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 0;//静止フレーム初期化

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Animation = false;

	Hits::SetHitBox(this, m_x + m_scroll, m_y + l_scroll, 64, 64, ELEMENT_ITEM, OBJ_HINOTAMA, 1);
}
//アクション
void CObjHinotama::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	m_x += m_vx;
	m_y += m_vy;

	m_ani_time++;

	if (m_ani_time == 4)
	{
		m_ani_frame++;
		m_ani_time = 0;
		if (m_ani_frame == 4)
			m_ani_frame = 0;
	}

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
		pb->BlockHit(&m_x, &m_y, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
			&m_vx, &m_vy
		);
	}

	if (m_hit_left == true || m_hit_right == true || m_hit_up == true ||
		hit->CheckObjNameHit(OBJ_NBLOCK) != nullptr ||
		hit->CheckObjNameHit(OBJ_HONOBLOCK) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_x > 10000 || m_x<-200 || m_y > 700)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	hit->SetPos(m_x + m_scroll, m_y + l_scroll);
}
//ドロー
void CObjHinotama::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f + (m_ani_frame*64.0f);
	src.m_left = 64.0f;
	src.m_right = 128.0f;
	src.m_bottom = 64.0f + (m_ani_frame*64.0f);

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	Draw::Draw(12, &src, &dst, c, spen);
}