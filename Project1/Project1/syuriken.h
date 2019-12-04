#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト手裏剣
class CObjSyuriken :public CObj
{
public:
	CObjSyuriken(int x,int y,int m);
	~CObjSyuriken() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー
	float GetX() { return m_x; }
	float GetP() { return m_po; }
	void SetP(float p) { m_po = p; }
	void SetT(float t) { t_h = t; }
private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;
	float m_posture;//姿勢
	bool m_po;//向き　true=左　false=右
	bool t_h;//敵に当たったフラグ
	CHitBox* hit;

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム
	int m_muki;//手裏剣の方向

	float m_scroll;
	float l_scroll;

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作

	//壁に当たったとき、アニメーションをさせる
	bool Animation;
	float spen;

	//手裏剣消滅カウント
	float syuriken_time;

	//blockとの衝突確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};