#pragma once
#include <vector>
#include <algorithm>
#include "StateMachine.h"
#include "Renderer.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "TitleScene.h"

using std::vector;

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
	void FrameSync(int frameRate);
public:
	Renderer* renderer;
private:
	StateMachine* m_stateMachine;
private:
	TitleScene* titleScene;
public:
	int* GetStageNum();
	void IncreaseStageNum();

	vector<Player*>* GetPlayers();
	int GetPlayerSize();
	vector<Enemy*>* GetEnemies();
	void RemoveEnemy(Enemy* enemy);

	Player* GetSelectedPlayer();
	Player** GetSelectedPlayerPtr();
	bool SetSelectedPlayer(int index);

	bool CanPlayerAttack();
	void ResetPlayersAttack();
private:
	int m_stageNum = 1;

	std::vector<Player*> m_players;
	Player* m_selectedPlayer;

	std::vector<Enemy*> m_enemies;
	Enemy* m_enemy;
};
