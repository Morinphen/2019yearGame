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

CObjHonoBlock::CObjHonoBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjHonoBlock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;

	m_vx = 0;
	m_vy = 0;
	enzyou = false;

	m_ani_time = 0;
	m_ani_frame = 0;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_HONOBLOCK, 1);
	HitBox_ON = true;

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
}
//アクション
void CObjHonoBlock::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//ヒットボックス生成
		if (HitBox_ON == false)
		{
			HitBox_ON = true;
			Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_HONOBLOCK, 1);
		}

		//ブロックとの当たり判定
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		pb->BBlockHit(&m_x, &m_y,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy
		);

		pb->Setmap(m_y, m_x);

		//主人公の位置を取得
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float hx = hero->GetX();
		float hy = hero->GetY();

		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		//pb->Setmap(m_x, m_y);

		//要素番号を安俵に変更
		float x = m_x;
		float y = m_y;

		CHitBox* hit = Hits::GetHitBox(this);

		//火遁を受けると炎上アニメーションを発生
		if (enzyou == true)
		{
			m_ani_time++;
			if (m_ani_time == 6) {
				Audio::Start(5);
				m_ani_time = 0;
				m_ani_frame++;
			}
		}

		if (hit->CheckObjNameHit(OBJ_HINOTAMA) != nullptr)
		{
			enzyou = true;
		}

		//一定の時間がたつと消滅
		if (m_ani_frame == 6)
		{
			CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
			pb->Deletemap(m_x, m_y);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		hit->SetPos(m_x + m_scroll, m_y + l_scroll);

		//重力
		if (m_vy < 10)
			m_vy += 9.8f / 16.0f;

		m_x += m_vx;

		m_y += m_vy;
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

}
//ドロー
void CObjHonoBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	// 表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//ブロック表示
		src.m_top = 0.0f + ((m_ani_frame % 4)*64.0f);
		src.m_left = 64.0f * 4;
		src.m_right = 64.0f * 5;
		src.m_bottom = 64.0f + ((m_ani_frame % 4)*64.0f);

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(23, &src, &dst, c, 0.0f);
		if (enzyou == true)
			Draw::Draw(13, &src, &dst, c, 0.0f);
	}
}