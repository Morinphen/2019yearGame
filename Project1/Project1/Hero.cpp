//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hero.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjHero::CObjHero()
{
	
}

//イニシャライズ
void CObjHero::Init()
{
	//スクロール情報取得
	CObjScroll * scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_x = 400;
	m_y = 600;
	m_vx = 0;
	m_vy = 0;
	m_posture = 0.0f;//右向き0.0ｆ、左向き1.0f
	remain = 3;//残機

	jamptime = 0;
	jamppower = 0.0f;
	W_cat = 1.0f;
	W_cat2 = 0.0f;

	n_m = -1;
	green = 1.0f;
	change = false;
	c_stop = false;

	s_atack = false;
	nawa_stop = false;
	Sworp = false;
	nawa_ido = false;
	idocount = 0;

	doton = false;
	ball = false;
	smokeh = false;
	U_flag = false;

	Ninzyutu = false;

	Cflag = false;

	U_scroll = false;

	dead = false;
	Wdead = false;
	dead_s = false;
	deadtime = 0;
	pushb=0;

	d_ani_time = 0;
	d_ani_frame = 0;

	doton=false;
	nezumi = false;

	hero_stop = false;

	w_x = 400;
	w_y = 600-scroll->GetYScroll();

	m_ani_time = 0;
	m_ani_frame = 0;//静止フレーム初期化

	m_speed_power = 0.3f;//通常速度
	m_ani_max_time = 2;//アニメーション感覚幅

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	Hits::SetHitBox(this, m_x, m_y,64,64, ELEMENT_PLAYER, OBJ_HERO,1);
}

