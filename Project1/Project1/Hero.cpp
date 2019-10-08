//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hero.h"

//使用するネームスペース
using namespace GameL;

CObjHero::CObjHero()
{

}

//イニシャライズ
void CObjHero::Init()
{
	m_x = 100;
	m_y = 300;
	m_vx = 0;
	m_vy = 0;
	m_posture = 1.0f;//右向き0.0ｆ、左向き1.0f

	jamptime = 0;
	jamppower = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
}
//アクション
void CObjHero::Action()
{
	if (Input::GetVKey(VK_RIGHT) == true) {
		m_vx += 1.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true) {
		m_vx -= 1.0f;
	}

	if (Input::GetVKey('X') && m_hit_down == true)
	{
		if(jamptime==0)
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

	//摩擦
	m_vx += -(m_vx*0.098);

	//重力
	if(m_vy<10)
		m_vy += 9.8f / 16.0f;

	m_x += m_vx;

	m_y += m_vy;
}
//ドロー
void CObjHero::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}