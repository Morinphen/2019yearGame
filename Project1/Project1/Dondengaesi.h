#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト手裏剣
class CObjDonden :public CObj
{
public:
	CObjDonden(int x, int y);
	~CObjDonden() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー
private:

	int Worp(int a);

	float m_x;
	float m_y;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	float red;

	int D_tag[10][2];//ペアのどんでん返しを探す

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作
};