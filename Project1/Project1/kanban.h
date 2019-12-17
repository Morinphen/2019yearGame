#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjkanban:public CObj
{
public:
	CObjkanban(int x, int y,int t);
	~CObjkanban() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

private:

	int type;//看板の種類判別
	bool flashing;//点滅させる
	float num;//秒間カウント用

	int m_x;
	int m_y;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

};
