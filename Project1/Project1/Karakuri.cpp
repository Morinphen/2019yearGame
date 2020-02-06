//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"
#include"main.h"

//使用するネームスペース
using namespace GameL;

//ゲームパッド用
XINPUT_STATE k_state;

CObjKarakuri::CObjKarakuri(int x, int y,int n)
{
	m_x = x;
	m_y = y;
	num = n;
}

//イニシャライズ
void CObjKarakuri::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;

	on_off = false;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK,OBJ_KARAKURI, 1);
	HitBox_ON = true;
}

//アクション
void CObjKarakuri::Action()
{
	//ゲームパッド用
	DWORD dwResult = XInputGetState(0, &k_state);

	//メニュー用の情報取得
	CObjMany* mn = (CObjMany*)Objs::GetObj(OBJ_MANY);
	bool m_stop = mn->GetOpen();

	if (m_stop == false) {
		////表示画面内の時
		CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
		if (scroll->Inscrooll_check(m_x, m_y) == true)
		{
			//ヒットボックス生成
			if (HitBox_ON == false)
			{
				HitBox_ON = true;
				Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, OBJ_KARAKURI, 1);
			}

			//レバー作動
			CHitBox* hit = Hits::GetHitBox(this);
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr&&Input::GetVKey(VK_UP) == true && on_off == false ||
				hit->CheckObjNameHit(OBJ_HERO) != nullptr&&k_state.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE&&on_off == false)
			{
				Audio::Start(6);
				on_off = true;
			}

			m_scroll = scroll->GetScroll();
			l_scroll = scroll->GetYScroll();

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
void CObjKarakuri::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	// 表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//レバーの向きを決める
		if (num == 61||num==62)
		{
			if (on_off == false)
			{
				//ブロック表示
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 63.0f;
				src.m_bottom = 64.0f;

			}
			else
			{
				//ブロック表示
				src.m_top = 64.0f;
				src.m_left = 0.0f;
				src.m_right = 63.0f;
				src.m_bottom = 0.0f;
			}
		}
		else
		{
			if (on_off == false)
			{
				//ブロック表示
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = -1.0f;
				src.m_bottom = 64.0f;

			}
			else
			{
				//ブロック表示
				src.m_top = 64.0f;
				src.m_left = 64.0f;
				src.m_right = -1.0f;
				src.m_bottom = 0.0f;
			}
		}

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(16, &src, &dst, c, 0.0f);
	}
}