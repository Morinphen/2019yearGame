//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include "TuriBlock.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjTBlock::CObjTBlock(int x, int y)
{
	m_x = x;
	m_y = y;
	sm_x = x;
	sm_y = y;
}

//イニシャライズ
void CObjTBlock::Init()
{
	m_ani_frame = 0;
	m_ani_time = 0;
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	n = 0;

	modecheck = false;//モード切替
	Hits::SetHitBox(this, m_x, m_y, 64, 576, ELEMENT_BLACK, OBJ_TURIBLOCK, 1);
	HitBox_ON = true;
}
//アクション
void CObjTBlock::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//ヒットボックス生成
		if (HitBox_ON == false)
		{
			HitBox_ON = true;
			Hits::SetHitBox(this, m_x, m_y, 64, 576, ELEMENT_BLACK, OBJ_TURIBLOCK, 1);
		}

		//主人公の位置を取得
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float hx = hero->GetX();
		float hy = hero->GetY();

		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_TURIBLOCK);


		//要素番号を安俵に変更
		float x = m_x;
		float y = m_y;

		m_ani_time++;
		if (m_ani_time == 16)
		{
			m_ani_time = 0;
			m_ani_frame++;
			if (m_ani_frame == 4)
			{
				m_ani_frame = 0;
			}
		}

		CHitBox* hit = Hits::GetHitBox(this);

		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			//主人公と当たったらフラグをオンに
			modecheck = true;

			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_TURIBLOCK2, 1);
		}

		hit->SetPos(m_x + m_scroll, m_y + l_scroll);
	}

	else
	{
		//ヒットボックス削除
		if (HitBox_ON == true)
		{
			HitBox_ON = false;
			Hits::DeleteHitBox(this);
		}

	}

	//ブロックを落とす
	if (modecheck == true)
	{
		m_y += 4;
		n++;
		//落ちきったら元の位置に戻す
		if (n / 38 == 3)
		{
			n = 0;
			modecheck = false;
			m_x = sm_x;
			m_y = sm_y;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 64, 576, ELEMENT_BLACK, OBJ_TURIBLOCK, 1);
		}
	}
}
//ドロー
void CObjTBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//ブロック表示
		src.m_top = 0.0f;
		src.m_left = 0.0f + (m_ani_frame*64.0f);
		src.m_right = 64.0f + (m_ani_frame*64.0f);
		src.m_bottom = 64.0f;

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;
		Draw::Draw(14, &src, &dst, c, 0.0f);
	}
}