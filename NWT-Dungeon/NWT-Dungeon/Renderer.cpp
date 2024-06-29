#include <string>
#include <fcntl.h>
#include <io.h>
#include "console.h"
#include "Core.h"
#include "Character.h"
#include "Renderer.h"

void Renderer::Init() {
	m_core = Core::GetInst();

	m_stageNum = m_core->GetStageNum();

	m_players = m_core->GetPlayers();
	m_selectedPlayer = m_core->GetSelectedPlayerPtr();

	m_enemies = m_core->GetEnemies();
}

void Renderer::Render() {
	GameRender();
	UIRender();
}

void Renderer::GameRender() {

	for (int i = 0; i < m_players->size(); ++i) {
		if (*m_selectedPlayer == nullptr && select == i)
			SetColor((int)Color::Red);
		else if ((*m_players)[i]->isAttacked)
			SetColor((int)Color::Blue);
		else if ((*m_players)[i] == *m_selectedPlayer) 
			SetColor((int)Color::Red);

		CharacterRender(6 + 20 * i, 21, (*m_players)[i]);
		SetColor((int)Color::White);
	}

	for (int i = 0; i < m_enemies->size(); ++i) {
		if (*m_selectedPlayer != nullptr) {
			Enemy* currentTarget = (*m_selectedPlayer)->GetTarget();

			if (currentTarget == nullptr) {
				if (select == i) SetColor((int)Color::Red);
			}
			else {
				if ((*m_enemies)[i] == currentTarget) SetColor((int)Color::Red);
			}
		}
		CharacterRender(68 + 23 * i, 21, (*m_enemies)[i]);
		SetColor((int)Color::White);
	}

	for (int i =(int)m_enemies->size(); i < 3; ++i) {
		int x = 68 + 23 * i;
		GotoXY(x, 21);
		for (int y = 22; y >= 0; --y) {
			GotoXY(x, y);
			wcout << "                     ";
		}
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
	wcout << "┌";
	for (int i = 0; i < 129; ++i) {
		wcout << "─";
	}
	wcout << "┐";
	for (int i = 24; i < 38; ++i) {
		GotoXY(4, i);
		wcout << "│";
		GotoXY(134, i);
		wcout << "│";
	}
	GotoXY(4, 38);
	wcout << "└";
	for (int i = 0; i < 129; ++i) {
		wcout << "─";
	}
	wcout << "┘";
	#pragma endregion

	memset(_ui, ' ', sizeof(_ui));

	for (int i = 0; i < 8; ++i) {
		UISet(54, 3 + i, STAGE[i]);
	}

	int num = *m_stageNum;
	for (int i = 0; i < 8; ++i) {
		UISet(108, 3 + i, NUM[num / 10][i]);
		UISet(118, 3 + i, NUM[num % 10][i]);
	}

	vector<PlayerSkill>* selectedPlayerSkills = (*m_players)[select]->GetSkills();

	if(*m_selectedPlayer != nullptr)
		selectedPlayerSkills = (*m_selectedPlayer)->GetSkills();

	UISet(7, 3, "스킬 이름");
	UISet(20, 3, "스테미나");
	UISet(30, 3, "공격력");
	for (int i = 0; i < selectedPlayerSkills->size(); ++i) {
		UISet(7, 6 + 2 * i, (*selectedPlayerSkills)[i].name);
		UISet(23, 6 + 2 * i, std::to_string((*selectedPlayerSkills)[i].useStamina));
		UISet(32, 6 + 2 * i, std::to_string((*selectedPlayerSkills)[i].attack));
	}

	if (*m_selectedPlayer != nullptr && (*m_selectedPlayer)->GetTarget() != nullptr)
		UISet(4, 6 + 2 * select, "▶");

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
