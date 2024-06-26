#include <iostream>
#include <io.h>
#include "console.h"
#include "StateMachine.h"
#include "SelectPlayerTurn.h"
#include "SelectEnemyTurn.h"
#include "SelectSkillTurn.h"
#include "Core.h"
#include "Enemy.h"
using std::wcout;

Core* Core::m_pInstance = nullptr;

bool Core::Init() {
	system("title NWT_DUNGEON | mode con cols=140 lines=40");
	LockResize();
	CursorVisible(false, 1);
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	for (int i = 0; i < 3; ++i) {
		Player* player = new Player;
		player->Init();
		m_players.push_back(player);
	}

	for (int i = 0; i < 3; ++i) {
		Enemy* enemy = new Enemy;
		enemy->Init();
		m_enemies.push_back(enemy);
	}

	m_stateMachine = new StateMachine;
	m_stateMachine->AddState(TURN::SELECTPLAYER, new SelectPlayerTurn(this, m_stateMachine));
	m_stateMachine->AddState(TURN::SELECTENEMY, new SelectEnemyTurn(this, m_stateMachine));
	m_stateMachine->AddState(TURN::SELECTSKILL, new SelectSkillTurn(this, m_stateMachine));

	m_stateMachine->Init(TURN::SELECTPLAYER);

	renderer = new Renderer;
	renderer->Init(m_players, &m_selectedPlayer, m_enemies);

	return true;
}

void Core::Run() {
	while (true) {
		m_stateMachine->CurrentState->UpdateState();
		renderer->Render();
		FrameSync(60);
	}
}

void Core::FrameSync(int frameRate) {
	clock_t oldTime = clock();
	clock_t curTime;

	while (true) {
		curTime = clock();
		if (curTime - oldTime > 1000 / frameRate) {
			oldTime = curTime;
			break;
		}
	}
}

vector<Player*> Core::GetPlayers() {
	return m_players;
}

vector<Enemy*> Core::GetEnemies() {
	return m_enemies;
}

Player* Core::GetSelectedPlayer() {
	return m_selectedPlayer;
}

void Core::SetSelectedPlayer(const int index) {
	if (index == -1) {
		m_selectedPlayer = nullptr;
	}
	else {
		m_selectedPlayer = m_players[index];
	}
}
