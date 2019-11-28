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
CSceneGameOver::CSceneGameOver()
{

}

// デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//ゲームメイン初期化メソッド
void CSceneGameOver::InitScene()
{
	Draw::LoadImage(L"GameOver.png", 0, TEX_SIZE_1024);
	Font::SetStrTex(L"ニンカツ");
	//外部オーディオファイル読み込み
	Audio::LoadAudio(0, L"gameover.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0);
	v=Audio::VolumeMaster((1.0-v));

	Audio::Start(0);

	//ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);//主人公オブジェクト登録
}

void CSceneGameOver::Scene()
{

}