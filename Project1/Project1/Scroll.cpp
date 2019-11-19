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

CObjScroll::CObjScroll(int map[10][100])
{
	memcpy(m_map, map, sizeof(int)*(10 * 100));
}

//イニシャライズ
void CObjScroll::Init()
{
	m_scroll = 0.0f;
	l_scroll = 64.0f*-36.0f;
}
//アクション
void CObjScroll::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//後方スクロールライン
	if (hx < 250)
	{
		hero->SetX(250);//主人公はラインを超えないように
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	//前方スクロールライン
	if (hx > 400)
	{
		hero->SetX(400);//主人公はラインを超えないように
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	//上方スクロールライン
	if (hy < 80)
	{
		hero->SetY(80);//主人公はラインを超えないように
		l_scroll -= hero->GetVY();//主人公が本来動く分だけ動かす
	}

	//下方スクロールライン
	if (hy > 500 && l_scroll>-64*46)
	{
		hero->SetY(500);//主人公はラインを超えないように
		l_scroll -= hero->GetVY();//主人公が本来動く分だけ動かす
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
	dst.m_right = 800.0f;
	dst.m_bottom = 800.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);
}

void CObjScroll::SetUtikagiScroll(float *hx, float *hy)
{
	//後方スクロールライン
	if (*hx < 250)
	{
		while (*hx < 250)
		{
			m_scroll += 64;//1ブロックづつ調整する（スクロール）
			*hx += 64;//1ブロックづつ調整（主人公）
		}
	}

	//前方スクロールライン
	if (*hx > 400)
	{
		while (*hx > 400)
		{
			m_scroll -= 64;//1ブロックづつ調整する（スクロール）
			*hx -= 64;//1ブロックづつ調整（主人公）
		}
	}

	//上方スクロールライン
	if (*hy < 80)
	{
		while (*hy < 80)
		{
			l_scroll -= 64;//1ブロックづつ調整する（スクロール）
			*hy -= 64;//1ブロックづつ調整（主人公）
		}
	}

	//下方スクロールライン
	if (*hy > 500 && l_scroll>-100)
	{
		while (*hy > 500)
		{
			l_scroll += 64;//1ブロックづつ調整する（スクロール）
			*hy += 64;//1ブロックづつ調整（主人公）
		}
	}
}