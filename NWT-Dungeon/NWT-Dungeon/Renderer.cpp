#include <fcntl.h>
#include <io.h>
#include "console.h"
#include "Character.h"
#include "Renderer.h"

void Renderer::Render() {
	GameRender();
	UIRender();
}

void Renderer::GameRender() {
	for (int i = 0; i < m_players.size(); ++i) {
		if(m_selectedPlayer == nullptr) {
			if (m_select == i) SetColor((int)Color::Red);
			CharacterRender(6 + 20 * i, 18, m_players[i]);
		}
		else {
			if (m_players[i] == m_selectedPlayer) SetColor((int)Color::Red);
			CharacterRender(6 + 20 * i, 18, m_players[i]);
		}
		SetColor((int)Color::White);
	}

	for (int i = 0; i < m_enemies.size(); ++i) {
		if (m_selectedPlayer == nullptr || m_selectedPlayer->GetTarget() == nullptr) {
			if (m_select == i) SetColor((int)Color::Red);
			CharacterRender(68 + 23 * i, 18, m_enemies[i]);
		}
		else {
			if (m_selectedPlayer != nullptr && m_selectedPlayer->GetTarget() != nullptr) {
				if (m_enemies[i] == m_selectedPlayer->GetTarget()) SetColor((int)Color::Red);
				CharacterRender(68 + 23 * i, 18, m_enemies[i]);
			}
			else
				CharacterRender(68 + 23 * i, 18, m_enemies[i]);
		}
		SetColor((int)Color::White);
	}
}

void Renderer::CharacterRender(int x, int y, Character* _character) {
	std::wstring* character = _character->GetCharacter();
	int size = _character->GetCharacterSize();

	GotoXY(x + 3, y - 1);
	wcout << "Health: " << _character->GetHealth() << " ";
	GotoXY(x + 3, y);
	wcout << "Stamina: " << _character->GetStamina() << " ";

	for (int i = size - 1; i >= 0; --i) {
		GotoXY(x, y - size + i - 2);
		wcout << character[i];
	}
}

void Renderer::UIRender() {
	int prevmode = _setmode(_fileno(stdout), _O_TEXT);

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

	if (m_selectedPlayer != nullptr && m_selectedPlayer->GetTarget() != nullptr)
		UISet(4, 3 + 2 * m_select, "▶");
	else UISet(4, 3, "▶");

	for (int y = 0; y < 14; ++y) {
		GotoXY(6, 21 + y);
		for (int x = 0; x < 128; ++x) {
			wcout << _ui[y][x];
		}
	}

	int newmode = _setmode(_fileno(stdout), prevmode);
}

void Renderer::UISet(int x, int y, std::string value) {
	for (int i = 0; i < value.length(); ++i) {
		_ui[y][x + i] = value[i];
	}
}

void Renderer::Init(vector<Player*> players, Player*& playerRef, vector<Enemy*> enemies) {
	m_players = players;
	m_selectedPlayer = playerRef;

	m_enemies = enemies;
}
