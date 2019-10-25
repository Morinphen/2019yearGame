//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hero.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjHero::CObjHero(int x,int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjHero::Init()
{
	m_x = 100;
	m_y = 300;
	m_vx = 0;
	m_vy = 0;
	m_posture = 0.0f;//右向き0.0ｆ、左向き1.0f

	jamptime = 0;
	jamppower = 0.0f;
	W_cat = 1.0f;
	W_cat2 = 0.0f;

	s_atack = false;
	Sworp = false;

	ball = false;

	m_ani_time = 0;
	m_ani_frame = 0;//静止フレーム初期化

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 2;//アニメーション感覚幅

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_PLAYER, OBJ_HERO,1);
}
//アクション
void CObjHero::Action()
{
	//ブロックとの当たり判定
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_x, &m_y,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,false,
		&m_vx, &m_vy
	);

	if (Input::GetVKey(VK_RIGHT) == true) {
		//Cボタンを押しているとダッシュ
		if (Input::GetVKey('C') == true) {
			m_vx += 1.0f;
			m_ani_time++;
		}
		m_vx += 1.0f;

			m_ani_time++;
			m_posture = 0.0f;
		}

		else if (Input::GetVKey(VK_LEFT) == true) {
			//Cボタンを押しているとダッシュ
			if (Input::GetVKey('C') == true) {
				m_vx -= 1.0f;
				m_ani_time++;
			}
			m_vx -= 1.0f;
			m_ani_time++;
			m_posture = 1.0f;
		}

		else
		{
			m_ani_frame = 0;
			m_ani_time = 0;
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

	//攻撃
	if (Input::GetVKey('Z'))
	{
		if (s_atack == false) {
			CObjSyuriken* obj_s = new CObjSyuriken(m_x, m_y, m_posture);
			Objs::InsertObj(obj_s, OBJ_SYURIKEN, 10);
			s_atack = true;
		}
	}
	else 
	{
		s_atack = false;
	}

	//煙玉
	if (Input::GetVKey('A'))
	{
		if (ball == false) 
		{
			CObjSmokeball* obj_s = new CObjSmokeball(m_x, m_y, m_posture);
			Objs::InsertObj(obj_s, OBJ_SMOKEBALL, 10);
			ball = true;
		}
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
	}

	if (m_y > 700.0f)
	{
		Scene::SetScene(new CSceneMain);
	}

	//上入力制御
	if (Input::GetVKey(VK_UP) == true || W_cat!=1.0f)
	{
		;
	}
	else 
	{
		Sworp = false;
	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//重力
	if(m_vy<10)
		m_vy += 9.8f / 16.0f;

	m_x += m_vx;

	m_y += m_vy;

	//弾丸のヒットボックス更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
}
//ドロー
void CObjHero::Draw()
{
	float aa = (W_cat2/50);
	float c[4] = { 1.0f,1.0f,1.0f,1.0f + aa };
	RECT_F src;
	RECT_F dst;

	src.m_top = 64.0f;
	src.m_left = 64.0f*(m_ani_frame*W_cat);
	src.m_right = 64.0f*((m_ani_frame*W_cat + 1));
	src.m_bottom = 128.0f;

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

	Draw::Draw(4, &src, &dst, c, 0.0f);
}