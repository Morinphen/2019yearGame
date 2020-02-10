//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Scroll.h"
#include"GameL\HitBoxManager.h"
#include"main.h"

//使用するネームスペース
using namespace GameL;

CObjScroll::CObjScroll(int map[46][100])
{
	memcpy(m_map, map, sizeof(int)*(46 * 100));
}

//イニシャライズ
void CObjScroll::Init()
{
	m_scroll = 64.0f*-0.0f;
	l_scroll = 64.0f*-36.0f;
}
//アクション
void CObjScroll::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hx > 500 && hx < 600)
	{
		mn_scroll = 500 - hx;
	}
	if (hy > 80 && hy < 500)
	{
		mn_scroll = 500 - hx;
	}

	//後方スクロールライン
	if (hx < 500)
	{
		hero->SetX(500);//主人公はラインを超えないように
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	//前方スクロールライン
	if (hx > 600)
	{
		hero->SetX(600);//主人公はラインを超えないように
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	if (hy < 0)
	{
		hero->SetY(500);//主人公はラインを超えないように
		l_scroll += 64 * 9;//主人公が本来動く分だけ動かす
	}

	////下方スクロールライン
	if (hy > 600 && l_scroll>-64*46)
	{
	    hero->SetY(0);//主人公はラインを超えないように
		l_scroll -= 64 * 9;//主人公が本来動く分だけ動かす
	}

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
	dst.m_right = 1200.0f;
	dst.m_bottom = 620.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);
}

//表示画面の中にいるか調べる
bool CObjScroll::Inscrooll_check(int x, int y)
{
	if (x+64 >= -m_scroll&&
		x    <= WINDOW_SIZE_W-m_scroll&&
		y+64 >= -l_scroll&&
		y    <= 600-l_scroll)
		return true;
	else
		false;
}

void CObjScroll::Resporn_check(int x, int y)
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hx > 500 && hx < 600)
	{
		mn_scroll = 500 - hx;
	}
	if (hy > 80 && hy < 500)
	{
		mn_scroll = 500 - hx;
	}

	//後方スクロールライン
	if (hx < 500)
	{
		hero->SetX(500);//主人公はラインを超えないように
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	//前方スクロールライン
	if (hx > 600)
	{
		hero->SetX(600);//主人公はラインを超えないように
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	if (hy < 0)
	{
		hero->SetY(0);//主人公はラインを超えないように
		l_scroll -= hero->GetVY();//主人公が本来動く分だけ動かす
	}

	////下方スクロールライン
	if (hy > 500)
	{
		hero->SetY(400);//主人公はラインを超えないように
		//l_scroll -= hero->GetVY();//主人公が本来動く分だけ動かす
	}
}

void CObjScroll::Donden_check(int x, int y)
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	int yy = y;

	int Yz = 0;

	for (; yy > 64 * 9;)
	{
		yy -= 64.0 * 9;
		Yz++;
	}

	hero->SetY(yy);

	l_scroll = -(64*9)*Yz;
}