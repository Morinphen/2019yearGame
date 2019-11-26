#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjNezuana :public CObj
{
public:
	CObjNezuana(int x, int y,int n);
	~CObjNezuana() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	void SetScrooll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void SetYScrooll(float s) { l_scroll = s; }
	float GetYScroll() { return l_scroll; }

	bool GetDnamber() { return Dnamber; }

	void SetFlag(float s) { flag = s; }

private:
	int m_x;
	int m_y;

	bool flag;
	float testc;

	//自身の番号を保存する変数
	int Namber;
	bool Dnamber;

	bool stop;

	int m_map[10][100];

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数
};