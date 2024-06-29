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
		GotoXY(11, i + 4);
		wcout << MainTitle[i];
	}
	int currmode = _setmode(_fileno(stdout), prevmode);
}

bool TitleScene::Title()
{
	TitleRender();

	while (true)
	{
		MenuType eMenuType = MenuTypeRender();
		switch (eMenuType)
		{
		case MenuType::Start:
			return true;
		case MenuType::Quit:
			return false;
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
	GotoXY(x, y + 2);
	cout << "게임 종료" << endl;

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
