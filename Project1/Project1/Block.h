#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	void SetScrooll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void SetYScrooll(float s) { l_scroll = s; }
	float GetYScroll() { return l_scroll; }
private:
	int m_x;
	int m_y;

	int m_map[10][100];

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

};