#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <io.h>
#include "console.h"
#include "define.h"
#include "Player.h"
#include "StateMachine.h"
#include "SelectPlayerTurn.h"
#include "Core.h"

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

	m_stateMachine->Init(TURN::SELECTPLAYER);

	m_renderer = new Renderer;
	m_renderer->Init(m_players, m_selectedPlayer, m_enemies);

	return true;
}

void Core::Run() {
	while (true) {
		m_stateMachine->CurrentState->UpdateState();
		m_renderer->Render();
		FrameSync(60);

		//case TURN::SELECTENEMY: {
		//	ChooseIndex(0, 2);
		//	if (_select == -1) {
		//		m_selectedPlayer->SetTarget(m_enemies[_finalSelect]);
		//		_select = 0;
		//		_finalSelect = 0;
		//		m_currentTurn = TURN::SELECTSKILL;
		//	}
		//}
		//break;
		//case TURN::SELECTSKILL: {
		//	ChooseIndex(0, 1, false);
		//	if (_select == -1) {
		//		m_selectedPlayer->Attack((PlayerSkillEnum)_finalSelect);
		//		_select = 0;
		//		_finalSelect = 0;

		//		m_selectedPlayer->SetTarget(nullptr);
		//		m_selectedPlayer = nullptr;

		//		m_currentTurn = TURN::SELECTPLAYER;
		//	}
		//}
		//break;
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

void Core::SetSelectedPlayer(int index) {
	m_selectedPlayer = m_players[index];
}

vector<Player*> Core::GetPlayers() {
	return m_players;
}
