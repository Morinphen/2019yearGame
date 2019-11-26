//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)」

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include "GameL\UserData.h"
#include"GameL\Audio.h"

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
	//外部オーディオファイル読み込み
	Audio::LoadAudio(0, L"main.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"syuriken.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(2, L"jump.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"dash.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(4, L"donden.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(5, L"fire.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(6, L"gatyan.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(7, L"kaginawa nage.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(8, L"makimono.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(9, L"nezumi.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(10, L"smokeball.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(11, L"syuriken get.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(12, L"utikagi kaginawa.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(13, L"enemyfind.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(14, L"enemyhit.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(15, L"water.wav", SOUND_TYPE::EFFECT);
	//ボリュームを1.5に増やす
	float v = Audio::VolumeMaster(1.5);
	//音楽スタート
	Audio::Start(0);

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
	Draw::LoadImage(L"karakuri.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"syuriken1.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"mode.png", 18, TEX_SIZE_512);
	Draw::LoadImage(L"frame.png", 19, TEX_SIZE_512);
	Draw::LoadImage(L"ninzya1.png", 25, TEX_SIZE_512);

	//blockオブジェクト作成
	/*int block_data[10][100] = {
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,1,1,1,1,0,0, 0,0,0,0,0,0,0,0,0,6, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,1,1,1,1,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,12,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,8,8,8,8,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 7,7,7,7,7,7,7,7,7,7, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,4,4,4,4,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,30,0,0,0,0,0,0,0, 3,0,0,6,6,6,6,0,12,5, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,1,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,1,0,0,0,0,0,0,0, 8,0,0,0,0,5,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 4,4,4,4,4,4,4,4,4,4, 1,1,1,1,1,1,1,1,1,1 },
	};
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,1,1,1,1,0,0, 0,0,0,0,21,21,21,21,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,12,0, 0,0,0,0,0,0,0,0,0,20, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,0, 0,8,8,8,8,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,20, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 7,7,7,7,7,7,7,7,7,7, 0,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,20, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,20, 0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,0,0,0,0,0,0,0,0, 8,0,0,0,0,0,0,0,0,0, 4,4,4,4,4,4,4,4,4,4, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,31,0,0,1, 0,0,0,6,6,6,6,0,12,5, 0,0,0,0,0,0,0,14,0,20, 0,0,0,0,0,0,15,0,0,1, 0,0,0,0,0,0,0,1,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,1,0,0,0,0,0,0,0, 8,0,0,0,0,5,0,31,0,0, 4,4,4,4,4,4,4,4,4,4, 0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,0,0, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,0,0,0,0,0,0,0,0,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 4,4,4,4,4,4,4,4,4,4, 1,1,1,1,1,1,1,1,1,1 },

	};*/

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p;  //ステージ情報のポインター
	int size;               //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"NIN.csv", &size);//外部データ読み込み

	int map[46][100];
	int count = 1;

	//Scrollオブジェクト追加
	CObjScroll* obj_s = new CObjScroll(map);
	Objs::InsertObj(obj_s, OBJ_SCROLL, 1);

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

	int Na = 0;

	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{

	/*		if (map[i][j] == 1) {
			CObjNezublock*objne;

		/*	if (map[i][j] == 1) {
				CObjBlock*objb = new CObjBlock(j * 64, i * 64);
				Objs::InsertObj(objb, OBJ_BLOCK, 2);
			}*/

			if (map[i][j] == 3)
			{
				CObjEnemy* obje = new CObjEnemy(j * 64, i * 64);
				Objs::InsertObj(obje, OBJ_ENEMY, 6);
			}
			else if (map[i][j] == 4)
			{
				CObjMBlock* objm = new CObjMBlock(j * 64, i * 64);
				Objs::InsertObj(objm, OBJ_MIZUBLOCK, 6);
			}

			else if (map[i][j] >=30&& map[i][j] <= 100)
			{
				CObjDonden*objd = new CObjDonden(j * 64, i * 64,map[i][j],false);
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

			else if (map[i][j] == 9)
			{
				CObjTBlock*objt = new CObjTBlock(j * 64, i * 64);
				Objs::InsertObj(objt, OBJ_TURIBLOCK, 3);
			}
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
			else if (map[i][j] == 14)
			{
				CObjExit*objex = new CObjExit(j * 64, i * 64);
				Objs::InsertObj(objex, OBJ_EXIT, 3);
			}
			else if (map[i][j] == 15)
			{
				CObjKarakuri*objk = new CObjKarakuri(j * 64, i * 64, 1);
				Objs::InsertObj(objk, OBJ_KARAKURI, 3);
			}
			else if (map[i][j] == 16)
			{
				CObjKarakuri*objk = new CObjKarakuri(j * 64, i * 64, 2);
				Objs::InsertObj(objk, OBJ_KARAKURI, 3);
			}
			else if (map[i][j] == 17)
			{
				CObjKarakuri*objk = new CObjKarakuri(j * 64, i * 64, 3);
				Objs::InsertObj(objk, OBJ_KARAKURI, 3);
			}


			/*if (block_data[i][j] == 1) {
			CObjBlock*objb = new CObjBlock(j * 64, i * 64);
			Objs::InsertObj(objb, OBJ_BLOCK, 2);
			}*/
			/*if (block_data[i][j] == 3)
			{
				CObjEnemy* obje = new CObjEnemy(j * 64, i * 64);
				Objs::InsertObj(obje, OBJ_ENEMY, 6);
			}
			else if (map[i][j] == 4)
			}*/
			//if (block_data[i][j] == 4)
			//{
			//	CObjMBlock* objm = new CObjMBlock(j * 64, i * 64);
			//	Objs::InsertObj(objm, OBJ_MIZUBLOCK, 6);
			//}

			else if (map[i][j] == 20 || map[i][j] == 21)
			{
				CObjNezublock*objne = new CObjNezublock(j * 64, i * 64, map[i][j]);
				Objs::InsertObj(objne, map[i][j], 3);
			}

			else if (map[i][j] == 26 || map[i][j] == 27)
			{
				CObjNezuana*objn = new CObjNezuana(j * 64, i * 64, map[i][j]);
				Objs::InsertObj(objn, map[i][j], 3);
			}

			else if (map[i][j] >=30&&map[i][j]<=100)
			{
				CObjDonden*objd = new CObjDonden(j * 64, i * 64,map[i][j],false);
				Objs::InsertObj(objd, OBJ_DONDEN, 3);
			}
			

			//else if (map[i][j] == 6) 
			//{
			//	CObjNBlock*objn = new CObjNBlock(j * 64, i * 64);
			//	Objs::InsertObj(objn, OBJ_DONDEN, 3);
			//}

			//else if (map[i][j] == 7)
			//{
			//	CObjUtikagi*obju = new CObjUtikagi(j * 64, i * 64);
			//	Objs::InsertObj(obju, OBJ_DONDEN, 3);

			//}
			//else if (map[i][j] == 8)
			//{
			//	CObjHonoBlock*obju = new CObjHonoBlock(j * 64, i * 64);
			//	Objs::InsertObj(obju, OBJ_HONOBLOCK, 3);
			//}

			//else if (map[i][j] == 9)
			//{
			//	CObjTBlock*objt = new CObjTBlock(j * 64, i * 64);
			//	Objs::InsertObj(objt, OBJ_TURIBLOCK, 3);
			//}
			//else if (map[i][j] == 10)
			//{
			//	CObjUguBlock*objugu = new CObjUguBlock(j * 64, i * 64);
			//	Objs::InsertObj(objugu, OBJ_UGUBLOCK, 3);
			//}
			//else if (map[i][j] == 11)
			//{
			//	CObjOtosiana*objo = new CObjOtosiana(j * 64, i * 64);
			//	Objs::InsertObj(objo, OBJ_OTOSIANA, 3);
			//}
			//else if (map[i][j] == 13)
			//{
			//	CObjMakimono*objma = new CObjMakimono(j * 64, i * 64);
			//	Objs::InsertObj(objma, OBJ_MAKIMONO, 3);
			//}
			//else if (block_data[i][j] == 15)
			//{
			//	CObjKarakuri*objk = new CObjKarakuri(j * 64, i * 64, 1);
			//	Objs::InsertObj(objk, OBJ_KARAKURI, 3);
			//}
			//else if (block_data[i][j] == 16)
			//{
			//	CObjKarakuri*objk = new CObjKarakuri(j * 64, i * 64, 2);
			//	Objs::InsertObj(objk, OBJ_KARAKURI, 3);
			//}
			//else if (block_data[i][j] == 17)
			//{
			//	CObjKarakuri*objk = new CObjKarakuri(j * 64, i * 64, 3);
			//	Objs::InsertObj(objk, OBJ_KARAKURI, 3);
			//}
		}
	}

	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero();//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 4);

	//Blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//手裏剣所持数オブジェクト作成
	CObjPsyuriken*objp= new CObjPsyuriken();//主人公オブジェクト作成
	Objs::InsertObj(objp, OBJ_PSYURIKEN, 10);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}