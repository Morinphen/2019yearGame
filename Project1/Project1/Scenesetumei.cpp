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
CScenesetumei::CScenesetumei()
{

}

// デストラクタ
CScenesetumei::~CScenesetumei()
{

}

//ゲームメイン初期化メソッド
void CScenesetumei::InitScene()
{
	Draw::LoadImage(L"sozai\\setumei.png", 0, TEX_SIZE_1024);
	Font::SetStrTex(L"ニンカツ");
	//外部オーディオファイル読み込み

	Audio::LoadAudio(0, L"music\\setumei.wav", SOUND_TYPE::BACK_MUSIC);

	float v = Audio::VolumeMaster(-0.5);
	v = Audio::VolumeMaster((1.0 - v));
	v = Audio::VolumeMaster(-0.5);
	Audio::Start(0);

	CObjsetumei* obj = new CObjsetumei();//説明オブジェクト作成
	Objs::InsertObj(obj, OBJ_SETUMEI, 10);//説明オブジェクト登録
}

void CScenesetumei::Scene()
{

}