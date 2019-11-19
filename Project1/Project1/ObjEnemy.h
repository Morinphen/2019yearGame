#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵
class CObjEnemy :public CObj
{
public:
	CObjEnemy(int x,int y);
	~CObjEnemy() {};
	void Init(); //イニシャライズ
	void Action();//アクション
	void Draw(); //ドロー

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVX(float vx) { m_vx = vx; }
	void SetVY(float vy) { m_vy = vy; }

	void SetUP(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
	void SetF(bool b) { find = b; }
	void SetD(bool b) { de = b; }

private:
	float m_px; //位置
	float m_py;
	float m_vx; //移動ベクトル
	float m_vy;
	float m_posture; //姿勢

	bool find;
	bool m_move;
	bool de;

	int m_ani_time; //アニメーション
	int m_ani_frame;//描画フレーム
	int m_posture_time;//姿勢変えるまでの時間

	bool crhitbox;
	float m_speed_power; //スピードパワー
	float m_ani_max_time; //アニメーション動作間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};