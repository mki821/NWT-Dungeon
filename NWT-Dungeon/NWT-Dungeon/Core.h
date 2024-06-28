#pragma once
#include <vector>
#include "StateMachine.h"
#include "Renderer.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

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
public:
	vector<Player*> GetPlayers();
	vector<Enemy*>* GetEnemies();

	Player* GetSelectedPlayer();
	bool SetSelectedPlayer(int index);

	bool CanPlayerAttack();
	void ResetPlayersAttack();
private:
	std::vector<Player*> m_players;
	Player* m_selectedPlayer;

	std::vector<Enemy*> m_enemies;
	Enemy* m_enemy;
};
