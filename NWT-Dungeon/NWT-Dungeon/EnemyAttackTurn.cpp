#include <random>   
#include <chrono> 
#include "Core.h"
#include "Scene.h"
#include "EnemyAttackTurn.h"

EnemyAttackTurn::EnemyAttackTurn(StateMachine* stateMachine)
{
	m_core = Core::GetInst();
	m_stateMachine = stateMachine;

	m_enemies = m_core->GetEnemies();
}

void EnemyAttackTurn::Enter()
{
	unsigned seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);

	shuffle(m_enemies->begin(), m_enemies->end(), engine);

	for (int i = 0; i < m_enemies->size(); i++)
	{
		std::uniform_int_distribution<int> enemyDistribution(0, m_core->GetPlayerSize() - 1);
		int randValue = enemyDistribution(engine);
		Enemy* enemy = (*m_enemies)[i];

		Player* targetPlayer = (*m_core->GetPlayers())[randValue];

		enemy->Attack(targetPlayer);
		enemy->SetStamina(enemy->GetStamina() - 1);

		m_core->renderer->Render();

		Sleep(1000);

		if (targetPlayer->GetHealth() < 1) {
			Sleep(500);

			m_core->RemovePlayer(targetPlayer);
			delete targetPlayer;
			m_core->renderer->RemovePlayer(randValue);

			if (m_core->GetPlayerSize() < 1) {
				system("cls");
				(new Scene)->ShowScene(SceneType::End);
				exit(0);
				return;
			}
		}
	}

	m_stateMachine->ChangeState(TURN::SELECTPLAYER);		
}
