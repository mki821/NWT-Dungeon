#pragma once

#include "Player.h"

class Renderer
{
public:
	void Init(std::vector<Player*> players, Player** selectedPlayer, vector<Enemy*> enemies);	
	void Render();
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
	std::vector<Player*> m_players;
	Player** m_selectedPlayer;

	std::vector<Enemy*> m_enemies;
};
