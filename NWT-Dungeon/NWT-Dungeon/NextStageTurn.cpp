#include "Core.h"
#include "Scene.h"
#include "NextStageTurn.h"

NextStageTurn::NextStageTurn(StateMachine* stateMachine) {
	m_core = Core::GetInst();
	m_stateMachine = stateMachine;

	m_players = m_core->GetPlayers();
	m_enemies = m_core->GetEnemies();
}

void NextStageTurn::Enter() {
	int stageNum = *m_core->GetStageNum();
	if (stageNum == 20) {
		system("cls");
		(new Scene)->ShowScene(SceneType::Clear);
		exit(0);
		return;
	}

	if (stageNum % 5 == 0) {
		for (int i = 0; i < m_players->size(); ++i) {
			(*m_players)[i]->InitState();
		}
	}

	m_core->IncreaseStageNum();

	if (m_enemies->size() > 0)
		throw;

	m_enemies->clear();
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

	system("cls");

	m_stateMachine->ChangeState(TURN::SELECTPLAYER);
}
