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
CSceneTitle::CSceneTitle()
{

}

// デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	Draw::LoadImage(L"title.png", 0, TEX_SIZE_1024);
	Font::SetStrTex(L"ニンカツ");
	//外部オーディオファイル読み込み
	Audio::LoadAudio(0, L"title.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"titleselect.wav", SOUND_TYPE::EFFECT);
	//バックミュージックスタート
	float v = Audio::VolumeMaster(-0.4);
	v = Audio::VolumeMaster((1.0 - v));
	v = Audio::VolumeMaster(-0.4);
	Audio::Start(0);

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10);//主人公オブジェクト登録
}

void CSceneTitle::Scene()
{

}