//アクション
void CObjHero::Action()
{
	if (remain <= 0)
	{
		Scene::SetScene(new CSceneRetry);
	}
	if (dead_s == true)
	{
		deadtime += 1;
	}
	//敵の位置を取得
	CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//ブロックとの当たり判定
	CObjDonden* dd = (CObjDonden*)Objs::GetObj(OBJ_DONDEN);
	//スクロール情報取得
	CObjScroll * scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	//ブロックとの当たり判定
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	pb->BlockHit(&m_x, &m_y, true, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
		&m_vx, &m_vy
	);
   if(dead_s==false)
   {
	//主人公が死んでおらず、うちかぎを使用しておらず、投げ縄の移動中ではないとき
	if (W_cat == 1.0f&&nawa_ido == false && U_flag == false && dead == false && nezumi == false && hero_stop == false)
	{
		Ninzyutu = false;
		U_scroll = false;
		d_ani_frame = 0;
		d_ani_time = 0;

		if (Input::GetVKey(VK_RIGHT) == true) {
			//Cボタンを押しているとダッシュ
			if (change == true)
			{
				n_m = 5;
			}
			if (Input::GetVKey('C') == true && m_hit_down == true) {
				m_vx += 0.5f;
				m_ani_time++;
			}
			Rightwalk();
		}

		else if (Input::GetVKey(VK_LEFT) == true) {
			if (change == true)
			{
				n_m = 5;
			}
			//Cボタンを押しているとダッシュ
			if (Input::GetVKey('C') == true && m_hit_down == true) {
				m_vx -= 0.5f;
				m_ani_time++;
			}
			Leftwalk();
		}

		else
		{
			m_ani_frame = 0;
			m_ani_time = 0;
		}

		//ジャンプ
		if (Input::GetVKey('X') && m_hit_down == true)
		{
			if (jamptime == 0)
				jamptime++;
			pushb = 2;
			Audio::Start(2);
			jamppower += 8.0f;
		}

		if (jamptime != 0)
		{
			jamptime++;
			if (jamptime == 5)
			{
				m_vy = -jamppower;
				m_y += m_vy;
				jamptime = 0;
				jamppower = 0.0f;
			}
		}

		if (jamptime != 0)
		{
			jamptime++;
			if (jamptime == 5)
			{
				m_vy = -jamppower;
				m_y += m_vy;
				jamptime = 0;
				jamppower = 0.0f;
			}
		}

		if (nawa_stop == false || nezumi == false) {

			//シノビチェンジ
			if (Input::GetVKey('Q'))
			{
				if (c_stop == false) {
					if (green != 0.0f)
					{
						n_m = 5;
						green = 0.0f;
					}
					else
					{
						n_m = -1;
						green = 1.0f;
					}
					change = change ? false : true;
					c_stop = true;
					Audio::Start(20);
					pushb = 5;
				}
			}
			else
			{
				c_stop = false;
			}

			//忍具モード時
			if (change == false) {
				//攻撃
				if (Input::GetVKey('Z'))
				{
					if (s_atack == false) {
							n_m = 0;
							Audio::Start(1);
							pushb = 1;
							CObjSyuriken* obj_s = new CObjSyuriken(m_x, m_y, m_posture);
							Objs::InsertObj(obj_s, OBJ_SYURIKEN, 10);
							s_atack = true;
							if (m_posture == 1.0f)
							{
								CObjSyuriken* sy = (CObjSyuriken*)Objs::GetObj(OBJ_SYURIKEN);
								sy->SetP(true);
							}
							else
							{
								CObjSyuriken* sy = (CObjSyuriken*)Objs::GetObj(OBJ_SYURIKEN);
								sy->SetP(false);
							}
					}
				}

				//鉤縄
				else if (Input::GetVKey('V') && nawa_stop == false && m_hit_down == true)
				{
					if (s_atack == false) {
						pushb = 4;
						n_m = 1;
						CObjKaginawa* obj_s = new CObjKaginawa(m_x, m_y, m_posture);
						Objs::InsertObj(obj_s, OBJ_KAGINAWA, 10);
						s_atack = true;
						nawa_stop = true;
					}
				}

				else
				{
					s_atack = false;
				}

				//煙玉
				if (Input::GetVKey('D'))
				{
					if (ball == false)
					{
						pushb = 3;
						n_m = 3;
						CObjSmokeball* obj_s = new CObjSmokeball(m_x, m_y, m_posture);
						Objs::InsertObj(obj_s, OBJ_SMOKEBALL, 10);
						ball = true;
					}
				}
				//忍術モード解除で土遁解除
				doton = false;
			}
			//妖術モード
			else {
				//火遁
				if (Input::GetVKey('Z'))
				{
					if (s_atack == false) {
						pushb = 1;
						n_m = 4;
						Audio::Start(16);
						CObjHinotama* obj_s = new CObjHinotama(m_x, m_y, m_posture);
						Objs::InsertObj(obj_s, OBJ_HINOTAMA, 10);
						s_atack = true;
						if (m_posture == 1.0f)
						{
							CObjHinotama* sy = (CObjHinotama*)Objs::GetObj(OBJ_HINOTAMA);
							sy->SetP(true);
						}
						else
						{
							CObjHinotama* sy = (CObjHinotama*)Objs::GetObj(OBJ_HINOTAMA);
							sy->SetP(false);
						}
					}
				}

				else if (Input::GetVKey('S'))
				{
					if (s_atack == false)
					{
						pushb = 3;
						n_m = 6;
						doton = doton ? false : true;
						s_atack = true;
					}
				}

				else if (Input::GetVKey('D') && m_hit_down == true)
				{
					if (s_atack == false && nezumi == false)
					{
						pushb = 4;
						n_m = 7;
						CObjNezumi* obj_n = new CObjNezumi(m_x, m_y, m_posture);
						Objs::InsertObj(obj_n, OBJ_HAMUTARO, 10);
						s_atack = true;
						nezumi = true;
					}
				}

				else
				{
					s_atack = false;
					doton = false;
				}
			}

		}
	}
 }
	//うちかぎを使用しているとき
	if (U_flag == true)
	{
		pb->UBlockHit(&m_x, &m_y,&U_scroll,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy
		);

		m_vy = 0;

		Ninzyutu = true;
		n_m = 2;

		if (Input::GetVKey(VK_RIGHT) == true) {
			Rightwalk();
		}

		else if (Input::GetVKey(VK_LEFT) == true) {
			Leftwalk();
		}
	}

	else
	{
		Ninzyutu = false;
	}

	//水で死亡したとき
	if (Wdead == true) {
		dead = true;
		if (d_ani_frame < 4) {
			d_ani_time++;
			m_ani_frame = 0;
		}
		if (d_ani_time == 8)
		{
			d_ani_time = 0;
			d_ani_frame++;
		}
	}

	//上入力制御
	if (Input::GetVKey(VK_UP) == true || W_cat != 1.0f)
	{
		;
	}
	else
	{
		Sworp = false;
	}

	//アニメーション
	if (m_ani_time >= 8)
	{
		m_ani_time = 0;
		m_ani_frame++;
		if (m_ani_frame == 2)
		{
			m_ani_frame = 0;
		}
	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//ヒットボックス更新
	CHitBox* hit = Hits::GetHitBox(this);

	//縄移動
	if (nawa_ido == true)
	{
		idocount++;
		s_atack = true;
		nawa_stop = true;
		m_vx = n_x / 30;
		m_vy = -n_y / 30;

		if (idocount==30)
		{
			nawa_ido = false;
			nawa_stop = false;
			hero_stop = false;
			n_x = 0;
			n_y = 0;
			idocount = 0;
		}
	}

	//重力
	if (m_vy < 10)
		m_vy += 9.8f / 16.0f;

	m_x += m_vx;

	m_y += m_vy;
	//煙玉の煙と当たっているかどうか確認
	if (hit->CheckObjNameHit(OBJ_SMOKEBALL) != nullptr)
	{
		smokeh = true;
	}
	else
	{
		smokeh = false;
	}

	//敵と当たっているかどうか確認
	/*if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr&&smokeh==false||
		hit->CheckObjNameHit(OBJ_HAMENEMY) != nullptr&&smokeh == false)
	{*/
		if (deadtime > 180)
		{
			remain -= 1;
			SetX(GetWX());
			SetY(GetWY());
			if (GetX() < 500) {
				scroll->SetScrooll(-(GetX() - (500)));
			}
			else if (GetX() > 600) {
				scroll->SetScrooll(-(GetX() - (600)));
			}

			if (GetY() < 80) {
				scroll->SetYScrooll(-(GetY() - (80)));
			}
			else if (GetY() > 500) {
				scroll->SetYScrooll(-(GetY() - (500)));
			}

			WDflag(false);
			Dflag(false);
			dead_s = false;
			deadtime = 0;
		}

//}

	//天井と当たっているかどうか確認
	if (hit->CheckObjNameHit(OBJ_TURIBLOCK2) != nullptr)
	{
		remain -= 1;
		SetX(GetWX());
		SetY(GetWY());
		if (GetX() < 500) {
			scroll->SetScrooll(-(GetX() - (500)));
		}
		else if (GetX() > 600) {
			scroll->SetScrooll(-(GetX() - (600)));
		}

		if (GetY() < 80) {
			scroll->SetYScrooll(-(GetY() - (80)));
		}
		else if (GetY() > 500) {
			scroll->SetYScrooll(-(GetY() - (500)));
		}

		WDflag(false);
		Dflag(false);
	}

	hit->SetPos(m_x, m_y);
}

//ドロー
void CObjHero::Draw()
{
	float aa = (W_cat2/50);
	float c[4] = { green,1.0f,green,1.0f + aa };
	RECT_F src;
	RECT_F dst;
	if (dead_s == false)
	{
		if (U_flag == false && Wdead == false) {
			src.m_top = 64.0f;
			src.m_left = 64.0f*(m_ani_frame*W_cat);
			src.m_right = 64.0f*((m_ani_frame*W_cat + 1));
			src.m_bottom = 128.0f;
		}

		else if (Wdead == true) {
			src.m_top = 128.0f;
			src.m_left = 64.0f*(d_ani_frame*W_cat);
			src.m_right = 64.0f*((d_ani_frame*W_cat + 1));
			src.m_bottom = 196.0f;
		}

		else {
			src.m_top = 0.0f;
			src.m_left = 64.0f*(m_ani_frame*W_cat + 1);
			src.m_right = 64.0f*((m_ani_frame*W_cat));
			src.m_bottom = 64.0f;
		}

		if (Wdead == false) {
			dst.m_top = 0.0f + m_y;
			dst.m_bottom = 64.0f + m_y;
		}

		else {
			dst.m_top = 0.0f + m_y - 48;
			dst.m_bottom = 64.0f + m_y - 48;
		}

		if (m_posture == 0) {
			dst.m_left = (64.0f*m_posture) - W_cat2 + m_x;
			dst.m_right = (64.0f - 64.0f*m_posture) + W_cat2 + m_x;
		}
		else
		{
			dst.m_left = (64.0f*m_posture) + W_cat2 + m_x;
			dst.m_right = (64.0f - 64.0f*m_posture) - W_cat2 + m_x;
		}

		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	else
	{
		if (deadtime < 120)
		{
			float c2[4] = { 1.0f,1.0f,1.0f,1.0f };
			src.m_top = 0.0f;
			src.m_left = 0.0;
			src.m_right = 712.0f;
			src.m_bottom = 256.0f;
			dst.m_top = 0.0f + m_y-128;
			dst.m_bottom = 64.0f + m_y;
			dst.m_left = (64.0f*m_posture) - W_cat2 + m_x-128;
			dst.m_right = (64.0f - 64.0f*m_posture) + W_cat2 + m_x+64;
			Draw::Draw(29, &src, &dst, c2, 0.0f);
		}
		else if (deadtime > 120 && deadtime < 180&&m_posture == 1)
		{
			float c2[4] = { 1.0f,1.0f,1.0f,1.0f };
			src.m_top = 0.0f;
			src.m_left = 0.0;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 0.0f + m_y;
			dst.m_bottom = 64.0f + m_y;
			dst.m_left = (64.0f*m_posture) - W_cat2 + m_x;
			dst.m_right = (64.0f - 64.0f*m_posture) + W_cat2 + m_x;
			Draw::Draw(35, &src, &dst, c2, 0.0f);
		}
		else if (deadtime > 120 && deadtime < 180 && m_posture == 0)
		{
			float c2[4] = { 1.0f,1.0f,1.0f,1.0f };
			src.m_top = 0.0f;
			src.m_left = 0.0;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 0.0f + m_y;
			dst.m_bottom = 64.0f + m_y;
			dst.m_left = (64.0f*m_posture) - W_cat2 + m_x;
			dst.m_right = (64.0f - 64.0f*m_posture) + W_cat2 + m_x;
			Draw::Draw(35, &src, &dst, c2, 0.0f);
		}
	}
}

//右に歩かせる
void CObjHero::Rightwalk()
{
	m_vx += 0.5f;
	m_ani_time++;
	m_posture = 0.0f;
}

//左に歩かせる
void CObjHero::Leftwalk()
{
	m_vx -= 0.5f;
	m_ani_time++;
	m_posture = 1.0f;
}