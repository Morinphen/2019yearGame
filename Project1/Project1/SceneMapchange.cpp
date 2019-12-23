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
CSceneMapchange::CSceneMapchange()
{

}

// デストラクタ
CSceneMapchange::~CSceneMapchange()
{

}

//ゲームメイン初期化メソッド
void CSceneMapchange::InitScene()
{
	//外部オーディオファイル読み込み
	Audio::LoadAudio(0, L"z.wav", SOUND_TYPE::BACK_MUSIC);

	Draw::LoadImage(L"sozai\\gt.png", 0, TEX_SIZE_1024);
	Draw::LoadImage(L"sozai\\jou.png", 1, TEX_SIZE_1024);
	Draw::LoadImage(L"sozai\\mo.png", 2, TEX_SIZE_1024);
	//Font::SetStrTex(L"ニンカツ");

	//マップ切り替えオブジェクト作成
	CObjMapchange* objmc = new CObjMapchange();//マップ切り替えオブジェクト作成
	Objs::InsertObj(objmc, OBJ_MAPCHANGE, 10);//マップ切り替えオブジェクト登録
}

void CSceneMapchange::Scene()
{

}