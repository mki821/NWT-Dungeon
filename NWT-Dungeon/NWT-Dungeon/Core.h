#pragma once
#include <vector>
#include "StateMachine.h"
#include "Renderer.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

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
private:
	StateMachine* m_stateMachine;
	Renderer* m_renderer;
public:
	vector<Player*> GetPlayers();
	void SetSelectedPlayer(int index);
private:
	std::vector<Player*> m_players;
	Player* m_selectedPlayer;

	std::vector<Enemy*> m_enemies;
	Enemy* m_enemy;
};
