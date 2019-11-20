//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"GameL\HitBoxManager.h"


//使用するネームスペース
using namespace GameL;

CObjKarakuri::CObjKarakuri(int x, int y,int n)
{
	m_x = x;
	m_y = y;
	num = n;
}

//イニシャライズ
void CObjKarakuri::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;

	on_off = false;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_KARAKURI, 1);
}

//アクション
void CObjKarakuri::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	CHitBox* hit = Hits::GetHitBox(this);

	if (on_off == false)
	{
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr&&Input::GetVKey(VK_UP))
		{
			Hits::DeleteHitBox(this);

			if (num == 1)
			{
				//こ↑こ↓にマップに変更処理
				on_off = true;
			}
			else if (num == 2)
			{
				//こ↑こ↓にマップに変更処理
				on_off = true;
			}
			else if (num == 3)
			{
				//こ↑こ↓にマップに変更処理
				on_off = true;
			}
		}
		hit->SetPos(m_x + m_scroll, m_y + l_scroll);
	}

	
}

//ドロー
void CObjKarakuri::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (on_off == false)
	{
		//ブロック表示
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;
		
	}
	else
	{
		//ブロック表示
		src.m_top = 64.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 0.0f;
	}

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	Draw::Draw(16, &src, &dst, c, 0.0f);
}