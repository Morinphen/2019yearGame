//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"kanban.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjkanban::CObjkanban(int x, int y, int t)
{
	m_x = x;
	m_y = y;
	type = t;
}

//イニシャライズ
void CObjkanban::Init()
{
	num = 0.0f;
	flashing = false;
}

//アクション
void CObjkanban::Action()
{

}

//ドロー
void CObjkanban::Draw()
{

}