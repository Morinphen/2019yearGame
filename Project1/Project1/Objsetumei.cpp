//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"Objsetumei.h"

//使用するネームスぺース
using namespace GameL;

//イニシャライズ
void CObjsetumei::Init()
{
	m_key_flag = false;
}

//アクション
void CObjsetumei::Action()
{
	//エンターキーを押してシーン:タイトルに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Audio::Start(0);
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjsetumei::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

				//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 00.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 682.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 600.0f;
	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}