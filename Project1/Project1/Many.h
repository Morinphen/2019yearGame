#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjMany :public CObj
{
public:
	CObjMany() {};
	~CObjMany() {};
	void Init();//いにしゃらいず
	void Action();//あくしょん
	void Draw();//どろー

	bool GetOpen() { return open; }
private:
	bool m_key_flag;//キーフラグ
	bool open;//メニュー画面を出現させる
	bool H_B;
	bool Giveup;
};