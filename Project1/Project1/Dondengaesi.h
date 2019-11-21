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
	CObjDonden(int x, int y, int namber, bool b);
	~CObjDonden() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	int Pworp;
private:

	int Worp(int a);
	int TagWorp(int a);

	int Wnamber;//ワープ先の番号を保存する

	float m_x;
	float m_y;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	float red;
	//ワープする際にアニメーションをさせる
	bool Wanimation;
	bool Wanimation2;

	//鉤縄移動制御用変数
	bool N_stop;

	//土遁用
	bool doton_flag;

	//主人公の位置の確認
	bool s_down;

	//どんでん返しで隠す
	bool hide;

	int D_tag[50][3];//ペアのどんでん返しを探す

	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作

	//画面内の時のみヒットボックスをつける
	bool HitBox_ON;
};