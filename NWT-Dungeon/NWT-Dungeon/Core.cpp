#include <iostream>
#include <fstream>
#include "console.h"
#include "Player.h"
#include "Core.h"

using std::cout;

Core* Core::m_pInstance = nullptr;

bool Core::Init() {
	system("title NWT_DUNGEON | mode con cols=140 lines=40");
	LockResize();
	CursorVisible(false, 1);

	m_player = new Player;
	m_player->Init();

	return true;
}

void Core::Run() {
	while (true) {
		Update();
		Render();
		FrameSync(60);
	}
}

void Core::Update() {
	_select = m_player->ChooseAttack();
}

void Core::Render() {
	#pragma region UIFrame
	GotoXY(4, 20);
	cout << "┌";
	for (int i = 0; i < 129; ++i) {
		cout << "─";
	}
	cout << "┐";
	for (int i = 21; i < 35; ++i) {
		GotoXY(4, i);
		cout << "│";
		GotoXY(134, i);
		cout << "│";
	}
	GotoXY(4, 35);
	cout << "└";
	for (int i = 0; i < 129; ++i) {
		cout << "─";
	}
	cout << "┘";
	#pragma endregion

	memset(_ui, ' ', sizeof(_ui));

	UISet(7, 3, "공격");
	UISet(7, 5, "몸통박치기");
	UISet(4, 3 + 2 * _select, "▶");

	for (int y = 0; y < 14; ++y) {
		GotoXY(6, 21 + y);
		for (int x = 0; x < 128; ++x) {
			cout << _ui[y][x];
		}
	}
}

void Core::FrameSync(int frameRate) {
	clock_t oldTime = clock();
	clock_t curTime;

	while (true) {
		curTime = clock();
		if (curTime - oldTime > 1000 / frameRate) {
			oldTime = curTime;
			break;
		}
	}
}

void Core::UISet(int x, int y, std::string value) {
	for (int i = 0; i < value.length(); ++i) {
		_ui[y][x + i] = value[i];
	}
}
