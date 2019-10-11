//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Scroll.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjScroll::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
}
//アクション
void CObjScroll::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	if (hx < 80)
	{
		hero->SetX(80);//主人公はラインを超えないように
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	//前方スクロールライン
	if (hx > 300)
	{
		hero->SetX(300);//主人公はラインを超えないように
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	//上方スクロールライン
	if (hy < 80)
	{
		hero->SetY(80);//主人公はラインを超えないように
		l_scroll -= hero->GetVY();//主人公が本来動く分だけ動かす
	}

	//下方スクロールライン
	if (hy > 500 && l_scroll>-100)
	{
		hero->SetY(500);//主人公はラインを超えないように
		l_scroll -= hero->GetVY();//主人公が本来動く分だけ動かす
	}

	//主人公の衝突状態確認用ﾌﾗｸﾞの初期化
	hero->SetUP(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

}
//ドロー
void CObjScroll::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//背景表示
	src.m_top = 300.0f - (l_scroll / 4);
	src.m_left = 100.0f - (m_scroll / 4);
	src.m_right = 700.0f - (m_scroll / 4);
	src.m_bottom = 1000.0f - (l_scroll / 4);
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 800.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);
}