//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"main.h"

//使用するネームスぺース
using namespace GameL;

//ゲームパッド用
XINPUT_STATE t_state;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
}

//アクション
void CObjTitle::Action()
{
	//ゲームパッド用
	DWORD dwResult = XInputGetState(0, &t_state);

	//エンターキーを押してシーン:ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true|| t_state.Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		if (m_key_flag == true)
		{
			Audio::Start(1);
			Scene::SetScene(new CScenesetumei());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjTitle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 00.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 524.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom =900.0f;
	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
	
}