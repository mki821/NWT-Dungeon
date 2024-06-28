#include <io.h>
#include "console.h"
#include "StateMachine.h"
#include "SelectPlayerTurn.h"
#include "SelectEnemyTurn.h"
#include "SelectSkillTurn.h"
#include "EnemyAttackTurn.h"
#include "NextStageTurn.h"
#include "PlayerMen.h"
#include "PlayerBear.h"
#include "PlayerCat.h"
#include "Enemy.h"
#include "Core.h"

Core* Core::m_pInstance = nullptr;

bool Core::Init() {
	system("title NWT_DUNGEON | mode con cols=140 lines=40");
	LockResize();
	CursorVisible(false, 1);
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	{
		Player* player = new PlayerMen;
		player->Init();
		m_players.push_back(player);
	}
	{
		Player* player = new PlayerBear;
		player->Init();
		m_players.push_back(player);
	}
	{
		Player* player = new PlayerCat;
		player->Init();
		m_players.push_back(player);
	}

	for (int i = 0; i < 3; ++i) {
		Enemy* enemy = new TrashMob;
		enemy->Init();
		m_enemies.push_back(enemy);
	}

	m_stateMachine = new StateMachine;
	m_stateMachine->AddState(TURN::SELECTPLAYER, new SelectPlayerTurn(this, m_stateMachine));
	m_stateMachine->AddState(TURN::SELECTENEMY, new SelectEnemyTurn(this, m_stateMachine));
	m_stateMachine->AddState(TURN::SELECTSKILL, new SelectSkillTurn(this, m_stateMachine));
	m_stateMachine->AddState(TURN::ENEMYATTACK, new EnemyAttackTurn(this, m_stateMachine));
	m_stateMachine->AddState(TURN::NEXTSTAGE, new NextStageTurn(this, m_stateMachine));

	m_stateMachine->Init(TURN::SELECTPLAYER);

	renderer = new Renderer;
	renderer->Init(&m_players, &m_selectedPlayer, &m_enemies);

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

vector<Enemy*> *Core::GetEnemies() {
	return &m_enemies;
}

Player* Core::GetSelectedPlayer() {
	return m_selectedPlayer;
}

bool Core::SetSelectedPlayer(const int index) {
	if (index == -1) {
		m_selectedPlayer = nullptr;
		return true;
	}

	if (m_players[index]->isAttacked) return false;

	m_selectedPlayer = m_players[index];

	return true;
}

bool Core::CanPlayerAttack() {
	for (int i = 0; i < m_players.size(); ++i) {
		if (!m_players[i]->isAttacked) return true;
	}

	return false;
}

void Core::ResetPlayersAttack() {
	for (int i = 0; i < m_players.size(); ++i) {
		m_players[i]->isAttacked = false;
	}
}
