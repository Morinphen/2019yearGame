#pragma once
//ウィンドウサイズ
#define WINDOW_SIZE_W	(1200)
#define WINDOW_SIZE_H	(900)
//解像度サイズ
#define PIXEL_SIZE_W	(1200)
#define PIXEL_SIZE_H	(900)
//一つのシーンで読み込めるグラフィック総数
#define SCENE_IMG_MAX	(70)
//一つのシーンで読み込める音楽総数
#define SCENE_AUDIO_MAX	(32)
//バックグラウンド色
#define BACK_COLOR      {0.0f, 0.0f, 0.0f, 1.0f}

//ウィンドウゲームタイトル名
#define GAME_NAME L"ライブラリ"

//ゲームパッド用宣言
#pragma comment(lib,"xinput.lib")
#include<Windows.h>
#include<Xinput.h>
#define XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE  32000