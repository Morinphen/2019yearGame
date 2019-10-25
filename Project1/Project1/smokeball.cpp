//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"smokeball.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjSmokeball::CObjSmokeball(int x, int y, int m)
{
	m_x = x;
	m_y = y;
	m_muki = -m;

	if (m == 0) {
		m_muki = 1;
	}
}

//イニシャライズ
void CObjSmokeball::Init()
{
	m_vx = 9 * m_muki;
	m_vy = -9;
	m_posture = 1.0f;//右向き0.0ｆ、左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	smokeball_delete = false;//削除命令

	modecheck = false;//モード切替

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_PLAYER, OBJ_SYURIKEN, 1);
}

//アクション
void CObjSmokeball::Action()
{
	//玉の状態
	if (modecheck == false)
	{

		hit = Hits::GetHitBox(this);

		//ブロックとの当たり判定
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_x, &m_y,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, true,
			&m_vx, &m_vy
		);

		//重力
		if (m_vy < 20)
			m_vy += 9.8f / 16.0f;

	}
	////煙の状態
	//else
	//{

	//}

	m_x += m_vx;
	m_y += m_vy;

	//主人公情報取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//削除処理
	if (smokeball_delete == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		hero->SetBallFlag(false);
	}

	//削除範囲
	if (m_y > 700)
		smokeball_delete = true;

	hit->SetPos(m_x, m_y);
}
//ドロー
void CObjSmokeball::Draw()
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

	Draw::Draw(5, &src, &dst, c, 0);
}