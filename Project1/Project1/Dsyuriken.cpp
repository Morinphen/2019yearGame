//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Dsyuriken.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjDsyuriken::CObjDsyuriken(int x, int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjDsyuriken::Init()
{
	deadtime = 0;
	m_scroll = 0.0f;
	l_scroll = 0.0f;

}
//アクション
void CObjDsyuriken::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	//メニュー用の情報取得
	CObjMany* mn = (CObjMany*)Objs::GetObj(OBJ_MANY);
	bool m_stop = mn->GetOpen();

	if (m_stop == false) {
		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();
		deadtime += 1;
		if (deadtime == 100)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
}
//ドロー
void CObjDsyuriken::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,(1.0f - deadtime / 100) };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0;
	src.m_right = 346.0f;
	src.m_bottom = 512.0f;
	//ブロック情報を持ってくる
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);

	dst.m_top = (0.0f + m_y - 64 + scroll->GetYScroll()) + (64 * (1 - deadtime / 120));
	dst.m_bottom = (64.0f + m_y - 64 + scroll->GetYScroll()) + (64 * (1 - deadtime / 120));
	dst.m_left = (64.0f+m_x + scroll->GetScroll());
	dst.m_right = (64.0f - 64.0f+ m_x + scroll->GetScroll());
	Draw::Draw(43, &src, &dst, c, 0.0f);

}