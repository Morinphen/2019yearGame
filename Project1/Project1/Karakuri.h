#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class  CObjKarakuri :public CObj
{
public:
	CObjKarakuri(int x, int y,int n);
	~CObjKarakuri() {};

	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	bool GetON_OFF() { return on_off; }

private:
	int m_x;
	int m_y;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	int num;

	bool on_off;

	//画面内の時のみヒットボックスをつける
	bool HitBox_ON;
};
