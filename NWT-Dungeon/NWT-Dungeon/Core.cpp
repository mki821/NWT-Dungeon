#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <io.h>
#include "console.h"
#include "define.h"
#include "Player.h"
#include "Core.h"

using std::wcout;

Core* Core::m_pInstance = nullptr;

bool Core::Init() {
	system("title NWT_DUNGEON | mode con cols=140 lines=40");
	LockResize();
	CursorVisible(false, 1);
	_setmode(_fileno(stdout), _O_U16TEXT);		

	for (int i = 0; i < 3; ++i) {
		Player* player = new Player;
		player->Init();
		m_players.push_back(player);
	}

	for (int i = 0; i < 1; ++i) {
		Enemy* enemy = new Enemy;
		enemy->Init();
		m_enemies.push_back(enemy);
	}

	m_currentTurn = TURN::SELECTPLAYER;
	_lastSelectTime = clock();

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
	switch (m_currentTurn) {
		case TURN::SELECTPLAYER: {
			ChooseIndex(0, 2);
			if (_select == -1) {
				m_selectedPlayer = m_players[_finalSelect];
				_select = 0;
				_finalSelect = 0;
				m_currentTurn = TURN::SELECTENEMY;
			}
		}
		break;
		case TURN::SELECTENEMY: {
			ChooseIndex(0, 2);
			if (_select == -1) {
				//m_selectedPlayer->SetTarget(m_enemies[_finalSelect]);
				_select = 0;
				_finalSelect = 0;
				m_currentTurn = TURN::SELECTSKILL;
			}
		}
		break;
		case TURN::SELECTSKILL: {
			ChooseIndex(0, 1, false);
			if (_select == -1) {
				m_selectedPlayer->Attack((PlayerSkillEnum)_finalSelect);
				_select = 0;
				_finalSelect = 0;
				m_currentTurn = TURN::SELECTPLAYER;
			}
		}
		break;
		case TURN::ENEMYATTACK:
			break;
	}
}

void Core::Render() {
	GameRender();
	UIRender();
}

void Core::GameRender() {
	for (int i = 0; i < m_players.size(); ++i) {
		if (m_currentTurn == TURN::SELECTPLAYER) {
			if (_finalSelect == i) SetColor((int)Color::Red);
			CharacterRender(10 + 20 * i, 18, m_players[i]);
			if (_finalSelect == i) SetColor((int)Color::White);
		}
		else {
			if (m_players[i] == m_selectedPlayer) SetColor((int)Color::Red);
			CharacterRender(10 + 20 * i, 18, m_players[i]);
			if (m_players[i] == m_selectedPlayer) SetColor((int)Color::White);
		}
	}
	for (int i = 0; i < m_enemies.size(); ++i) {
		CharacterRender(78 + 20 * i, 18, m_enemies[i]);
	}
}

void Core::CharacterRender(int x, int y, Character* _character) {
	std::wstring* character = _character->GetCharacter();
	int size = _character->GetCharacterSize();

	GotoXY(x + 3, y - 1);
	wcout << "Health: " << _character->GetHealth();
	GotoXY(x + 3, y);
	wcout << "Stamina: " << _character->GetStamina();

	for (int i = size - 1; i >= 0; --i) {
		GotoXY(x, y - size + i - 2);
		wcout << character[i];
	}
}

void Core::UIRender() {
	#pragma region UIFrame
	GotoXY(4, 20);
	wcout << "┌";
	for (int i = 0; i < 129; ++i) {
		wcout << "─";
	}
	wcout << "┐";
	for (int i = 21; i < 35; ++i) {
		GotoXY(4, i);
		wcout << "│";
		GotoXY(134, i);
		wcout << "│";
	}
	GotoXY(4, 35);
	wcout << "└";
	for (int i = 0; i < 129; ++i) {
		wcout << "─";
	}
	wcout << "┘";
	#pragma endregion

	memset(_ui, ' ', sizeof(_ui));

	UISet(7, 3, "공격");
	UISet(7, 5, "몸통박치기");

	if(m_currentTurn == TURN::SELECTSKILL)
		UISet(4, 3 + 2 * _select, "▶");

	for (int y = 0; y < 14; ++y) {
		GotoXY(6, 21 + y);
		for (int x = 0; x < 128; ++x) {
			wcout << _ui[y][x];
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

void Core::ChooseIndex(int min, int max, bool horizontal) {
	if (clock() - _lastSelectTime > 100) {
		_lastSelectTime = clock();
	}
	else return;

	if (horizontal) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) --_select;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) ++_select;
	}
	else {
		if (GetAsyncKeyState(VK_UP) & 0x8000) --_select;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) ++_select;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		_select = -1;
		return;
	}

	if (_select < min) _select = min;
	else if (_select > max) _select = max;

	_finalSelect = _select;
}
