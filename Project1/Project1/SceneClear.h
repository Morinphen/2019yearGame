#pragma once
//使用するヘッダファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneClear :public CScene
{
public:
	CSceneClear();
	~CSceneClear();
	void InitScene();//ゲームタイトルの初期化メソッド
	void Scene();    //ゲームタイトルの実行中メソッド
private:

}; 
