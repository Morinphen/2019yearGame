#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjRetry :public CObj
{
public:
	CObjRetry(bool map);
	~CObjRetry() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	bool m_key_flag;//キーフラグ
	bool m_posture;//上か下か
	bool m_type;//マップの状態を確認
}; 
