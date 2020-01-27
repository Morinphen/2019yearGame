//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"kanban.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjkanban::CObjkanban(int x, int y, int t)
{
	m_x = x;
	m_y = y;
	type = t;
}

//イニシャライズ
void CObjkanban::Init()
{
	num = 0.0f;
	flashing = false;

	hit_hero = false;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_KANBAN, 1);
	HitBox_ON = true;
}

//アクション
void CObjkanban::Action()
{
	//表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	//メニュー用の情報取得
	CObjMany* mn = (CObjMany*)Objs::GetObj(OBJ_MANY);
	bool m_stop = mn->GetOpen();

	if (m_stop == false) {
		if (scroll->Inscrooll_check(m_x, m_y) == true)
		{
			//ヒットボックス生成
			if (HitBox_ON == false)
			{
				HitBox_ON = true;
				Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_KANBAN, 1);
			}

			CHitBox* hit = Hits::GetHitBox(this);
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
				hit_hero = true;
			else
				hit_hero = false;

			m_scroll = scroll->GetScroll();
			l_scroll = scroll->GetYScroll();

			num++;
			if (num / 60 == 1)
			{
				num = 0.0f;
				flashing = flashing ? false : true;
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
			}
		}
	}
}

//ドロー
void CObjkanban::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	// 表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//看板を拡大させる
		if(hit_hero==false)
		{
			//ブロック表示
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 512.0f;
			src.m_bottom = 512.0f;

			dst.m_top = m_y + l_scroll;
			dst.m_left = m_x + m_scroll;
			dst.m_right = dst.m_left + 64.0f;
			dst.m_bottom = dst.m_top + 64.0f;
			
			Draw::Draw(46, &src, &dst, c, 0.0f);
			
		}
		else
		{
			//ブロック表示
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 512.0f;
			src.m_bottom = 512.0f;

			dst.m_top = m_y - 64.0f * 6 + l_scroll;
			dst.m_left = m_x - 64.0f * 3.5 + m_scroll;
			dst.m_right = dst.m_left + 64.0f * 8;
			dst.m_bottom = dst.m_top + 64.0f * 8;

			//手裏剣看板
			if (type == 120)
			{
				if (flashing == false)
					Draw::Draw(47, &src, &dst, c, 0.0f);
				else
					Draw::Draw(48, &src, &dst, c, 0.0f);
			}
			//モードチェンジ
			else if(type == 121)
			{
				if (flashing == false)
					Draw::Draw(49, &src, &dst, c, 0.0f);
				else
					Draw::Draw(50, &src, &dst, c, 0.0f);
			}
			//走る
			else if (type == 122)
			{
				if (flashing == false)
					Draw::Draw(51, &src, &dst, c, 0.0f);
				else
					Draw::Draw(52, &src, &dst, c, 0.0f);
			}
			//木箱燃やす
			else if (type == 123)
			{
				if (flashing == false)
					Draw::Draw(53, &src, &dst, c, 0.0f);
				else
					Draw::Draw(54, &src, &dst, c, 0.0f);
			}
			//どんでん返し
			else if (type == 124)
			{
				if (flashing == false)
					Draw::Draw(55, &src, &dst, c, 0.0f);
				else
					Draw::Draw(56, &src, &dst, c, 0.0f);
			}
			//土遁
			else if (type == 125)
			{
				if (flashing == false)
					Draw::Draw(57, &src, &dst, c, 0.0f);
				else
					Draw::Draw(58, &src, &dst, c, 0.0f);
			}
			//ネズミ
			else if (type == 126)
			{
				if (flashing == false)
					Draw::Draw(59, &src, &dst, c, 0.0f);
				else
					Draw::Draw(60, &src, &dst, c, 0.0f);
			}
			//煙玉
			else if (type == 127)
			{
				if (flashing == false)
					Draw::Draw(61, &src, &dst, c, 0.0f);
				else
					Draw::Draw(62, &src, &dst, c, 0.0f);
			}
			//縄鉤
			else if (type == 128)
			{
				if (flashing == false)
					Draw::Draw(63, &src, &dst, c, 0.0f);
				else
					Draw::Draw(64, &src, &dst, c, 0.0f);
			}
			//レバー
			else if (type == 129)
			{
				if (flashing == false)
					Draw::Draw(65, &src, &dst, c, 0.0f);
				else
					Draw::Draw(66, &src, &dst, c, 0.0f);
			}
			//ジャンプ
			else if (type == 115)
			{
				if (flashing == false)
					Draw::Draw(67, &src, &dst, c, 0.0f);
				else
					Draw::Draw(68, &src, &dst, c, 0.0f);
			}
		}
		
		
	}
}