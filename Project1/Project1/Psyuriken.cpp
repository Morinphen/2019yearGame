//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"Psyuriken.h"

//使用するネームスぺース
using namespace GameL;

//イニシャライズ
void CObjPsyuriken::Init()
{
	ps = 0;
}

//アクション
void CObjPsyuriken::Action()
{

}

//ドロー
void CObjPsyuriken::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F srcf; //描画元切り取り位置
	RECT_F dstf; //描画先表示位置

				 //切り取り位置の設定
	srcf.m_top = 0.0f;
	srcf.m_left = 0.0f;
	srcf.m_right = 512.0f;
	srcf.m_bottom = 150.0f;

	//表示位置の設定
	dstf.m_top = 0.0f;
	dstf.m_left = 100.0f;
	dstf.m_right = 380.0f;
	dstf.m_bottom = 100.0f;
	//描画
	Draw::Draw(19, &srcf, &dstf, c, 0.0f);

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 20.0f;
	dst.m_left = 150.0f;
	dst.m_right = 278.0f;
	dst.m_bottom = 84.0f;
	//描画
	Draw::Draw(17, &src, &dst, c, 0.0f);
	//主人公の情報を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	RECT_F srcs; //描画元切り取り位置
	RECT_F dsts; //描画先表示位置
	ps=hero->GetPS();
	//切り取り位置の設定
	if (ps > 3)
	{
		srcs.m_top = 2.0f;
		srcs.m_left = 130.0f + 64*(5-ps);
		srcs.m_right = 191.0f + 64 * (5-ps);
		srcs.m_bottom = 64.0f;
	}
	else
	{
		srcs.m_top = 2.0f;
		srcs.m_left = 130.0f + 64 * (5-ps);
		srcs.m_right = 184.0f + 64 * (5-ps);
		srcs.m_bottom = 64.0f;
	}
	//表示位置の設定
	dsts.m_top = 20.0f;
	dsts.m_left = 278.0f;
	dsts.m_right = 342.0f;
	dsts.m_bottom = 84.0f;
	//描画
	Draw::Draw(17, &srcs, &dsts, c, 0.0f);

	RECT_F srcm; //描画元切り取り位置
	RECT_F dstm; //描画先表示位置
	mode = hero->GetMode();
	if (mode == false)
	{
		srcm.m_top = 0.0f;
		srcm.m_left = 0.0f;
		srcm.m_right = 256.0f;
		srcm.m_bottom = 256.0f;
	}
	else
	{
		srcm.m_top = 0.0f;
		srcm.m_left = 256.0f;
		srcm.m_right = 512.0f;
		srcm.m_bottom = 256.0f;
	}

	//表示位置の設定
	dstm.m_top = 0.0f;
	dstm.m_left = 0.0f;
	dstm.m_right = 100.0f;
	dstm.m_bottom = 120.0f;
	//描画
	Draw::Draw(18, &srcm, &dstm, c, 0.0f);
}