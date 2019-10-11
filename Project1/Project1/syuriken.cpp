//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"syuriken.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjSyuriken::CObjSyuriken(int x,int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjSyuriken::Init()
{
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

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_PLAYER, OBJ_SYURIKEN, 1);
}
//アクション
void CObjSyuriken::Action()
{
	m_x += 7.0f;
	m_y += m_vy;

	//弾丸のヒットボックス更新
	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_BLOCK)!=nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	hit->SetPos(m_x, m_y);
}
//ドロー
void CObjSyuriken::Draw()
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

	Draw::Draw(3, &src, &dst, c, 0.0f);
}