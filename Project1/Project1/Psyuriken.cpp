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
	re = 0;
	n_m = -1;
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

	//描画カラー情報
	float c2[4] = { 1.0f,1.0f,1.0f,0.8f };

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
	
	//主人公の情報を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	
	RECT_F srcb; //描画元切り取り位置
	RECT_F dstb; //描画先表示位置
	srcb.m_top = 0.0f;
	srcb.m_left = 0.0f;
	srcb.m_right = 512.0f;
	srcb.m_bottom = 512.0f;

	//表示位置の設定
	dstb.m_top = 0.0f;
	dstb.m_left = 0.0f;
	dstb.m_right = 100.0f;
	dstb.m_bottom = 120.0f;
	//描画
	Draw::Draw(32, &srcb, &dstb, c, 0.0f);

	RECT_F srcm_u; //描画元切り取り位置
	RECT_F dstm_u; //描画先表示位置
	srcm_u.m_top = 0.0f;
	srcm_u.m_left = 0.0f;
	srcm_u.m_right = 211.0f;
	srcm_u.m_bottom = 256.0f;

	//表示位置の設定
	dstm_u.m_top = 10.0f;
	dstm_u.m_left = 20.0f;
	dstm_u.m_right = 80.0f;
	dstm_u.m_bottom = 60.0f;
	//描画
	Draw::Draw(18, &srcm_u, &dstm_u, c, 0.0f);
	mode = hero->GetChange();
	RECT_F srcm; //描画元切り取り位置
	RECT_F dstm; //描画先表示位置

	if (mode == true)
	{
		srcm.m_top = 256.0f;
		srcm.m_left = 0.0f;
		srcm.m_right = 211.0f;
		srcm.m_bottom = 512.0f;
	}
	else
	{
		srcm.m_top = 256.0f;
		srcm.m_left = 211.0f;
		srcm.m_right = 422.0f;
		srcm.m_bottom = 512.0f;
	}

	//表示位置の設定
	dstm.m_top = 60.0f;
	dstm.m_left = 20.0f;
	dstm.m_right = 80.0f;
	dstm.m_bottom = 110.0f;
	//描画
	Draw::Draw(18, &srcm, &dstm, c, 0.0f);

	RECT_F srcd; //描画元切り取り位置
	RECT_F dstd; //描画先表示位置

	//切り取り位置の設定
	srcd.m_top = 0.0f;
	srcd.m_left = 0.0f;
	srcd.m_right = 128.0f;
	srcd.m_bottom = 64.0f;

	//表示位置の設定
	dstd.m_top = 20.0f;
	dstd.m_left = 150.0f;
	dstd.m_right = 278.0f;
	dstd.m_bottom = 84.0f;
	//描画
	Draw::Draw(21, &srcd, &dstd, c, 0.0f);

	RECT_F srcz; //描画元切り取り位置
	RECT_F dstz; //描画先表示位置
	re = hero->GetRE();
	//切り取り位置の設定
	if (re > 3)
	{
		srcz.m_top = 2.0f;
		srcz.m_left = 130.0f + 64 * (5 - re);
		srcz.m_right = 191.0f + 64 * (5 - re);
		srcz.m_bottom = 64.0f;
	}
	else
	{
		srcz.m_top = 2.0f;
		srcz.m_left = 130.0f + 64 * (5 - re);
		srcz.m_right = 184.0f + 64 * (5 - re);
		srcz.m_bottom = 64.0f;
	}
	//表示位置の設定
	dstz.m_top = 20.0f;
	dstz.m_left = 278.0f;
	dstz.m_right = 342.0f;
	dstz.m_bottom = 84.0f;
	//描画
	Draw::Draw(21, &srcz, &dstz, c, 0.0f);
	RECT_F dstt; //描画先表示位置

	//表示位置の設定
	dstt.m_top = 0.0f;
	dstt.m_left = 1100.0f;
	dstt.m_right = 1200.0f;
	dstt.m_bottom = 120.0f;
	//描画
	Draw::Draw(32, &srcb, &dstt, c2, 0.0f);
	if (hero->GetCF() == true)
	{
		RECT_F srcg; //描画元切り取り位置
		RECT_F dstg; //描画先表示位置
		srcg.m_top = 0.0f;
		srcg.m_left = 0.0f;
		srcg.m_right = 512.0f;
		srcg.m_bottom = 512.0f;

		//表示位置の設定
		dstg.m_top = 20.0f;
		dstg.m_left = 1110.0f;
		dstg.m_right = 1190.0f;
		dstg.m_bottom = 100.0f;

		//描画
		Draw::Draw(31, &srcg, &dstg, c, 0.0f);
	}
	RECT_F dstn_b; //描画先表示位置

	//表示位置の設定
	dstn_b.m_top = 0.0f;
	dstn_b.m_left = 750.0f;
	dstn_b.m_right = 900.0f;
	dstn_b.m_bottom = 120.0f;
	//描画
	Draw::Draw(32, &srcb, &dstn_b, c2, 0.0f);
	n_m = hero->GetN_M();
	if (n_m>=0)
	{
		RECT_F srcn_m; //描画元切り取り位置
		RECT_F dstn_m; //描画先表示位置
		if (n_m < 4)
		{
			srcn_m.m_top = 0.0f;
			srcn_m.m_left = 0.0f + (184.0f*n_m);;
			srcn_m.m_right =184.0+(184.0f*n_m);
			if (n_m == 1 || n_m == 3)
			{
				srcn_m.m_bottom = 350.0f;
			}
			else
			{
				srcn_m.m_bottom = 512.0f;
			}
		}
		else if (n_m < 8)
		{
			srcn_m.m_top = 512.0f;
			srcn_m.m_left = 0.0f + (184.0f*n_m);;
			srcn_m.m_right = 184.0 + (184.0f*n_m);
			if (n_m == 7)
			{
				srcn_m.m_bottom = 1024.0f;
			}
			else
			{
				srcn_m.m_bottom = 862.0f;
			}
		}
		//表示位置の設定
		dstn_m.m_top = 0.0f;
		dstn_m.m_left = 790.0f;
		dstn_m.m_right = 860.0f;
		dstn_m.m_bottom = 120.0f;
		//描画
		Draw::Draw(33, &srcn_m, &dstn_m, c, 0.0f);
	}
}