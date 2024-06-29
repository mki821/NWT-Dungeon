#pragma once
#include <thread>  
#include <io.h>
#include "define.h"
#include "console.h"
#include "GameLogic.h"

enum class MenuType
{
	Game = 0, Quit = 1, None = 2
};

enum class SceneType
{
	Title, Clear, End
};

class Scene
{
public:
	Scene();
public:
	int GameScene(SceneType sceneType, string name);
	MenuType SceneTypeRender( string name);
	void SceneAnimation();
public:
	int ShowScene(SceneType sceneType);
private:
	int selectMenu = 0;
};

