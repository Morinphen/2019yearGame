#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト手裏剣
class CObjNezumi :public CObj
{
public:
	CObjNezumi(int x, int y, int muki);
	~CObjNezumi() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	//ハム太郎が歩けるかどうかを判定
	bool mapsarch(int x,int y,int muki);
	//ハム太郎の現在地を返す
	int mapplace(int x, int y, int muki);
private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;

	//ハム太郎のおおきさ
	int Dimax;

	//ハム太郎の位置保存用変数
	int hamnam;

	//ハム太郎移動制限用変数
	bool hamstop;

	int map_data[46][100];

	//召喚された位置情報情報を保存
	float b_x;
	float b_y;

	//ハム太郎のスピード
	int speed;

	//方向の反転
	bool m_return;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	float m_posture;//姿勢

	bool flag;
	bool Bflag;

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};