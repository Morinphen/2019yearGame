//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"HonoBlock.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjUguBlock::CObjUguBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjUguBlock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	uguisu = false;

	m_ani_time = 0;
	m_ani_frame = 0;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_UGUBLOCK, 1);
	HitBox_ON = true;
}
//アクション
void CObjUguBlock::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//ヒットボックス生成
		if (HitBox_ON == false)
		{
			HitBox_ON = true;
			Hits::SetHitBox(this, m_x, m_y, 62, 62, ELEMENT_BLACK, OBJ_UGUBLOCK, 1);
		}

		//主人公の位置を取得
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float hx = hero->GetX();
		float hy = hero->GetY();

		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		//要素番号を安俵に変更
		float x = m_x;
		float y = m_y;

		//主人公とブロックの当たり判定
		if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + (-l_scroll) + 64.0f > y) && (hy + (-l_scroll) < y + 64.0f))
		{
			//上下左右判定

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
			if (len < 88.0f) {
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
					uguisu = true;
					hero->Dflag(true);
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
		}

		CHitBox* hit = Hits::GetHitBox(this);

		if (uguisu == true)
		{

			Audio::Start(18);
			hero->SetVX(0);
			hero->SetVY(0);
			hero->SetX(hero->GetWX());
			hero->SetY(hero->GetWY());

			if (hero->GetX() < 500) {
				scroll->SetScrooll(-(hero->GetX() - (500)));
			}
			else if (hero->GetX() > 600) {
				scroll->SetScrooll(-(hero->GetX() - (600)));
			}

			if (hero->GetY() < 80) {
				scroll->SetYScrooll(-(hero->GetY() - (80)));
			}
			else if (hero->GetY() > 500) {
				scroll->SetYScrooll(-(hero->GetY() - (500)));
			}

			scroll->Resporn_check(m_x, m_y);

			hero->SetRE(1);
			hero->WDflag(false);
			hero->Dflag(false);
			uguisu = false;
			m_ani_frame = 0;
			
		}

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
			uguisu = false;
			m_ani_time = 0;
			m_ani_frame = 0;
		}
	}
}

//ドロー
void CObjUguBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//ブロック表示
		src.m_top = 0.5f;
		src.m_left = 64.0f * 4;
		src.m_right = 64.0f * 5;
		src.m_bottom = 64.0f;

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(24, &src, &dst, c, 0.0f);
	}
}