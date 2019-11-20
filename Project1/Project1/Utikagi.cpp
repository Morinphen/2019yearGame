//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Utikagi.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjUtikagi::CObjUtikagi(int x, int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjUtikagi::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	flag = false;
	Bflag = false;

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_UTIKAGI, 1);
}
//アクション
void CObjUtikagi::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr && Input::GetVKey(VK_UP))
	{
		bool stop;
		stop = h->GetNawa();
		float h_vx = h->GetVX();

		if (stop == false && Bflag == false) {
			Audio::Start(12);
			flag = flag ? false : true;
			h->Uflag(flag);
			Bflag = true;
		}
	}

	else
	{
		Bflag = false;
	}

	hit->SetPos(m_x + m_scroll, m_y + l_scroll);
}
//ドロー
void CObjUtikagi::Draw()
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

	Draw::Draw(10, &src, &dst, c, 0.0f);
}

void CObjUtikagi::Refresh()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	h->SetX(m_x);

	if (h->GetX()>400)
	scroll->SetScrooll(-(h->GetX() - (400)));
	else if (h->GetX()>250)
	scroll->SetScrooll(-(h->GetX() - (250)));
}