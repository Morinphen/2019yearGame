#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjHonoBlock :public CObj
{
public:
	CObjHonoBlock(int x, int y);
	~CObjHonoBlock() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	void SetScrooll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void SetYScrooll(float s) { l_scroll = s; }
	float GetYScroll() { return l_scroll; }

	////主人公と壁の交差判定
	//bool HeroBlockCrossPoint(
	//	float x, float y, float vx, float vy,
	//	float *out_px, float *out_py, float* out_len
	//);

private:
	

	float m_x;
	float m_y;

	//元々いた場所を保存する
	float b_x;
	float b_y;

	float m_vx;
	float m_vy;

	int m_map[10][100];

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	bool enzyou;

	//画面内の時のみヒットボックスをつける
	bool HitBox_ON;

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};