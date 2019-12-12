//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjTitle.h"

//使用するネームスぺース
using namespace GameL;

//イニシャライズ
void CObjRetry::Init()
{
	m_key_flag = false;
	m_posture = true;
}

//アクション
void CObjRetry::Action()
{
	if (Input::GetVKey(VK_UP) == true)
	{
		m_posture = true;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_posture = false;
	}
	//エンターキーを押してシーン:ゲームオーバーかメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			if (m_posture == true)
			{
				Scene::SetScene(new CSceneGameOver());
			}
			else if (m_posture == false)
			{
				Scene::SetScene(new CSceneMain());
			}
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjRetry::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置



	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 715.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 900.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

	RECT_F srcs; //描画元切り取り位置
	RECT_F dsts; //描画先表示位置

	//切り取り位置の設定
	srcs.m_top = 0.0f;
	srcs.m_left = 0.0f;
	srcs.m_right = 512.0f;
	srcs.m_bottom = 512.0f;

	if (m_posture == true)
	{
		//表示位置の設定
		dsts.m_top = 250.0f;
		dsts.m_left = 350.0f;
		dsts.m_right =414.0f;
		dsts.m_bottom =314.0f;
	}
	else if (m_posture == false)
	{
		//表示位置の設定
		dsts.m_top = 560.0f;
		dsts.m_left = 350.0f;
		dsts.m_right = 414.0f;
		dsts.m_bottom =624.0f;
	}
	//描画
	Draw::Draw(1, &srcs, &dsts, c, 0.0f);
}