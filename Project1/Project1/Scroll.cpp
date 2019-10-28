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
	l_scroll = 0.0f;
}
//アクション
void CObjScroll::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//敵の位置を取得
	CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	float hx = hero->GetX();
	float hy = hero->GetY();

	float vx = hero->GetVX();
	float vy = hero->GetVY();

	//後方スクロールライン
	if (hx < 250)
	{
		hero->SetX(250);//主人公はラインを超えないように
		enemy->SetVX(-vx);
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	//前方スクロールライン
	if (hx > 400)
	{
		hero->SetX(400);//主人公はラインを超えないように
		enemy->SetVX(vx);
		m_scroll -= hero->GetVX();//主人公が本来動く分だけ動かす
	}

	//上方スクロールライン
	if (hy < 80)
	{
		hero->SetY(80);//主人公はラインを超えないように
		enemy->SetVY(-vy);
		l_scroll -= hero->GetVY();//主人公が本来動く分だけ動かす
	}

	//下方スクロールライン
	if (hy > 500 && l_scroll>-100)
	{
		hero->SetY(500);//主人公はラインを超えないように
		enemy->SetVY(vy);
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