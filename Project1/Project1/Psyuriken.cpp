//g—p‚·‚ιƒwƒbƒ_[ƒtƒ@ƒCƒ‹
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"Psyuriken.h"

//g—p‚·‚ιƒl[ƒ€ƒX‚Ψ[ƒX
using namespace GameL;

//ƒCƒjƒVƒƒƒ‰ƒCƒY
void CObjPsyuriken::Init()
{
	ps = 0;
	re = 0;
	n_m = -1;
}

//ƒAƒNƒVƒ‡ƒ“
void CObjPsyuriken::Action()
{

}

//ƒhƒ[
void CObjPsyuriken::Draw()
{
	//•`‰ζƒJƒ‰[ξ•ρ
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//•`‰ζƒJƒ‰[ξ•ρ
	float c2[4] = { 1.0f,1.0f,1.0f,0.8f };

	//•`‰ζƒJƒ‰[ξ•ρ
	float c3[4] = { 1.0f,0.0f,0.0f,1.0f };

	RECT_F srcm_ba; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstm_ba; //•`‰ζζ•\¦Κ’u
	srcm_ba.m_top = 0.0f;
	srcm_ba.m_left = 50.0f;
	srcm_ba.m_right = 448.0f;
	srcm_ba.m_bottom = 449.0f;

	//•\¦Κ’u‚Μέ’θ
	dstm_ba.m_top = 600.0f;
	dstm_ba.m_left = 750.0f;
	dstm_ba.m_right = 1200.0f;
	dstm_ba.m_bottom = 900.0f;
	//•`‰ζ
	Draw::Draw(42, &srcm_ba, &dstm_ba, c, 0.0f);

	RECT_F srcf; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstf; //•`‰ζζ•\¦Κ’u

				 //Ψ‚θζ‚θΚ’u‚Μέ’θ
	srcf.m_top = 0.0f;
	srcf.m_left = 0.0f;
	srcf.m_right = 512.0f;
	srcf.m_bottom = 150.0f;

	//•\¦Κ’u‚Μέ’θ
	dstf.m_top = 0.0f;
	dstf.m_left = 100.0f;
	dstf.m_right = 380.0f;
	dstf.m_bottom = 100.0f;
	//•`‰ζ
	Draw::Draw(19, &srcf, &dstf, c, 0.0f);
	
	//εlφ‚Μξ•ρ‚πζ“Ύ
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	
	RECT_F srcb; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstb; //•`‰ζζ•\¦Κ’u
	srcb.m_top = 0.0f;
	srcb.m_left = 0.0f;
	srcb.m_right = 512.0f;
	srcb.m_bottom = 512.0f;

	//•\¦Κ’u‚Μέ’θ
	dstb.m_top = 0.0f;
	dstb.m_left = 0.0f;
	dstb.m_right = 100.0f;
	dstb.m_bottom = 120.0f;
	//•`‰ζ
	Draw::Draw(32, &srcb, &dstb, c, 0.0f);

	RECT_F srcm_u; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstm_u; //•`‰ζζ•\¦Κ’u
	srcm_u.m_top = 0.0f;
	srcm_u.m_left = 0.0f;
	srcm_u.m_right = 211.0f;
	srcm_u.m_bottom = 256.0f;

	//•\¦Κ’u‚Μέ’θ
	dstm_u.m_top = 10.0f;
	dstm_u.m_left = 20.0f;
	dstm_u.m_right = 80.0f;
	dstm_u.m_bottom = 60.0f;
	//•`‰ζ
	Draw::Draw(18, &srcm_u, &dstm_u, c, 0.0f);
	mode = hero->GetChange();
	RECT_F srcm; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstm; //•`‰ζζ•\¦Κ’u

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

	//•\¦Κ’u‚Μέ’θ
	dstm.m_top = 60.0f;
	dstm.m_left = 20.0f;
	dstm.m_right = 80.0f;
	dstm.m_bottom = 110.0f;
	//•`‰ζ
	Draw::Draw(18, &srcm, &dstm, c, 0.0f);

	RECT_F srcd; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstd; //•`‰ζζ•\¦Κ’u

	//Ψ‚θζ‚θΚ’u‚Μέ’θ
	srcd.m_top = 0.0f;
	srcd.m_left = 0.0f;
	srcd.m_right = 128.0f;
	srcd.m_bottom = 64.0f;

	//•\¦Κ’u‚Μέ’θ
	dstd.m_top = 20.0f;
	dstd.m_left = 150.0f;
	dstd.m_right = 278.0f;
	dstd.m_bottom = 84.0f;
	//•`‰ζ
	Draw::Draw(21, &srcd, &dstd, c, 0.0f);

	RECT_F srcz; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstz; //•`‰ζζ•\¦Κ’u
	re = hero->GetRE();
	//Ψ‚θζ‚θΚ’u‚Μέ’θ
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
	//•\¦Κ’u‚Μέ’θ
	dstz.m_top = 20.0f;
	dstz.m_left = 278.0f;
	dstz.m_right = 342.0f;
	dstz.m_bottom = 84.0f;
	//•`‰ζ
	Draw::Draw(21, &srcz, &dstz, c, 0.0f);
	RECT_F dstt; //•`‰ζζ•\¦Κ’u

	//•\¦Κ’u‚Μέ’θ
	dstt.m_top = 780.0f;
	dstt.m_left = 1100.0f;
	dstt.m_right = 1200.0f;
	dstt.m_bottom = 900.0f;
	//•`‰ζ
	Draw::Draw(32, &srcb, &dstt, c, 0.0f);
	if (hero->GetCF() == true)
	{
		RECT_F srcg; //•`‰ζ³Ψ‚θζ‚θΚ’u
		RECT_F dstg; //•`‰ζζ•\¦Κ’u
		srcg.m_top = 0.0f;
		srcg.m_left = 0.0f;
		srcg.m_right = 512.0f;
		srcg.m_bottom = 512.0f;

		//•\¦Κ’u‚Μέ’θ
		dstg.m_top = 800.0f;
		dstg.m_left = 1110.0f;
		dstg.m_right = 1190.0f;
		dstg.m_bottom = 880.0f;

		//•`‰ζ
		Draw::Draw(31, &srcg, &dstg, c, 0.0f);
	}
	//θ— •
	RECT_F srcm_btn; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstm_btn; //•`‰ζζ•\¦Κ’u
	srcm_btn.m_top = 0.0f;
	srcm_btn.m_left = 0.0f;
	srcm_btn.m_right = 448.0f;
	srcm_btn.m_bottom = 449.0f;

	//•\¦Κ’u‚Μέ’θ
	dstm_btn.m_top = 600.0f;
	dstm_btn.m_left = 750.0f;
	dstm_btn.m_right = 1100.0f;
	dstm_btn.m_bottom = 900.0f;
	//•`‰ζ
	Draw::Draw(42, &srcm_btn, &dstm_btn, c, 0.0f);
    //”E‹οƒ‚[ƒhƒ{ƒ^ƒ“
	if (hero->GetChange() == false)
	{
		//θ— •
		RECT_F srcm_bta; //•`‰ζ³Ψ‚θζ‚θΚ’u
		RECT_F dstm_bta; //•`‰ζζ•\¦Κ’u
		srcm_bta.m_top = 125.0f;
		srcm_bta.m_left = 240.0f;
		srcm_bta.m_right = 362.0f;
		srcm_bta.m_bottom = 245.0f;

		//•\¦Κ’u‚Μέ’θ
		dstm_bta.m_top = 700.0f;
		dstm_bta.m_left = 978.0f;
		dstm_bta.m_right = 1100.0f;
		dstm_bta.m_bottom = 820.0f;
		if (hero->GetPushb() == 1)
		{
			//•`‰ζ
			Draw::Draw(36, &srcm_bta, &dstm_bta, c3, 0.0f);
		}
		else
		{
			//•`‰ζ
			Draw::Draw(36, &srcm_bta, &dstm_bta, c, 0.0f);
		}
		//‰‹Κ
		RECT_F srcm_btx; //•`‰ζ³Ψ‚θζ‚θΚ’u
		RECT_F dstm_btx; //•`‰ζζ•\¦Κ’u
		srcm_btx.m_top = 125.0f;
		srcm_btx.m_left = 0.0f;
		srcm_btx.m_right = 120.0f;
		srcm_btx.m_bottom = 245.0f;

		//•\¦Κ’u‚Μέ’θ
		dstm_btx.m_top = 700.0f;
		dstm_btx.m_left = 750.0f;
		dstm_btx.m_right = 870.0f;
		dstm_btx.m_bottom = 820.0f;
		if (hero->GetPushb() == 3)
		{
			//•`‰ζ
			Draw::Draw(36, &srcm_btx, &dstm_btx, c3, 0.0f);
		}
		else
		{
			//•`‰ζ
			Draw::Draw(36, &srcm_btx, &dstm_btx, c, 0.0f);
		}
		//ηκ“κ
		RECT_F srcm_bty; //•`‰ζ³Ψ‚θζ‚θΚ’u
		RECT_F dstm_bty; //•`‰ζζ•\¦Κ’u
		srcm_bty.m_top = 0.0f;
		srcm_bty.m_left = 130.0f;
		srcm_bty.m_right = 245.0f;
		srcm_bty.m_bottom = 115.0f;

		//•\¦Κ’u‚Μέ’θ
		dstm_bty.m_top = 600.0f;
		dstm_bty.m_left = 868.0f;
		dstm_bty.m_right = 983.0f;
		dstm_bty.m_bottom = 735.0f;
		if (hero->GetPushb() == 4)
		{
			//•`‰ζ
			Draw::Draw(36, &srcm_bty, &dstm_bty, c3, 0.0f);
		}
		else
		{
			//•`‰ζ
			Draw::Draw(36, &srcm_bty, &dstm_bty, c, 0.0f);
		}
	}
	else
	{
		//‰Ξ“Ω
		RECT_F srcm_bta; //•`‰ζ³Ψ‚θζ‚θΚ’u
		RECT_F dstm_bta; //•`‰ζζ•\¦Κ’u
		srcm_bta.m_top = 125.0f;
		srcm_bta.m_left = 240.0f;
		srcm_bta.m_right = 362.0f;
		srcm_bta.m_bottom = 245.0f;

		//•\¦Κ’u‚Μέ’θ
		dstm_bta.m_top = 700.0f;
		dstm_bta.m_left = 978.0f;
		dstm_bta.m_right = 1100.0f;
		dstm_bta.m_bottom = 820.0f;
		if (hero->GetPushb() == 1)
		{
			//•`‰ζ
			Draw::Draw(37, &srcm_bta, &dstm_bta, c3, 0.0f);
		}
		else
		{
			//•`‰ζ
			Draw::Draw(37, &srcm_bta, &dstm_bta, c, 0.0f);
		}
		//“y“Ω
		RECT_F srcm_btx; //•`‰ζ³Ψ‚θζ‚θΚ’u
		RECT_F dstm_btx; //•`‰ζζ•\¦Κ’u
		srcm_btx.m_top = 125.0f;
		srcm_btx.m_left = 0.0f;
		srcm_btx.m_right = 120.0f;
		srcm_btx.m_bottom = 245.0f;

		//•\¦Κ’u‚Μέ’θ
		dstm_btx.m_top = 700.0f;
		dstm_btx.m_left = 750.0f;
		dstm_btx.m_right = 870.0f;
		dstm_btx.m_bottom = 820.0f;
		if (hero->GetPushb() == 3)
		{
			//•`‰ζ
			Draw::Draw(37, &srcm_btx, &dstm_btx, c3, 0.0f);
		}
		else
		{
			//•`‰ζ
			Draw::Draw(37, &srcm_btx, &dstm_btx, c, 0.0f);
		}
		//’b“Ω
		RECT_F srcm_bty; //•`‰ζ³Ψ‚θζ‚θΚ’u
		RECT_F dstm_bty; //•`‰ζζ•\¦Κ’u
		srcm_bty.m_top = 0.0f;
		srcm_bty.m_left = 130.0f;
		srcm_bty.m_right = 245.0f;
		srcm_bty.m_bottom = 115.0f;

		//•\¦Κ’u‚Μέ’θ
		dstm_bty.m_top = 600.0f;
		dstm_bty.m_left = 868.0f;
		dstm_bty.m_right = 983.0f;
		dstm_bty.m_bottom = 735.0f;
		if (hero->GetPushb() == 4)
		{
			//•`‰ζ
			Draw::Draw(37, &srcm_bty, &dstm_bty, c3, 0.0f);
		}
		else
		{
			//•`‰ζ
			Draw::Draw(37, &srcm_bty, &dstm_bty, c, 0.0f);
		}
	}
	//ƒWƒƒƒ“ƒv
	RECT_F srcm_btb; //•`‰ζ³Ψ‚θζ‚θΚ’u
	RECT_F dstm_btb; //•`‰ζζ•\¦Κ’u
	srcm_btb.m_top = 240.0f;
	srcm_btb.m_left = 130.0f;
	srcm_btb.m_right = 245.0f;
	srcm_btb.m_bottom = 362.0f;

	//•\¦Κ’u‚Μέ’θ
	dstm_btb.m_top = 778.0f;
	dstm_btb.m_left = 868.0f;
	dstm_btb.m_right = 983.0f;
	dstm_btb.m_bottom = 900.0f;
	if (hero->GetPushb() == 2)
	{
		//•`‰ζ
		Draw::Draw(36, &srcm_btb, &dstm_btb, c3, 0.0f);
	}
	else
	{
		//•`‰ζ
		Draw::Draw(36, &srcm_btb, &dstm_btb, c, 0.0f);
	}
	

	//ƒWƒƒƒ“ƒv
RECT_F srcm_btm; //•`‰ζ³Ψ‚θζ‚θΚ’u
RECT_F dstm_btm; //•`‰ζζ•\¦Κ’u
srcm_btm.m_top = 0.0f;
srcm_btm.m_left = 0.0f;
srcm_btm.m_right = 99.0f;
srcm_btm.m_bottom = 178.0f;

//•\¦Κ’u‚Μέ’θ
dstm_btm.m_top = 600.0f;
dstm_btm.m_left = 1100.0f;
dstm_btm.m_right = 1200.0f;
dstm_btm.m_bottom = 750.0f;
if (hero->GetPushb() == 5)
{
	//•`‰ζ
	Draw::Draw(38, &srcm_btm, &dstm_btm, c3, 0.0f);
}
else
{
	//•`‰ζ
	Draw::Draw(38, &srcm_btm, &dstm_btm, c, 0.0f);
}
RECT_F srcmn; //•`‰ζ³Ψ‚θζ‚θΚ’u
RECT_F dstmn; //•`‰ζζ•\¦Κ’u
srcmn.m_top = 0.0f;
srcmn.m_left = 0.0f;
srcmn.m_right = 512.0f;
srcmn.m_bottom = 365.0f;

//•\¦Κ’u‚Μέ’θ
dstmn.m_top = 600.0f;
dstmn.m_left = 0.0f;
dstmn.m_right = 750.0f;
dstmn.m_bottom = 900.0f;

//•`‰ζ
Draw::Draw(39, &srcmn, &dstmn, c, 0.0f);
CObjScroll* sc = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
RECT_F srcm_n; //•`‰ζ³Ψ‚θζ‚θΚ’u
RECT_F dstm_n; //•`‰ζζ•\¦Κ’u
srcm_n.m_top = 0.0f;
srcm_n.m_left = 0.0f;
srcm_n.m_right = 200.0f;
srcm_n.m_bottom = 200.0f;
ys = sc->GetYScroll()+2320;
//•\¦Κ’u‚Μέ’θ
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
//•`‰ζ
Draw::Draw(18, &srcm_n, &dstm_n, c, 0.0f);
RECT_F dstf_m; //•`‰ζζ•\¦Κ’u
//•\¦Κ’u‚Μέ’θ
dstf_m.m_top = 0.0f;
dstf_m.m_left = 1100.0f;
dstf_m.m_right = 1200.0f;
dstf_m.m_bottom = 120.0f;
//•`‰ζ
Draw::Draw(32, &srcb, &dstf_m, c, 0.0f);
RECT_F srcf_n; //•`‰ζ³Ψ‚θζ‚θΚ’u
RECT_F dstf_n; //•`‰ζζ•\¦Κ’u
srcf_n.m_top = 30.0f;
srcf_n.m_left = 35.0f+(fs*90);
srcf_n.m_right = 90.0f + (fs *90);
srcf_n.m_bottom = 140.0f;
//•\¦Κ’u‚Μέ’θ
dstf_n.m_top =10.0f;
dstf_n.m_left = 1110;
dstf_n.m_right = 1190;
dstf_n.m_bottom = 100.0f;
//•`‰ζ
Draw::Draw(40, &srcf_n, &dstf_n, c, 0.0f);
}