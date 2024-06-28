#include "Core.h"
#include "NextStageTurn.h"

NextStageTurn::NextStageTurn(Core* core, StateMachine* stateMachine) {
	m_core = core;
	m_stateMachine = stateMachine;
}

void NextStageTurn::Enter() {
	if (m_core->GetEnemies()->size() > 0)
		throw;

	for (int i = 0; i < 3; ++i) {
		Enemy* enemy = new TrashMob;
		enemy->Init();
		m_core->GetEnemies()->push_back(enemy);
	}

	vector<Player*> players = *m_core->GetPlayers();
	for (int i = 0; i < players.size(); ++i) {
		players[i]->isAttacked = false;
	}

	m_stateMachine->ChangeState(TURN::SELECTPLAYER);
}
