#pragma once
//使用するヘッダファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneRetry :public CScene
{
public:
	CSceneRetry(bool map);
	~CSceneRetry();
	void InitScene();//ゲームリトライの初期化メソッド
	void Scene();    //ゲームリトライの実行中メソッド
private:
	bool m_type;//マップの状態を確認

};
