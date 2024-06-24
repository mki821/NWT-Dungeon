#pragma once

#include "Player.h"

class Renderer
{
public:
	void Render();
private:
	void GameRender();
	void CharacterRender(int x, int y, Character* _character);
	void UIRender();
	void UISet(int x, int y, std::string value);
private:
	char _ui[14][128];
public:
	void Init(vector<Player*> players, Player*& playerRef, vector<Enemy*> enemies);
private:
	vector<Player*> m_players;
	Player* m_selectedPlayer;

	vector<Enemy*> m_enemies;

	int m_select = 0;
};
