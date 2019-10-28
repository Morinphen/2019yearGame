#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjHero :public CObj
{
public:
	CObjHero(int x,int y);
	~CObjHero() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void NawaIdo(bool b) { nawa_ido = b; }
	void ReSetN(bool b) { nawa_stop = b; }
	void SetNX(float x) { n_x = x; }
	void SetNY(float y) { n_y = y; }

	void SetUP(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	bool Sworp;//ワープ制御用変数

	//ワープする際の画像切り取り位置
	float W_cat;
	float W_cat2;

private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;
	float m_posture;//姿勢

	int jamptime;
	float jamppower;

	//攻撃等の制限用変数
	bool s_atack;
	bool nawa_stop;

	//縄移動用変数
	bool nawa_ido;
	float n_x;
	float n_y;

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