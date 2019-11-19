#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト手裏剣
class CObjNagenawa :public CObj
{
public:
	CObjNagenawa(int x, int y, int a, float vx, float vy);
	~CObjNagenawa() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	int Pworp;
private:
	float m_x;
	float m_y;

	float m_vx;
	float m_vy;

	//縄の向き
	float m_muki;
	//縄の重力用変数
	float grabty;
	//縄の長さ用変数
	float Nawa;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数


	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作

	//blockとの衝突確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};