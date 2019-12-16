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
	Audio::LoadAudio(16, L"matti.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(17, L"key-drop1.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(18, L"sword-slash4.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(19, L"sadou.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(20, L"change.wav", SOUND_TYPE::EFFECT);
	//ボリュームを1.5に増やす
	float v = Audio::VolumeMaster(-0.5);
	v = Audio::VolumeMaster((1.0 - v));
	v = Audio::VolumeMaster(-0.5);
	//音楽スタート
	Audio::Start(0);

	//外部グラフィックファイル読み込み
	Draw::LoadImage(L"Zimen_t.jpg", 1, TEX_SIZE_512);
	Draw::LoadImage(L"Kabe2.jpg", 2, TEX_SIZE_512);
	Draw::LoadImage(L"Syuriken.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"char_p_ninja012.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"Donden.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"smokeball.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"nawa.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Kaginawablock.png", 8, TEX_SIZE_512);
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
	Draw::LoadImage(L"kaginawa.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"ninzya1.png", 21, TEX_SIZE_512);
	Draw::LoadImage(L"Zimen_y.jpg", 22, TEX_SIZE_512);
	Draw::LoadImage(L"Moemasu.jpg", 23, TEX_SIZE_512);
	Draw::LoadImage(L"uguisu.png", 24, TEX_SIZE_512);
	Draw::LoadImage(L"nezuana.png", 25, TEX_SIZE_512);
	Draw::LoadImage(L"turi.png", 26, TEX_SIZE_512);
	Draw::LoadImage(L"goal.png", 27, TEX_SIZE_512);
	Draw::LoadImage(L"sikaku.png", 28, TEX_SIZE_512);
	Draw::LoadImage(L"kemuri.png", 29, TEX_SIZE_1024);
	Draw::LoadImage(L"nezumi.png", 30, TEX_SIZE_512);
	Draw::LoadImage(L"makimo_a.png", 31, TEX_SIZE_512);
	Draw::LoadImage(L"mode_back.jpg", 32, TEX_SIZE_512);
	Draw::LoadImage(L"magic.png", 33, TEX_SIZE_1024);
	Draw::LoadImage(L"haken.png", 34, TEX_SIZE_512);
	Draw::LoadImage(L"km.png", 35, TEX_SIZE_512);
	Draw::LoadImage(L"botan.png", 36, TEX_SIZE_512);
	Draw::LoadImage(L"botan2.png", 37, TEX_SIZE_512);
	Draw::LoadImage(L"modebotan.png", 38, TEX_SIZE_512);
	Draw::LoadImage(L"minimap.png", 39, TEX_SIZE_512);
	Draw::LoadImage(L"floor.png", 40, TEX_SIZE_512);
	Draw::LoadImage(L"hatena.png", 41, TEX_SIZE_512);
	Draw::LoadImage(L"sousa.png", 42, TEX_SIZE_512);
	Draw::LoadImage(L"fire.png", 43, TEX_SIZE_512);
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p;  //ステージ情報のポインター
	int size;               //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"NIN2.csv", &size);//外部データ読み込み

	//unique_ptr<wchar_t> p2;  //ステージ情報のポインター
	//int size2;               //ステージ情報の大きさ
	//p2 = Save::ExternalDataOpen(L"NIN2.csv", &size2);//外部データ読み込み

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

	//int map2[46][100];
	//int count2 = 1;

	//for (int i = 0; i < 46; i++)
	//{
	//	for (int j = 0; j < 100; j++)
	//	{
	//		int w2 = 0;
	//		swscanf_s(&p2.get()[count2], L"%d", &w2);

	//		map2[i][j] = w2;
	//		if (w2 < 10)
	//		{
	//			count2 += 2;
	//		}
	//		else
	//		{
	//			count2 += 3;
	//		}
	//	}
	//}

	//Scrollオブジェクト追加
	CObjScroll* obj_s = new CObjScroll(map);
	Objs::InsertObj(obj_s, OBJ_SCROLL, 1);

	int Na = 0;

	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 81 || map[i][j] == 82)
			{
				CObjEnemy* objne = new CObjEnemy(j * 64, i * 64);
				Objs::InsertObj(objne, OBJ_ENEMY, 6);
				
				if (map[i][j] == 82)
				{
					CObjEnemy* en = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
					en->Setestop(true);
				}
			}
			else if (map[i][j] == 83 || map[i][j] == 84)
			{
				CObjFireEnemy* objfe = new CObjFireEnemy(j * 64, i * 64);
				Objs::InsertObj(objfe, OBJ_FIREENEMY, 6);
				
				if (map[i][j] == 84)
				{
					CObjFireEnemy* fen = (CObjFireEnemy*)Objs::GetObj(OBJ_FIREENEMY);
					fen->Setfestop(true);
					fen->Setm_p(1.0);
					fen->Setm_m(false);
				}
			}
			else if(map[i][j] == 85|| map[i][j] == 86)
			{
				CObjHamEnemy* obje = new CObjHamEnemy(j * 64, i * 64);
				Objs::InsertObj(obje, OBJ_HAMENEMY, 6);
				CObjHamEnemy* hen = (CObjHamEnemy*)Objs::GetObj(OBJ_HAMENEMY);
				//左向き
				if (map[i][j] == 85)
				{
					hen->SetM_P(1.0);
				}
				//右向き
				else
				{
					hen->SetM_P(0.0);
				}
			}
			else if (map[i][j] == 87 || map[i][j] == 88)
			{
				CObjMuscleEnemy* obje = new CObjMuscleEnemy(j * 64, i * 64);
				Objs::InsertObj(obje, OBJ_MUSCLEENEMY, 6);
				CObjMuscleEnemy* men = (CObjMuscleEnemy*)Objs::GetObj(OBJ_MUSCLEENEMY);
				//右向き
				if (map[i][j] == 87)
				{
					men->SetM_P(1.0);
				}
				//左向き
				else
				{
					men->SetM_P(0.0);
				}
			}
			else if (map[i][j] == 4)
			{
				CObjMBlock* objm = new CObjMBlock(j * 64, i * 64);
				Objs::InsertObj(objm, OBJ_MIZUBLOCK, 6);
			}

			else if (map[i][j] >=30&& map[i][j] <= 50)
			{
				CObjDonden*objd = new CObjDonden(j * 64, i * 64,map[i][j],false);
				Objs::InsertObj(objd, OBJ_DONDEN, 3);
			}

			else if (map[i][j] == 12)
			{
				CObjDonden*objd = new CObjDonden(j * 64, i * 64, map[i][j], true);
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
			else if (map[i][j] == 60|| map[i][j] == 61|| map[i][j] == 62)
			{
				CObjKarakuri*objk = new CObjKarakuri(j * 64, i * 64, map[i][j]);
				Objs::InsertObj(objk, map[i][j], 3);
			}
			else if (map[i][j] == 63 || map[i][j] == 64 || map[i][j] == 65)
			{
				CObjKarakuriblock*objk = new CObjKarakuriblock(j * 64, i * 64, map[i][j]);
				Objs::InsertObj(objk, map[i][j], 3);
			}
			else if (map[i][j] == 51 || map[i][j] == 52||map[i][j]==53)
			{
				CObjNezublock*objne = new CObjNezublock(j * 64, i * 64, map[i][j]);
				Objs::InsertObj(objne, map[i][j], 3);
			}
			else if (map[i][j] == 57 || map[i][j] == 58||map[i][j]==59)
			{
				CObjNezuana*objn = new CObjNezuana(j * 64, i * 64, map[i][j]);
				Objs::InsertObj(objn, map[i][j], 3);
			}
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