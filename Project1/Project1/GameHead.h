#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_SYURIKEN,
	OBJ_SCROLL,
	OBJ_DONDEN,
	OBJ_SMOKEBALL,
	OBJ_ENEMY,
	OBJ_KAGINAWA,
	OBJ_NAGENAWA,
	OBJ_NBLOCK,
	OBJ_UTIKAGI,
	OBJ_HINOTAMA,
	OBJ_HONOBLOCK,
	OBJ_MIZUBLOCK,
	OBJ_TURIBLOCK,
	OBJ_TURIBLOCK2,
	OBJ_UGUBLOCK,
	OBJ_OTOSIANA,
	OBJ_MAKIMONO,
	OBJ_HAMUTARO,
	OBJ_KARAKURI,
	OBJ_DSYURIKEN,
	OBJ_PSYURIKEN,
	OBJ_TITLE,
	OBJ_GAMEOVER,
	OBJ_RETRY,
	OBJ_CLEAR,
	OBJ_EXIT,
	OBJ_NEZUANA,
	OBJ_NEZUBLOCK,
	OBJ_KARAKURIBLOCK,
	OBJ_SETUMEI,
	OBJ_FIREENEMY,
	OBJ_HAMENEMY,
	OBJ_MUSCLEENEMY,
	OBJ_KANBAN
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"Hero.h"
#include"Block.h"
#include"syuriken.h"
#include"Scroll.h"
#include"Dondengaesi.h"
#include"smokeball.h"
#include"ObjEnemy.h"
#include"Kaginawa.h"
#include"Nagenawa.h"
#include"NawaBlock.h"
#include"Utikagi.h"
#include"Hinotama.h"
#include"HonoBlock.h"
#include"MizuBlock.h"
#include"TuriBlock.h"
#include"UguBlock.h"
#include"Otosiana.h"
#include"Makimono.h"
#include"Hamutaro.h"
#include"Karakuri.h"
#include"Psyuriken.h"
#include"Dsyuriken.h"
#include"HamEnemy.h"
#include"Fireenemy.h"
#include"MuscleEnemy.h"
#include"kanban.h"

#include"ObjTitle.h"
#include"ObjGameOver.h"
#include"ObjRetry.h"
#include"ObjClear.h"
#include"Objsetumei.h"
#include"Exit.h"
#include"Nezuana.h"
#include"NezuBlock.h"
#include"KarakuriBlock.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneMain.h"
#include"SceneTitle.h"
#include"SceneGameOver.h"
#include"SceneRetry.h"
#include"SceneClear.h"
#include"Scenesetumei.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//#define SET_GAME_START  
//-----------------------------------------------