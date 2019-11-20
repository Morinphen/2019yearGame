//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hamutaro.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjNezumi::CObjNezumi(int x, int y, int muki)
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	m_x = x - m_scroll;
	m_y = y - l_scroll;
	m_posture = muki;
}

//イニシャライズ
void CObjNezumi::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	flag = false;
	Bflag = false;

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_HAMUTARO, 1);
}
//アクション
void CObjNezumi::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	if (m_posture == 0)
	{
		m_x += 2.0f;
	}

	else
	{
		m_x -= 2.0f;
	}

	hit->SetPos(m_x + m_scroll, m_y + l_scroll);
}
//ドロー
void CObjNezumi::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
