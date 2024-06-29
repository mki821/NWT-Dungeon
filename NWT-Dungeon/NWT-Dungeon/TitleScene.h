#pragma once
#include "define.h"
#include "console.h"
#include "GameLogic.h"
#include "Scene.h"

enum class MenuType
{
	Start = 0, Info = 1, Quit = 2
};

class TitleScene
{
public:
	TitleScene();	
public:
	bool Title();
	MenuType MenuTypeRender();		
	void SceneAnimation();
private:
	int selectMenu = 0;
};

