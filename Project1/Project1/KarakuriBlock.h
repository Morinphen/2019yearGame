#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class  CObjKarakuriblock :public CObj
{
public:
	CObjKarakuriblock(int x, int y, int n);
	~CObjKarakuriblock() {};

	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	void SetDelete(bool b) { Delete = b; }

private:
	int m_x;
	int m_y;

	float m_scroll;//左右スクロール用変数
	float l_scroll;//上下スクロール用変数

	int num;//識別番号
	bool Delete;//削除命令
	//画面内の時のみヒットボックスをつける
	bool HitBox_ON;
};
