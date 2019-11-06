//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)」

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#include "SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイル読み込み
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"block.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"field.jpg", 2, TEX_SIZE_512);
	Draw::LoadImage(L"syuriken.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"char_p_ninja012.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"mon.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"kemuridama.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"nawa.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"tokei.jpg", 8, TEX_SIZE_512);
	Draw::LoadImage(L"target.png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"kagidume.jpg",10, TEX_SIZE_512);
	Draw::LoadImage(L"ninzya.png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"hinotama.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"enzyou.png", 13, TEX_SIZE_512);

	//blockオブジェクト作成
	int block_data[10][100] = {
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,1,1,1,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,5,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,1,1,1,1,0,0, 0,0,0,0,0,0,0,0,0,6, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,1,1,1,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,1,1,1,1,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 7,7,7,7,7,7,7,7,7,7, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,1,1,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,3,0,0, 0,0,0,0,0,0,0,0,5,1, 0,0,3,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,1,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1 },
	};

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{	
			/*if (block_data[i][j] == 1) {
				CObjBlock*objb = new CObjBlock(j * 64, i * 64);
				Objs::InsertObj(objb, OBJ_BLOCK, 2);
			}*/
			if (block_data[i][j] == 3)
			{
				CObjEnemy* obje = new CObjEnemy(j * 64, i * 64);
				Objs::InsertObj(obje, OBJ_ENEMY, 6);
			}
			else if (block_data[i][j] == 5) {
				CObjDonden*objd = new CObjDonden(j * 64, i * 64);
				Objs::InsertObj(objd, OBJ_DONDEN, 3);
			}

			else if (block_data[i][j] == 6) {
				CObjNBlock*objn = new CObjNBlock(j * 64, i * 64);
				Objs::InsertObj(objn, OBJ_DONDEN, 3);
			}

			else if (block_data[i][j] == 7) {
				CObjUtikagi*obju = new CObjUtikagi(j * 64, i * 64);
				Objs::InsertObj(obju, OBJ_DONDEN, 3);
			}
		}
	}

	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero(1919, 514);//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 4);

	//Scrollオブジェクト追加
	CObjScroll* obj_s = new CObjScroll(block_data);
	Objs::InsertObj(obj_s, OBJ_SCROLL, 1);


	//Blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(block_data);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}