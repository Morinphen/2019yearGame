#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjScroll :public CObj
{
public:
	CObjScroll(int map[46][100]);
	~CObjScroll() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	void SetScrooll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void SetYScrooll(float s) { l_scroll = s; }
	float GetYScroll() { return l_scroll; }

	float GetMNScroll() { return mn_scroll; }
	float GetLNScroll() { return ln_scroll; }
	bool Inscrooll_check(int x, int y);

	int m_map[46][100];
private:
	int m_x;
	int m_y;


	float mn_scroll;//ミニマップ用スクロール変数
	float ln_scroll;//ミニマップ用スクロール変数
	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	float w_m_scroll;//ワープ先保存左右スクロール用変数
	float w_l_scroll;//ワープ先保存上下スクロール用変数

};