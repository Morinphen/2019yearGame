#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjTBlock :public CObj
{
public:
	CObjTBlock(int x, int y);
	~CObjTBlock() {};
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
	int m_x;
	int m_y;

	int sm_x;//初期位置保存
	int sm_y;//初期位置保存

	int n;

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	int m_map[10][100];

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	int modecheck;//モードチェンジ(1,止まる2,落とす3,上げる)

	//画面内の時のみヒットボックスをつける
	bool HitBox_ON;

	bool stop;
};