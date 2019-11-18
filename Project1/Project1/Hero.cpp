//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hero.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjHero::CObjHero()
{
	
}

//イニシャライズ
void CObjHero::Init()
{
	//m_x = 100;
	//m_y = 300;
	m_vx = 0;
	m_vy = 0;
	m_posture = 0.0f;//右向き0.0ｆ、左向き1.0f

	jamptime = 0;
	jamppower = 0.0f;
	W_cat = 1.0f;
	W_cat2 = 0.0f;

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

	U_scroll = false;

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
	//敵の位置を取得
	CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//スクロール情報取得
	CObjScroll * scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	//ブロックとの当たり判定
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	if (W_cat == 1.0f&&nawa_ido == false && U_flag == false) {
		Ninzyutu = false;
		U_scroll = false;

		pb->BlockHit(&m_x, &m_y,true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
			&m_vx, &m_vy
		);

		if (Input::GetVKey(VK_RIGHT) == true) {
			//Cボタンを押しているとダッシュ
			if (Input::GetVKey('C') == true && m_hit_down == true) {
				m_vx += 0.5f;
				m_ani_time++;
			}
			m_vx += 0.5f;

			m_ani_time++;
			m_posture = 0.0f;
		}

		else if (Input::GetVKey(VK_LEFT) == true) {
			//Cボタンを押しているとダッシュ
			if (Input::GetVKey('C') == true && m_hit_down == true) {
				m_vx -= 0.5f;
				m_ani_time++;
			}
			m_vx -= 0.5f;
			m_ani_time++;
			m_posture = 1.0f;
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

			jamppower += 4.0f;
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

		//重力
		if (m_vy < 10)
			m_vy += 9.8f / 16.0f;

		if (nawa_stop == false) {

			//シノビチェンジ
			if (Input::GetVKey('Q'))
			{
				if (c_stop == false) {
					if(green!=0.0f)
						green = 0.0f;
					else
						green = 1.0f;
					change = change ? false : true;
					c_stop = true;
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
						CObjSyuriken* obj_s = new CObjSyuriken(m_x, m_y, m_posture);
						Objs::InsertObj(obj_s, OBJ_SYURIKEN, 10);
						s_atack = true;
					}
				}

				//鉤縄
				else if (Input::GetVKey('V') && nawa_stop == false && m_hit_down == true)
				{
					if (s_atack == false) {
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
						CObjSmokeball* obj_s = new CObjSmokeball(m_x, m_y, m_posture);
						Objs::InsertObj(obj_s, OBJ_SMOKEBALL, 10);
						ball = true;
					}
				}
			}

			else {
				//火遁
				if (Input::GetVKey('Z'))
				{
					if (s_atack == false) {
						CObjHinotama* obj_s = new CObjHinotama(m_x, m_y, m_posture);
						Objs::InsertObj(obj_s, OBJ_HINOTAMA, 10);
						s_atack = true;
					}
				}
				else
				{
					s_atack = false;
				}

				//土遁（仮）
				if (Input::GetVKey('S'))
				{
					if (s_atack == false) 
					{
						doton = doton ? false : true;
					}
				}
				else
				{
					s_atack = false;
				}
			}

			//ジャンプ
			if (Input::GetVKey('X') && m_hit_down == true)
			{
				if (jamptime == 0)
					jamptime++;
	
				jamppower += 3.5f;
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

		}
	}

	//うちかぎを使用しているとき
	else if (U_flag == true)
	{
		pb->UBlockHit(&m_x, &m_y,&U_scroll,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy
		);

		/*scroll->SetUtikagiScroll(&m_x, &m_y);*/

		m_vy = 0;

		Ninzyutu = true;

		if (Input::GetVKey(VK_RIGHT) == true) {
			m_vx += 0.5f;

			m_ani_time++;
			m_posture = 0.0f;
		}

		else if (Input::GetVKey(VK_LEFT) == true) {
			m_vx -= 0.5f;
			m_ani_time++;
			m_posture = 1.0f;
		}
	}

	else
	{
		Ninzyutu = true;
	}

	if (m_y > 700.0f)
	{
		Scene::SetScene(new CSceneMain);
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
			n_x = 0;
			n_y = 0;
			idocount = 0;
		}
	}

	m_x += m_vx;

	m_y += m_vy;

	hit->SetPos(m_x, m_y);
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
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr&&smokeh==false)
	{
		Scene::SetScene(new CSceneMain);
	}

}

//ドロー
void CObjHero::Draw()
{
	float aa = (W_cat2/50);
	float c[4] = { green,1.0f,green,1.0f + aa };
	RECT_F src;
	RECT_F dst;

	if (U_flag == false) {
		src.m_top = 64.0f;
		src.m_left = 64.0f*(m_ani_frame*W_cat);
		src.m_right = 64.0f*((m_ani_frame*W_cat + 1));
		src.m_bottom = 128.0f;
	}

	else {
		src.m_top = 0.0f;
		src.m_left = 64.0f*(m_ani_frame*W_cat+1);
		src.m_right = 64.0f*((m_ani_frame*W_cat));
		src.m_bottom = 64.0f;
	}

	dst.m_top = 0.0f + m_y;
	if (m_posture == 0) {
		dst.m_left = (64.0f*m_posture) - W_cat2 + m_x;
		dst.m_right = (64.0f - 64.0f*m_posture) + W_cat2 + m_x;
	}
	else
	{
		dst.m_left = (64.0f*m_posture) + W_cat2 + m_x;
		dst.m_right = (64.0f - 64.0f*m_posture) - W_cat2 + m_x;
	}
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(11, &src, &dst, c, 0.0f);
}
