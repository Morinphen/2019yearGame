//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"NezuBlock.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjNezublock::CObjNezublock(int x, int y, int n)
{
	m_x = x;
	m_y = y;
	Namber = n + 6;

	dflag = false;
}

//イニシャライズ
void CObjNezublock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, Namber, 1);
}

//アクション
void CObjNezublock::Action()
{
	// 表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//主人公の位置を取得
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float hx = hero->GetX();
		float hy = hero->GetY();

		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		CObjNezuana* Nezu = (CObjNezuana*)Objs::GetObj(Namber);
		dflag = Nezu->GetDnamber();

		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + m_scroll, m_y + l_scroll);

		if (dflag == true)
		{
			CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
			pb->Deletemap(m_x, m_y);

			Hits::DeleteHitBox(this);
			this->SetStatus(false);
		}
	}
}

//ドロー
void CObjNezublock::Draw()
{
	float c[4] = { 0.0f,1.0f,1.0f,1.0f };
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
	Draw::Draw(22, &src, &dst, c, 0.0f);
}