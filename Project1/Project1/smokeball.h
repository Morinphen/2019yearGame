#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjSmokeball : public CObj
{
public:
	CObjSmokeball(int x, int y, int m);
	~CObjSmokeball() {};
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

	void SetUP(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	void SetDelete(bool d) { smokeball_delete = d; }
	void Setmodecheck(bool c) { modecheck = c; }

private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;
	float m_posture;//姿勢

	float g_x;
	float g_y;

	CHitBox* hit;

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム
	int m_muki;//煙玉の投げる方向

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作

	int smoke_time;//煙を出している時間
	bool smokeball_delete;//ボールの削除

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	bool modecheck;//モードチェンジ

	//blockとの衝突確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};