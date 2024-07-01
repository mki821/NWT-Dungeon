#include <random>   
#include <chrono> 
#include "Core.h"
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

	std::uniform_int_distribution<int> enemyDistribution(0, (int)m_enemies->size() - 1);

	for (int i = 0; i < m_enemies->size(); i++)
	{
		int randValue = enemyDistribution(engine);		
		Enemy* enemy = (*m_enemies)[i];

		Player* targetPlayer = (*m_core->GetPlayers())[randValue];

		enemy->Attack(targetPlayer);
		enemy->SetStamina(enemy->GetStamina() - 1);

		if (targetPlayer->GetHealth() < 1) {
			delete targetPlayer;
		}
	}

	m_stateMachine->ChangeState(TURN::SELECTPLAYER);		
}
