//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Many.h"
#include"GameL\HitBoxManager.h"
#include"main.h"

//使用するネームスペース
using namespace GameL;

//ゲームパッド用
XINPUT_STATE m_state;

//イニシャライズ
void CObjMany::Init()
{
	m_key_flag = false;
	open = false;
	H_B = false;
	Giveup = false;
}
//アクション
void CObjMany::Action()
{
	//ゲームパッド用
	DWORD dwResult = XInputGetState(0, &m_state);

	if (open == true) {
		if (Input::GetVKey(VK_UP) == true || m_state.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			H_B = false;
		}
		else if (Input::GetVKey(VK_DOWN) == true || m_state.Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			H_B = true;
		}
	}

	//エンターキーを押してシーン:ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true || m_state.Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		if (m_key_flag == true && open == false)
		{
			open = true;
		}

		else
		{
			if (H_B == false && Giveup == false || H_B == true && Giveup == true) {
				if (m_key_flag == true) {
					open = false;
					H_B = false;
					Giveup = false;
				}
			}

			else {
				Giveup = true;
				if (m_key_flag == true && H_B == false)
				{
					Scene::SetScene(new CSceneTitle());
				}
			}
		}
		m_key_flag = false;
	}

	else
	{
		m_key_flag = true;
	}
}
//ドロー
void CObjMany::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;


	if (open == true) {
		
		//背景表示
		//看板
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;
		dst.m_top = 100.0f;
		dst.m_left = 250.0f;
		dst.m_right = 950.0f;
		dst.m_bottom = 720.0f;
		Draw::Draw(69, &src, &dst, c, 0.0f);

		//めにゅーor本当に
		if (Giveup == false) {
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 170.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 234.0f;
		}
		else
		{
			src.m_top = 192.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 256.0f;
			dst.m_top = 170.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 234.0f;
		}
		Draw::Draw(14, &src, &dst, c, 0.0f);

		//すたーとで決定
		src.m_top = 384.0f;
		src.m_left = 0.0f;
		src.m_right = 192.0f;
		src.m_bottom = 468.0f;
		dst.m_top = 220.0f;
		dst.m_left = 420.0f;
		dst.m_right = 792.0f;
		dst.m_bottom = 300.0f;
		Draw::Draw(14, &src, &dst, c, 0.0f);

		//任務続行orはい
		if (Giveup == false) {
			src.m_top = 128.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 300.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 364.0f;
		}
		else {
			src.m_top = 256.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 320.0f;
			dst.m_top = 270.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 394.0f;
		}
		if (H_B == true)
			c[3] = 0.5f;
		else
			c[3] = 1.0f;
		Draw::Draw(14, &src, &dst, c, 0.0f);

		//たいとるにorいいえ
		if (Giveup == false) {
			src.m_top = 64.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 400.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 464.0f;
		}
		else {
			src.m_top = 320.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 384.0f;
			dst.m_top = 370.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 494.0f;
		}
		if (H_B == false)
			c[3] = 0.5f;
		else
			c[3] = 1.0f;
		Draw::Draw(14, &src, &dst, c, 0.0f);

		//カーソル出現
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 32.0f;
		src.m_bottom = 32.0f;

		if (H_B == false)
		{
			//表示位置の設定
			dst.m_top = 300.0f;
			dst.m_left = 350.0f;
			dst.m_right = 414.0f;
			dst.m_bottom = 364.0f;
		}
		else if (H_B == true)
		{
			//表示位置の設定
			dst.m_top = 400.0f;
			dst.m_left = 350.0f;
			dst.m_right = 414.0f;
			dst.m_bottom = 464.0f;
		}

		c[3] = 1.0f;
		Draw::Draw(3, &src, &dst, c, 0.0f);

	}
}