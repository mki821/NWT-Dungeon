#include "Scene.h"

Scene::Scene()
{
}

void SceneRender(SceneType sceneType)
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < 8; ++i)
	{
		GotoXY(11, i + 4);
		wcout << MainTitle[static_cast<int>(sceneType)][i];	
	}
	int currmode = _setmode(_fileno(stdout), prevmode);
}

int Scene::GameScene(SceneType sceneType,string name)		
{
	SceneRender(sceneType);

	while (true)
	{
		MenuType eMenuType = SceneTypeRender(name);	
		switch (eMenuType)
		{
		case MenuType::Game:
			return 0;
		case MenuType::Quit:
			return 1;
		}
	}
}

MenuType Scene::SceneTypeRender(string name)
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2.2;
	int y = Resolution.Y / 2;
	int origin = y;

	GotoXY(x, y);
	cout << name;
	GotoXY(x, y + 2);
	cout << "던전 탈출" << endl;

	if (ChooseIndex(0, 1, false, selectMenu)) {
		return static_cast<MenuType>(selectMenu);
	}
	else {
		if (selectMenu == 0) {
			GotoXY(x - 3, y);
			cout << "▶";
			GotoXY(x - 3, y + 2);
			cout << "  ";
		}
		else {
			GotoXY(x - 3, y);
			cout << "  ";
			GotoXY(x - 3, y + 2);
			cout << "▶";
		}
	}

	return MenuType::None;
}

void Scene::SceneAnimation()
{
	COORD Resolution = GetConsoleResolution();
	int width = Resolution.X;
	int height = Resolution.Y;
	int animtime = 20;

	for (int i = 0; i < 5; i++)
	{
		GotoXY(0, 0);
		SetColor((int)Color::Black, (int)Color::White);
		system("cls");
		Sleep(animtime);

		GotoXY(0, 0);
		SetColor((int)Color::White);
		system("cls");
		Sleep(animtime);
	}

	SetColor((int)Color::Black, (int)Color::White);
	for (int i = 0; i < width * 0.5f; i++) {
		for (int j = 0; j < height; j += 2) {
			GotoXY(i * 2, j);
			cout << "  ";
		}
		for (int j = 1; j < height; j += 2) {
			GotoXY(width - 2 - i * 2, j);
			cout << "  ";
		}
		Sleep(animtime);
	}
	SetColor((int)Color::White);
	system("cls");
}

int Scene::ShowScene(SceneType sceneType)	
{
	switch (sceneType)
	{
	case SceneType::Title:	
		return GameScene(sceneType, "던전 입장");
	case SceneType::Clear:	
		return GameScene(sceneType, "던전 재입장");
	case SceneType::End:	
		return GameScene(sceneType, "던전 재도전");
	default:
		break;
	}
}
