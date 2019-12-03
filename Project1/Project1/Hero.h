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

	//現在の座標を渡す
	float GetX() { return m_x; }
	float GetY() { return m_y; }
	//加速度を渡す
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	//リスタート用の変数を渡す
	float GetWX() { return w_x; }
	float GetWY() { return w_y; }

	//主人公の座標を外部から変更する
	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }

	//主人公の加速度を外部から変更する
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	//主人公の手裏剣の所持数を渡す
	float GetPS() { return psyuriken; }
	//主人公の手裏剣の所持数を外部から変更する
	void SetPS(float x) { psyuriken = psyuriken+x; }

	//主人公のリスタート位置を外部から変更する
	void SetWX(float x) { w_x = x; }
	void SetWY(float y) { w_y = y; }

	bool GetCF() { return Cflag; }
	//主人公の残機数を渡す
	float GetRE() { return remain; }
	//主人公の残機数を外部から変更する
	void SetRE(float x) { remain = remain - x; }
	//主人公のモード状態を渡す
	bool GetChange() { return change; }

	//主人公の鉤縄使用状態を外部から変更する
	void NawaIdo(bool b) { nawa_ido = b; }
	void ReSetN(bool b) { nawa_stop = b; }
	void SetNX(float x) { n_x = x; }
	void SetNY(float y) { n_y = y; }

	//主人公の鉤縄を使用している状態を渡す
	bool GetNawa() { return nawa_stop; }
	bool GetINawa() { return nawa_ido; }
	void Uflag(bool b) { U_flag = b; }

	//主人公の虫獣遁のフラグを設定
	void HamuSetUP(bool b) { nezumi = b; }

	//主人公の死亡フラグを外部から変更する
	void Dflag(bool b) { dead = b; }
	void WDflag(bool b) { Wdead = b; }
	bool GetWDflag() { return Wdead; }

	//主人公の当たり判定の状態を外部から変更する
	void SetUP(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	//主人公の当たり判定の状態を外部に渡す
	bool GetUP() { return m_hit_up; }
	bool GetDown() { return m_hit_down; }
	bool GetLeft() { return m_hit_left; }
	bool GetRight() { return m_hit_right; }

	//土遁の術確認
	bool GetDoton() { return doton; }

	//主人公の戦闘スタイルを外部に渡す
	bool GetMode() { return change; }

	//右に歩く
	void Rightwalk();
	void Leftwalk();

	bool Sworp;//ワープ制御用変数



	//忍術フラグ
	bool Ninzyutu;

	//クリア用フラグ
	bool Cflag;

	//ワープする際の画像切り取り位置
	float W_cat;
	float W_cat2;

	bool GetBallFlag() { return ball; }
	void SetBallFlag(bool f) { ball = f; }

private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;
	float m_posture;//姿勢
	float remain;//残機

	float g_x;//グローバルX位置
	float g_y;//グローバルY位置

	//リスタート用位置
	float w_x;
	float w_y;

	int jamptime;
	float jamppower;

	//手裏剣の所持数
	int psyuriken;

	//攻撃等の制限用変数
	bool s_atack;
	bool nawa_stop;

	//縄移動用変数
	bool nawa_ido;
	float n_x;
	float n_y;
	int idocount;

	//うちかぎフラグ
	bool U_flag;
	bool U_scroll;

	//実験用シノビチェンジ
	bool change;
	bool c_stop;
	float green;

	//虫獣遁用変数
	bool nezumi;

	//死亡フラグ
	bool dead;
	bool Wdead;

	int d_ani_time;
	int d_ani_frame;

	//土遁の術
	bool doton;

	bool ball;//煙玉フラグ
	bool smokeh;//煙との衝突確認用
	int m_ani_time;//アニメーションフレーム
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作

	//blockとの衝突確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};