//STLデバッグ機能をOFFにする
#define _SECURE_SCL (O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"

//使用するネームスぺース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneRetry::CSceneRetry()
{

}

// デストラクタ
CSceneRetry::~CSceneRetry()
{

}

//ゲームメイン初期化メソッド
void CSceneRetry::InitScene()
{
	Draw::LoadImage(L"retry.png", 0, TEX_SIZE_1024);
	Draw::LoadImage(L"ka.png", 1, TEX_SIZE_512);
	Font::SetStrTex(L"ニンカツ");
	//外部オーディオファイル読み込み
	Audio::LoadAudio(0, L"gameover.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0.5);
	v = Audio::VolumeMaster((1.0 - v));

	Audio::Start(0);

	//リトライオブジェクト作成
	CObjRetry* obj = new CObjRetry();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_RETRY, 10);//主人公オブジェクト登録
}

void CSceneRetry::Scene()
{

}