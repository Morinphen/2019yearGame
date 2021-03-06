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
	change = false;
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

	//描画カラー情報
	float c3[4] = { 1.0f,0.0f,0.0f,1.0f };

	RECT_F srcm_ba; //描画元切り取り位置
	RECT_F dstm_ba; //描画先表示位置
	srcm_ba.m_top = 0.0f;
	srcm_ba.m_left = 50.0f;
	srcm_ba.m_right = 448.0f;
	srcm_ba.m_bottom = 449.0f;

	//表示位置の設定
	dstm_ba.m_top = 600.0f;
	dstm_ba.m_left = 750.0f;
	dstm_ba.m_right = 1200.0f;
	dstm_ba.m_bottom = 900.0f;
	//描画
	Draw::Draw(42, &srcm_ba, &dstm_ba, c, 0.0f);

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
	/*srcz.m_top = 2.0f;
	srcz.m_left = 130.0f + 64 * (5 - re);
	srcz.m_right = 184.0f + 64 * (5 - re);
	srcz.m_bottom = 64.0f;*/
	srcz.m_top = 30.0f;
	srcz.m_left = 35.0f+90*(re-1);
	srcz.m_right = 90.0f + 90 * (re-1);
	srcz.m_bottom = 70.0f;
	//表示位置の設定
	dstz.m_top = 20.0f;
	dstz.m_left = 278.0f;
	dstz.m_right = 360.0f;
	dstz.m_bottom = 70.0f;
	//描画
	Draw::Draw(40, &srcz, &dstz, c, 0.0f);
	RECT_F dstt; //描画先表示位置

	//表示位置の設定
	dstt.m_top = 780.0f;
	dstt.m_left = 750.0f;
	dstt.m_right = 850.0f;
	dstt.m_bottom = 900.0f;
	//描画
	Draw::Draw(32, &srcb, &dstt, c, 0.0f);
	if (hero->GetCF() == true)
	{
		RECT_F srcg; //描画元切り取り位置
		RECT_F dstg; //描画先表示位置
		srcg.m_top = 0.0f;
		srcg.m_left = 0.0f;
		srcg.m_right = 512.0f;
		srcg.m_bottom = 512.0f;

		//表示位置の設定
		dstg.m_top = 800.0f;
		dstg.m_left = 760.0f;
		dstg.m_right = 840.0f;
		dstg.m_bottom = 880.0f;

		//描画
		Draw::Draw(31, &srcg, &dstg, c, 0.0f);
	}
	//手裏剣
	RECT_F srcm_btn; //描画元切り取り位置
	RECT_F dstm_btn; //描画先表示位置
	srcm_btn.m_top = 0.0f;
	srcm_btn.m_left = 0.0f;
	srcm_btn.m_right = 448.0f;
	srcm_btn.m_bottom = 449.0f;

	//表示位置の設定
	dstm_btn.m_top = 600.0f;
	dstm_btn.m_left = 850.0f;
	dstm_btn.m_right = 1200.0f;
	dstm_btn.m_bottom = 900.0f;
	//描画
	Draw::Draw(42, &srcm_btn, &dstm_btn, c, 0.0f);
    //忍具モードボタン
	if (hero->GetChange() == false)
	{
		//手裏剣
		RECT_F srcm_bta; //描画元切り取り位置
		RECT_F dstm_bta; //描画先表示位置
		srcm_bta.m_top = 125.0f;
		srcm_bta.m_left = 240.0f;
		srcm_bta.m_right = 362.0f;
		srcm_bta.m_bottom = 245.0f;

		//表示位置の設定
		dstm_bta.m_top = 700.0f;
		dstm_bta.m_left = 1078.0f;
		dstm_bta.m_right = 1200.0f;
		dstm_bta.m_bottom = 820.0f;
		if (hero->GetPushb() == 1)
		{
			//描画
			Draw::Draw(36, &srcm_bta, &dstm_bta, c3, 0.0f);
		}
		else
		{
			//描画
			Draw::Draw(36, &srcm_bta, &dstm_bta, c, 0.0f);
		}
		//煙玉
		RECT_F srcm_btx; //描画元切り取り位置
		RECT_F dstm_btx; //描画先表示位置
		srcm_btx.m_top = 125.0f;
		srcm_btx.m_left = 0.0f;
		srcm_btx.m_right = 120.0f;
		srcm_btx.m_bottom = 245.0f;

		//表示位置の設定
		dstm_btx.m_top = 700.0f;
		dstm_btx.m_left = 850.0f;
		dstm_btx.m_right = 970.0f;
		dstm_btx.m_bottom = 820.0f;
		if (hero->GetPushb() == 3)
		{
			//描画
			Draw::Draw(36, &srcm_btx, &dstm_btx, c3, 0.0f);
		}
		else
		{
			//描画
			Draw::Draw(36, &srcm_btx, &dstm_btx, c, 0.0f);
		}
		//鉤縄
		RECT_F srcm_bty; //描画元切り取り位置
		RECT_F dstm_bty; //描画先表示位置
		srcm_bty.m_top = 0.0f;
		srcm_bty.m_left = 130.0f;
		srcm_bty.m_right = 245.0f;
		srcm_bty.m_bottom = 115.0f;

		//表示位置の設定
		dstm_bty.m_top = 600.0f;
		dstm_bty.m_left = 968.0f;
		dstm_bty.m_right = 1083.0f;
		dstm_bty.m_bottom = 735.0f;
		if (hero->GetPushb() == 4)
		{
			//描画
			Draw::Draw(36, &srcm_bty, &dstm_bty, c3, 0.0f);
		}
		else
		{
			//描画
			Draw::Draw(36, &srcm_bty, &dstm_bty, c, 0.0f);
		}
	}
	else
	{
		//火遁
		RECT_F srcm_bta; //描画元切り取り位置
		RECT_F dstm_bta; //描画先表示位置
		srcm_bta.m_top = 125.0f;
		srcm_bta.m_left = 240.0f;
		srcm_bta.m_right = 362.0f;
		srcm_bta.m_bottom = 245.0f;

		//表示位置の設定
		dstm_bta.m_top = 700.0f;
		dstm_bta.m_left = 1078.0f;
		dstm_bta.m_right = 1200.0f;
		dstm_bta.m_bottom = 820.0f;
		if (hero->GetPushb() == 1)
		{
			//描画
			Draw::Draw(37, &srcm_bta, &dstm_bta, c3, 0.0f);
		}
		else
		{
			//描画
			Draw::Draw(37, &srcm_bta, &dstm_bta, c, 0.0f);
		}
		//土遁
		RECT_F srcm_btx; //描画元切り取り位置
		RECT_F dstm_btx; //描画先表示位置
		srcm_btx.m_top = 125.0f;
		srcm_btx.m_left = 0.0f;
		srcm_btx.m_right = 120.0f;
		srcm_btx.m_bottom = 245.0f;

		//表示位置の設定
		dstm_btx.m_top = 700.0f;
		dstm_btx.m_left = 850.0f;
		dstm_btx.m_right = 970.0f;
		dstm_btx.m_bottom = 820.0f;
		if (hero->GetPushb() == 3)
		{
			//描画
			Draw::Draw(37, &srcm_btx, &dstm_btx, c3, 0.0f);
		}
		else
		{
			//描画
			Draw::Draw(37, &srcm_btx, &dstm_btx, c, 0.0f);
		}
		//虫獣遁
		RECT_F srcm_bty; //描画元切り取り位置
		RECT_F dstm_bty; //描画先表示位置
		srcm_bty.m_top = 0.0f;
		srcm_bty.m_left = 130.0f;
		srcm_bty.m_right = 245.0f;
		srcm_bty.m_bottom = 115.0f;

		//表示位置の設定
		dstm_bty.m_top = 600.0f;
		dstm_bty.m_left = 968.0f;
		dstm_bty.m_right = 1083.0f;
		dstm_bty.m_bottom = 735.0f;
		if (hero->GetPushb() == 4)
		{
			//描画
			Draw::Draw(37, &srcm_bty, &dstm_bty, c3, 0.0f);
		}
		else
		{
			//描画
			Draw::Draw(37, &srcm_bty, &dstm_bty, c, 0.0f);
		}
	}
	//ジャンプ
	RECT_F srcm_btb; //描画元切り取り位置
	RECT_F dstm_btb; //描画先表示位置
	srcm_btb.m_top = 240.0f;
	srcm_btb.m_left = 130.0f;
	srcm_btb.m_right = 245.0f;
	srcm_btb.m_bottom = 362.0f;

	//表示位置の設定
	dstm_btb.m_top = 778.0f;
	dstm_btb.m_left = 968.0f;
	dstm_btb.m_right = 1083.0f;
	dstm_btb.m_bottom = 900.0f;
	if (hero->GetPushb() == 2)
	{
		//描画
		Draw::Draw(36, &srcm_btb, &dstm_btb, c3, 0.0f);
	}
	else
	{
		//描画
		Draw::Draw(36, &srcm_btb, &dstm_btb, c, 0.0f);
	}
	

	//ジャンプ
