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
	void InitScene();//ゲームクリアの初期化メソッド
	void Scene();    //ゲームクリアの実行中メソッド
private:

}; 
