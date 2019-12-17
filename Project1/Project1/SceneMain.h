#pragma once
#include "GameL\SceneManager.h"

using namespace GameL;

class CSceneMain:public CScene
{
public:
	CSceneMain(bool b);
	~CSceneMain();
	void InitScene();
	void Scene();
private:
	bool maptype;
};