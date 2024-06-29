#pragma once
#include "define.h"
#include "console.h"
#include "GameLogic.h"
#include "Scene.h"

enum class MenuType
{
	Start = 0, Quit = 1, Info = 2
};

class TitleScene
{
public:
	TitleScene();		
public:
	int Title();	
	MenuType MenuTypeRender();		
	void SceneAnimation();
private:
	int selectMenu = 0;
};

