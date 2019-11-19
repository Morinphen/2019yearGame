//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)」

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include "GameL\UserData.h"

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
	Draw::LoadImage(L"mizu.jpg", 14, TEX_SIZE_512);
	Draw::LoadImage(L"makimono.png", 15, TEX_SIZE_512);

	//blockオブジェクト作成
	/*int block_data[10][100] = {
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,1,1,1,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,5,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0, 0,9,9,9,9,9,9,9,9,9, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,1,1,1,1,0,0, 0,0,0,0,0,0,0,0,0,6, 0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,1,1,1,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,1,1,1,1,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,1,1,1,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,1,1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,1,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,1, 3,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,5,1, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,1,1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,1,1,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,1,11,11,11,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1, 10,10,10,10,10,10,10,10,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 4,4,4,4,4,4,4,4,4,4, 1,1,1,1,1,1,1,1,1,1 },
	};*/

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p;  //ステージ情報のポインター
	int size;               //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"NIN.csv", &size);//外部データ読み込み

	int map[46][100];
	int count = 1;
	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			if (w < 10)
			{
				count += 2;
			}
			else
			{
				count += 3;
			}
		}
	}

	//Scrollオブジェクト追加
	CObjScroll* obj_s = new CObjScroll(map);
	Objs::InsertObj(obj_s, OBJ_SCROLL, 1);

	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{

		/*	if (map[i][j] == 1) {
				CObjBlock*objb = new CObjBlock(j * 64, i * 64);
				Objs::InsertObj(objb, OBJ_BLOCK, 2);
			}*/

			if (map[i][j] == 3)
			{
				CObjEnemy* obje = new CObjEnemy(j * 64, i * 64);
				Objs::InsertObj(obje, OBJ_ENEMY, 6);
			}
			/*else if (map[i][j] == 4)
			{
				CObjMBlock* objm = new CObjMBlock(j * 64, i * 64);
				Objs::InsertObj(objm, OBJ_MIZUBLOCK, 6);
			}*/

			else if (map[i][j] == 5)
			{
				CObjDonden*objd = new CObjDonden(j * 64, i * 64,false);
				Objs::InsertObj(objd, OBJ_DONDEN, 3);
			}
			

			else if (map[i][j] == 6) 
			{
				CObjNBlock*objn = new CObjNBlock(j * 64, i * 64);
				Objs::InsertObj(objn, OBJ_DONDEN, 3);
			}

			else if (map[i][j] == 7)
			{
				CObjUtikagi*obju = new CObjUtikagi(j * 64, i * 64);
				Objs::InsertObj(obju, OBJ_DONDEN, 3);

			}
			else if (map[i][j] == 8)
			{
				CObjHonoBlock*obju = new CObjHonoBlock(j * 64, i * 64);
				Objs::InsertObj(obju, OBJ_HONOBLOCK, 3);
			}

			/*else if (map[i][j] == 9)
			{
				CObjTBlock*objt = new CObjTBlock(j * 64, i * 64);
				Objs::InsertObj(objt, OBJ_TURIBLOCK, 3);
			}*/
			else if (map[i][j] == 10)
			{
				CObjUguBlock*objugu = new CObjUguBlock(j * 64, i * 64);
				Objs::InsertObj(objugu, OBJ_UGUBLOCK, 3);
			}
			else if (map[i][j] == 11)
			{
				CObjOtosiana*objo = new CObjOtosiana(j * 64, i * 64);
				Objs::InsertObj(objo, OBJ_OTOSIANA, 3);
			}
			else if (map[i][j] == 13)
			{
				CObjMakimono*objma = new CObjMakimono(j * 64, i * 64);
				Objs::InsertObj(objma, OBJ_MAKIMONO, 3);
			}


			/*if (block_data[i][j] == 1) {
			CObjBlock*objb = new CObjBlock(j * 64, i * 64);
			Objs::InsertObj(objb, OBJ_BLOCK, 2);
			}*/
			/*if (block_data[i][j] == 3)
			{
				CObjEnemy* obje = new CObjEnemy(j * 64, i * 64);
				Objs::InsertObj(obje, OBJ_ENEMY, 6);
			}*/
			/*if (block_data[i][j] == 4)
			{
				CObjMBlock* objm = new CObjMBlock(j * 64, i * 64);
				Objs::InsertObj(objm, OBJ_MIZUBLOCK, 6);
			}
			else if (block_data[i][j] == 5)
			{
				CObjDonden*objd = new CObjDonden(j * 64, i * 64, false);
				Objs::InsertObj(objd, OBJ_DONDEN, 3);
			}

			else if (block_data[i][j] == 6)
			{
				CObjNBlock*objn = new CObjNBlock(j * 64, i * 64);
				Objs::InsertObj(objn, OBJ_NBLOCK, 3);
			}

			else if (block_data[i][j] == 7)
			{
				CObjUtikagi*obju = new CObjUtikagi(j * 64, i * 64);
				Objs::InsertObj(obju, OBJ_UTIKAGI, 3);
			}

			else if (block_data[i][j] == 8)
			{
				CObjHonoBlock*obju = new CObjHonoBlock(j * 64, i * 64);
				Objs::InsertObj(obju, OBJ_HONOBLOCK, 3);
			}

			else if (block_data[i][j] == 9)
			{
				CObjTBlock*objt = new CObjTBlock(j * 64, i * 64);
				Objs::InsertObj(objt, OBJ_TURIBLOCK, 3);
			}
			else if (block_data[i][j] == 10)
			{
				CObjUguBlock*objugu = new CObjUguBlock(j * 64, i * 64);
				Objs::InsertObj(objugu, OBJ_UGUBLOCK, 3);
			}
			else if (block_data[i][j] == 11)
			{
				CObjOtosiana*objo = new CObjOtosiana(j * 64, i * 64);
				Objs::InsertObj(objo, OBJ_OTOSIANA, 3);
			}

			else if (block_data[i][j] == 12)
			{
				CObjDonden*objd = new CObjDonden(j * 64, i * 64, true);
				Objs::InsertObj(objd, OBJ_DONDEN, 3);
			}*/
		}
	}

	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero();//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 4);

	//Blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}