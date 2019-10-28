//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjEnemy.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjEnemy::Init()
{
	m_px = 200.0f;//位置
	m_py = 500.0f;
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;//右向き0.0f　左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1; //静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 2;//アニメーション間隔幅

					   //blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	Hits::SetHitBox(this, m_vx, m_vy, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//アクション
void CObjEnemy::Action()
{
	//落下
	if (m_py > 1000.0f)
	{
		;
	}

	//通常速度
	m_speed_power = 0.5f;
	m_ani_max_time = 2;

	//方向
	if (m_px<800)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	/*else if (m_px>800)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}*/
	else
	{
		m_ani_frame = 1;
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 2)
	{
		m_ani_frame = 0;
	}



	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下運動
    m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);
}

//ドロー
void CObjEnemy::Draw()
{
	int AniData[2] =
	{
		0,1,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 65.0f;
	src.m_left = 448.0f*AniData[m_ani_frame]-64;
	src.m_right = 448.0f*AniData[m_ani_frame];
	src.m_bottom = 128.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64 - 64.0f*m_posture) + m_px;
	dst.m_right = (64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
}
