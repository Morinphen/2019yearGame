//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"KarakuriBlock.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjKarakuriblock::CObjKarakuriblock(int x, int y, int n)
{
	m_x = x;
	m_y = y;
	num = n - 3;
}

//イニシャライズ
void CObjKarakuriblock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	Delete = false;
	HitBox_ON=true;
	Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, num, 1);
}

//アクション
void CObjKarakuriblock::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//ヒットボックス生成
		if (HitBox_ON == false)
		{
			HitBox_ON = true;
			Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, num, 1);
		}
		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + m_scroll, m_y + l_scroll);

	}
	//表示画面外の時
	else
	{
		//ヒットボックス削除
		if (HitBox_ON == true)
		{
			HitBox_ON = false;
			Hits::DeleteHitBox(this);
		}
	}
	//レバーが起動したら自分を消す
	if (Delete == true)
	{
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->Deletemap(m_x, m_y);
		Hits::DeleteHitBox(this);
		this->SetStatus(false);
	}

}

//ドロー
void CObjKarakuriblock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	// 表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//ブロック表示
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(26, &src, &dst, c, 0.0f);
	}
}