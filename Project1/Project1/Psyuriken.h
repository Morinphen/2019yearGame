#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjPsyuriken :public CObj
{
public:
	CObjPsyuriken() {};
	~CObjPsyuriken() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
	void SetChange(bool b) { change = b; }
private:
	int ys;
	int fs;
	int ps;
	int re;
	bool mode;
	bool change;
	float n_m;
};