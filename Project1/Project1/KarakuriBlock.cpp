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
	num = n + 3;
}

//イニシャライズ
void CObjKarakuriblock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, num, 1);
}

//アクション
void CObjKarakuriblock::Action()
{

	//表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	
		//主人公の位置を取得
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float hx = hero->GetX();
		float hy = hero->GetY();

		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + m_scroll, m_y + l_scroll);	
	

	//CObjKarakuri* karakuri = (CObjKarakuri*)Objs::GetObj(num);
	////レバーが起動した
	//if (karakuri->GetON_OFF() == true)
	//{

	//	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//	pb->Deletemap(m_x, m_y);

	//	Hits::DeleteHitBox(this);
	//	this->SetStatus(false);
	//}
}

//ドロー
void CObjKarakuriblock::Draw()
{
	float c[4] = { 0.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//ブロック表示
	/*src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_x + l_scroll;
	dst.m_left = m_y + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);*/
}