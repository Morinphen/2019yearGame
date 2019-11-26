#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト手裏剣
class CObjUtikagi :public CObj
{
public:
	CObjUtikagi(int x, int y);
	~CObjUtikagi() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	void Refresh();//ばしょこうしん
private:
	float m_x;
	float m_y;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	bool flag;
	bool Bflag;

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作

	//画面内の時のみヒットボックスをつける
	bool HitBox_ON;
};