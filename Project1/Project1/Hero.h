#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjHero :public CObj
{
public:
	CObjHero();
	~CObjHero() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー
private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;

	bool m_hit_down;

};