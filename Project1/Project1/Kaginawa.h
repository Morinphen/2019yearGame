#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト手裏剣
class CObjKaginawa :public CObj
{
public:
	CObjKaginawa(int x, int y,int a);
	~CObjKaginawa() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	int Pworp;
private:
	//カーソル移動用変数
	float direction;
	int D_Count;
	bool D_Suiti;

	float m_x;
	float m_y;

	float sm_x;
	float sm_y;

	float m_vx;
	float m_vy;

	float m_muki;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数


	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作
};