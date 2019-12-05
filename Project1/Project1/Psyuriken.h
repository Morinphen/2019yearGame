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
private:
	int ps;
	int re;
	bool mode;
	float n_m;
};