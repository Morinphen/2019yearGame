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
CSceneClear::CSceneClear()
{

}

// デストラクタ
CSceneClear::~CSceneClear()
{

}

//ゲームメイン初期化メソッド
void CSceneClear::InitScene()
{
	Draw::LoadImage(L"sozai\\clear.png", 0, TEX_SIZE_1024);
	Font::SetStrTex(L"ニンカツ");
	//外部オーディオファイル読み込み

	Audio::LoadAudio(0, L"music\\gameclear.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"music\\titleselect.wav", SOUND_TYPE::EFFECT);
	float v = Audio::VolumeMaster(-0.5);
	v = Audio::VolumeMaster((1.0 - v));
	v = Audio::VolumeMaster(-0.5);
	Audio::Start(0);

	//クリアオブジェクト作成
	CObjClear* obj = new CObjClear();//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_CLEAR, 10);//クリアオブジェクト登録
}

void CSceneClear::Scene()
{

}