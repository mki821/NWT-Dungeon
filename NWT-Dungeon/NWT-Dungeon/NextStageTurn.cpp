#include "Core.h"
#include "NextStageTurn.h"

NextStageTurn::NextStageTurn(StateMachine* stateMachine) {
	m_core = Core::GetInst();
	m_stateMachine = stateMachine;

	m_players = m_core->GetPlayers();
	m_enemies = m_core->GetEnemies();
}

void NextStageTurn::Enter() {
	m_core->IncreaseStageNum();

	for (int i = 0; i < m_players->size(); ++i) {
		(*m_players)[i]->InitState();
	}

	if (m_core->GetEnemies()->size() > 0)
		throw;

	for (int i = 0; i < 3; ++i) {
		Enemy* enemy = new TrashMob;
		enemy->Init();
		m_core->GetEnemies()->push_back(enemy);
	}

	if (*m_core->GetStageNum() % 5 == 0) {
		Enemy* boss = new Boss;
		boss->Init();
		(*m_enemies).push_back(boss);
	}
	else {
		for (int i = 0; i < 3; ++i) {
			Enemy* enemy = new TrashMob;
			enemy->Init();
			(*m_enemies).push_back(enemy);
		}
	}

	vector<Player*> players = *m_core->GetPlayers();
	for (int i = 0; i < players.size(); ++i) {
		players[i]->isAttacked = false;
	}

	m_stateMachine->ChangeState(TURN::SELECTPLAYER);
}
