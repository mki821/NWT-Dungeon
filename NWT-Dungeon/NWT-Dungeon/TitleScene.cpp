#include <io.h>
#include "TitleScene.h"

TitleScene::TitleScene()
{
}

void TitleRender()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < 8; ++i)
	{
		GotoXY(2, i);
		wcout << MainTitle[i];
	}
	int currmode = _setmode(_fileno(stdout), prevmode);
}

int TitleScene::Title()
{
	TitleRender();

	while (true)
	{
		MenuType eMenuType = MenuTypeRender();
		switch (eMenuType)
		{
		case MenuType::Start:
			return 0;
			break;
		case MenuType::Quit:
			return 1;
			break;
		}
	}
}

MenuType TitleScene::MenuTypeRender()	
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2.2;
	int y = Resolution.Y / 2;
	int origin = y;

	GotoXY(x, y);
	cout << "게임 시작";
	GotoXY(x, y + 1);
	cout << "게임 종료" << endl;

	if (ChooseIndex(y, y + 1, false, selectMenu)) {
		return static_cast<MenuType>(selectMenu - y);
	}
	else {
		if (selectMenu > origin) {
			GotoXY(x - 2, origin);
			cout << " ";
		}
		else if (selectMenu == origin) {
			GotoXY(x - 2, origin + 1);
			cout << " ";
		}
	}

	GotoXY(x - 2, selectMenu);
	cout << "▶";

	return MenuType::Info;
}

void TitleScene::SceneAnimation()
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
