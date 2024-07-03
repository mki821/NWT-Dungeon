#pragma once

#include "Player.h"
#include "Enemy.h"

class Renderer
{
public:
	void Init();
	void Render();
	void RemovePlayer(int index);
private:
	void GameRender();
	void CharacterRender(int x, int y, Character* _character);
	void UIRender();
	void UISet(int x, int y, std::string value);
private:
	char _ui[14][128];
public:
	int select = 0;
private:
	Core* m_core;

	int* m_stageNum;

	std::vector<Player*>* m_players;
	Player** m_selectedPlayer;

	std::vector<Enemy*>* m_enemies;
};
