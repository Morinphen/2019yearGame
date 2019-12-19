//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"main.h"
#include"GameHead.h"
#include"ObjTitle.h"

//使用するネームスぺース
using namespace GameL;

//ゲームパッド用
XINPUT_STATE mc_state;

//イニシャライズ
void CObjMapchange::Init()
{
	m_key_flag = false;
	time = 0;
	mtime = 0;
}

//アクション
void CObjMapchange::Action()
{
	time +=1;
	mtime += 1;
	//ゲームパッド用
	DWORD dwResult = XInputGetState(0, &mc_state);

	//エンターキーを押してシーン:タイトルに移行する
	if (Input::GetVKey(VK_RETURN) == true || mc_state.Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(true));
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjMapchange::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c1[4] = { 1.0f,1.0f,1.0f,1.0f*(mtime/150) };
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

    //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 00.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 723.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 900.0f;
	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

	RECT_F srcj; //描画元切り取り位置
	RECT_F dstj; //描画先表示位置

	//切り取り位置の設定
	srcj.m_top = 0.0f;
	srcj.m_left = 00.0f;
	srcj.m_right = 800.0f;
	srcj.m_bottom = 794.0f;
	//表示位置の設定
	dstj.m_top = 100.0f;
	dstj.m_bottom = 800.0f;
	if (time > 200)
	{
		dstj.m_left = 200.0f;
		dstj.m_right = 1000.0f;
	}
	else if (time % 6 == 0|| time % 6 == 1)
	{
		dstj.m_left = 190.0f;
		dstj.m_right = 990.0f;
	}
	else if (time % 6 == 2||time % 6 == 3)
	{
		dstj.m_left = 200.0f;
		dstj.m_right = 1000.0f;
	}
	else if (time % 6 == 4||time % 6 == 5)
	{
		dstj.m_left = 210.0f;
		dstj.m_right = 1010.0f;
	}
	//描画
	Draw::Draw(1, &srcj, &dstj, c, 0.0f);
	RECT_F srcm; //描画元切り取り位置
	RECT_F dstm; //描画先表示位置

	//切り取り位置の設定
	srcm.m_top = 0.0f;
	srcm.m_left = 00.0f;
	srcm.m_right = 1024.0f;
	srcm.m_bottom = 303.0f;

	//表示位置の設定
	dstm.m_top = 700.0f;
	dstm.m_left = 0.0f;
	dstm.m_right = 1200.0f;
	dstm.m_bottom = 900.0f;
	//描画
	Draw::Draw(2, &srcm, &dstm, c1, 0.0f);
}