//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"MizuBlock.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjMBlock::CObjMBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjMBlock::Init()
{
	m_ani_frame = 0;
	m_ani_time = 0;
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	h_flag = false;
	deadtime = 0;
	Fdead = false;
	Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, OBJ_MIZUBLOCK, 1);
}
//アクション
void CObjMBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	h_flag = hero->GetMode();

	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	//上下左右判定
	float x = m_x;
	float y = m_y;

	//vectorの作成
	float vx = (hx + (-m_scroll)) - x;
	float vy = (hy + (-l_scroll)) - y;
	//長さを求める
	float len = sqrt(vx*vx + vy*vy);

	//角度を求める
	float r = atan2(vy, vx);
	r = r * 180 / 3.14;
	if (r <= 0.0f)
		r = abs(r);
	else
		r = 360.0f - abs(r);

	//lenがある一定の長さのより短い場合判定に入る
	if (len < 88.0f && h_flag == true) {
		//角度で上下左右を判定
		if ((r < 45 && r >= 0) || r > 315)
		{
			//右
			hero->SetRight(true);//主人公の左の部分が衝突している
			hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
			hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
		}
		else if (r > 45 && r < 135)
		{
			//上
			hero->SetDown(true);//主人公から見て下の部分が衝突している
			hero->SetY(y - 64.0f + (l_scroll));//ブロックの位置-主人公の幅
			hero->SetVY(0.0f);
		}
		else if (r > 135 && r < 225)
		{
			//左
			hero->SetLeft(true);//主人公の右の部分が衝突している
			hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置+主人公の幅
			hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
		}
		else if (r > 225 && r < 315)
		{
			//下
			hero->SetUP(true);//主人公から見て上の部分が当たっている
			hero->SetY(y + 64.0f + (l_scroll));//ブロックの位置+主人公の幅
			if (hero->GetVY() < 0)
			{
				hero->SetVY(0.0f);
			}
		}
	}

	//ヒットボックス更新
	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr && Fdead == false)
	{
		Fdead = true;
		hero->WDflag(true);
	}

	//主人公が着水したとき
	if (Fdead == true)
	{
		hero->SetVX(0);
		hero->SetVY(0);
		deadtime++;
		//主人公を中間ポイントに戻す
		if (deadtime == 79)
		{
			hero->SetX(hero->GetWX());
			hero->SetY(hero->GetWY());

			scroll->SetScrooll(-(hero->GetX() - (400)));
			if (hero->GetY() < 80) {
				scroll->SetYScrooll(-(hero->GetY() - (80)));
			}
			else if (hero->GetY() > 500) {
				scroll->SetYScrooll(-(hero->GetY() - (500)));
			}

		}
		//主人公のミス判定をリセット
		if (deadtime == 80)
		{
			deadtime = 0;
			Fdead = false;
			hero->WDflag(false);
			hero->Dflag(false);
		}

	}

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

	hit->SetPos(m_x + m_scroll, m_y + l_scroll + 48);
}
//ドロー
void CObjMBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

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