RECT_F srcm_btm; //描画元切り取り位置
RECT_F dstm_btm; //描画先表示位置
srcm_btm.m_top = 0.0f;
srcm_btm.m_left = 0.0f;
srcm_btm.m_right = 99.0f;
srcm_btm.m_bottom = 178.0f;

//表示位置の設定
dstm_btm.m_top = 600.0f;
dstm_btm.m_left = 750.0f;
dstm_btm.m_right = 850.0f;
dstm_btm.m_bottom = 750.0f;
if (hero->GetPushb() == 5)
{
	//描画
	Draw::Draw(38, &srcm_btm, &dstm_btm, c3, 0.0f);
}
else
{
	//描画
	Draw::Draw(38, &srcm_btm, &dstm_btm, c, 0.0f);
}
if (change == false)
{
	RECT_F srcmn; //描画元切り取り位置
	RECT_F dstmn; //描画先表示位置
	srcmn.m_top = 0.0f;
	srcmn.m_left = 0.0f;
	srcmn.m_right = 512.0f;
	srcmn.m_bottom = 365.0f;

	//表示位置の設定
	dstmn.m_top = 600.0f;
	dstmn.m_left = 0.0f;
	dstmn.m_right = 750.0f;
	dstmn.m_bottom = 900.0f;

	//描画
	Draw::Draw(39, &srcmn, &dstmn, c, 0.0f);
}
else
{
	RECT_F srcmn; //描画元切り取り位置
	RECT_F dstmn; //描画先表示位置
	srcmn.m_top = 0.0f;
	srcmn.m_left = 0.0f;
	srcmn.m_right = 512.0f;
	srcmn.m_bottom = 365.0f;

	//表示位置の設定
	dstmn.m_top = 600.0f;
	dstmn.m_left = 0.0f;
	dstmn.m_right = 750.0f;
	dstmn.m_bottom = 900.0f;

	//描画
	Draw::Draw(45, &srcmn, &dstmn, c, 0.0f);
}
CObjScroll* sc = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
RECT_F srcm_n; //描画元切り取り位置
RECT_F dstm_n; //描画先表示位置
srcm_n.m_top = 0.0f;
srcm_n.m_left = 0.0f;
srcm_n.m_right = 200.0f;
srcm_n.m_bottom = 200.0f;
ys = sc->GetYScroll()+2320;
//表示位置の設定
dstm_n.m_top = 875.0f -(ys/9.8);
dstm_n.m_left = 55.0f-(sc->GetScroll()/8.6)-(sc->GetMNScroll()/8.6);
dstm_n.m_right = 75.0f - (sc->GetScroll()/8.6) - (sc->GetMNScroll()/8.6);
dstm_n.m_bottom = 895.0f - (ys / 9.8);
if (sc->GetYScroll() > -250)
{
	fs = 4;
}
else if (sc->GetYScroll() > -750)
{
	fs = 3;
}
else if (sc->GetYScroll() > -1260)
{
	fs = 2;
}
else if (sc->GetYScroll() > -1760)
{
	fs = 1;
}
else
{
	fs = 0;
}
//描画
Draw::Draw(18, &srcm_n, &dstm_n, c, 0.0f);
RECT_F dstf_m; //描画先表示位置
//表示位置の設定
dstf_m.m_top = 0.0f;
dstf_m.m_left = 1100.0f;
dstf_m.m_right = 1200.0f;
dstf_m.m_bottom = 120.0f;
//描画
Draw::Draw(32, &srcb, &dstf_m, c, 0.0f);
RECT_F srcf_n; //描画元切り取り位置
RECT_F dstf_n; //描画先表示位置
srcf_n.m_top = 30.0f;
srcf_n.m_left = 35.0f+(fs*90);
srcf_n.m_right = 90.0f + (fs *90);
srcf_n.m_bottom = 140.0f;
//表示位置の設定
dstf_n.m_top =10.0f;
dstf_n.m_left = 1110;
dstf_n.m_right = 1190;
dstf_n.m_bottom = 100.0f;
//描画
Draw::Draw(40, &srcf_n, &dstf_n, c, 0.0f);
}