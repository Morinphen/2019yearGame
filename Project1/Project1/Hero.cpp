//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hero.h"

//使用するネームスペース
using namespace GameL;

CObjHero::CObjHero()
{
	m_x = 0;
	m_y = 0;
	m_vx = 0;
	m_vy = 0;
}

//イニシャライズ
void CObjHero::Init()
{
	m_x = 0;

	m_hit_down = false;
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

	if (Input::GetVKey('X'))
	{
		if(m_hit_down==false){
			m_vy = -20.0f;
			m_y += m_vy;
			m_hit_down = true;
		}
	}
	else
	{
		m_hit_down = false;
	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//重力
	m_vy += 9.8f / 16.0f;

	m_x += m_vx;

	if (m_y<300)
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