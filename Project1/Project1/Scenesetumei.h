#pragma once
//使用するヘッダファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CScenesetumei :public CScene
{
public:
	CScenesetumei();
	~CScenesetumei();
	void InitScene();//ゲーム説明の初期化メソッド
	void Scene();    //ゲーム説明の実行中メソッド
private:

};
