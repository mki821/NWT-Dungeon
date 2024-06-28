#include <fcntl.h>
#include <io.h>
#include "console.h"
#include "Character.h"
#include "Renderer.h"

void Renderer::Init(vector<Player*>* players, Player** selectedPlayer, vector<Enemy*>* enemies) {
	m_players = players;
	m_selectedPlayer = selectedPlayer;

	m_enemies = enemies;
}

void Renderer::Render() {
	GameRender();
	UIRender();
}

void Renderer::GameRender() {

	for (int i = 0; i < m_players->size(); ++i) {
		if (*m_selectedPlayer == nullptr && select == i) {
			SetColor((int)Color::Red);
			CharacterRender(6 + 20 * i, 21, (*m_players)[i]);
		}
		else if ((*m_players)[i]->isAttacked) {
			SetColor((int)Color::Blue);
			CharacterRender(6 + 20 * i, 21, (*m_players)[i]);
		}
		else {
			if ((*m_players)[i] == *m_selectedPlayer) SetColor((int)Color::Red);
			CharacterRender(6 + 20 * i, 21, (*m_players)[i]);
		}
		SetColor((int)Color::White);
	}

	for (int i = 0; i < m_enemies->size(); ++i) {
		if (*m_selectedPlayer != nullptr && (*m_selectedPlayer)->GetTarget() == nullptr) {
			if (select == i) SetColor((int)Color::Red);
			CharacterRender(68 + 23 * i, 21, (*m_enemies)[i]);
		}
		else {
			if (*m_selectedPlayer != nullptr && (*m_selectedPlayer)->GetTarget() != nullptr) {
				if ((*m_enemies)[i] == (*m_selectedPlayer)->GetTarget()) SetColor((int)Color::Red);
				CharacterRender(68 + 23 * i, 21, (*m_enemies)[i]);
			}
			else
				CharacterRender(68 + 23 * i, 21, (*m_enemies)[i]);
		}
		SetColor((int)Color::White);
	}
}

void Renderer::CharacterRender(int _x, int _y, Character* _character) {
	std::wstring* character = _character->GetCharacter();
	int size = _character->GetCharacterSize();

	GotoXY(_x + 3, _y - 1);
	wcout << "Health: " << _character->GetHealth() << " ";
	GotoXY(_x + 3, _y);
	wcout << "Stamina: " << _character->GetStamina() << " ";

	int x = _x - _character->GetCharacterOffset();
	int y = _y - size - 2;
	for (int i = size - 1; i >= 0; --i) {
		int d = _y + i;
		GotoXY(x, y + i);
		wcout << character[i];
	}
}

void Renderer::UIRender() {
	int prevmode = _setmode(_fileno(stdout), _O_TEXT);

	#pragma region UIFrame
	GotoXY(4, 23);
	wcout << "¦£";
	for (int i = 0; i < 129; ++i) {
		wcout << "¦¡";
	}
	wcout << "¦¤";
	for (int i = 24; i < 38; ++i) {
		GotoXY(4, i);
		wcout << "¦¢";
		GotoXY(134, i);
		wcout << "¦¢";
	}
	GotoXY(4, 38);
	wcout << "¦¦";
	for (int i = 0; i < 129; ++i) {
		wcout << "¦¡";
	}
	wcout << "¦¥";
	#pragma endregion

	memset(_ui, ' ', sizeof(_ui));

	vector<PlayerSkill>* selectedPlayerSkills = (*m_players)[select]->GetSkills();

	if(*m_selectedPlayer != nullptr)
		selectedPlayerSkills = (*m_selectedPlayer)->GetSkills();

	for (int i = 0; i < selectedPlayerSkills->size(); ++i) {
		UISet(7, 3 + 2 * i, (*selectedPlayerSkills)[i].name);
	}

	if (*m_selectedPlayer != nullptr && (*m_selectedPlayer)->GetTarget() != nullptr)
		UISet(4, 3 + 2 * select, "¢º");
	else UISet(4, 3, "¢º");

	for (int y = 0; y < 14; ++y) {
		GotoXY(6, 24 + y);
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
