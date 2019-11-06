#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjMBlock :public CObj
{
public:
	CObjMBlock(int x, int y);
	~CObjMBlock() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	void Worp();

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
	int aaa;

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	int m_map[10][100];

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	float Dot(float ax, float ay, float bx, float by);//内積
	float Cross(float ax, float ay, float bx, float by);//外積
														/*bool CObjBlock::LineCrossPoint(
														float a1x, float a1y, float a2x, float a2y,
														float b1x, float b1y, float b2x, float b2y,
														float* out_px, float* out_py
														);*/
};