#pragma once
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

enum class TURN {
	SELECTPLAYER, SELECTENEMY, SELECTSKILL, ENEMYATTACK
};

class Core {
private:
	Core() = default;
	static Core* m_pInstance;
public:
	static Core* GetInst() {
		if(m_pInstance == nullptr)
			m_pInstance = new Core;

		return m_pInstance;
	}
	static void DestroyInst() {
		if(m_pInstance != nullptr)
			delete m_pInstance;

		m_pInstance = nullptr;
	}
public:
	bool Init();
	void Run();
private:
	void Update();
	void Render();
	void GameRender();
	void CharacterRender(int x, int y, Character* _character);
	void UIRender();
	void FrameSync(int frameRate);
private:
	char _ui[14][128];
	void UISet(int x, int y, std::string value);
private:
	int _select = 0;
	int _finalSelect = 0;
	clock_t _lastSelectTime;
	void ChooseIndex(int min, int max, bool horizontal = true);
private:
	TURN m_currentTurn;
	
	std::vector<Player*> m_players;
	Player* m_selectedPlayer;

	std::vector<Enemy*> m_enemies;
	Enemy* m_enemy;
};
