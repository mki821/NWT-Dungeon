#include <random>   
#include <chrono> 
#include "Core.h"
#include "EnemyAttackTurn.h"

EnemyAttackTurn::EnemyAttackTurn(StateMachine* stateMachine)
{
	m_core = Core::GetInst();
	m_stateMachine = stateMachine;
}

void EnemyAttackTurn::Enter()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);	

	Core* core = m_core->GetInst();
	m_enemies = core->GetEnemies();

	shuffle(m_enemies.begin(), m_enemies.end(), engine);

	std::uniform_int_distribution<int> enemyDistribution(0, m_enemies.size() - 1);		

	for (int i = 0; i < m_enemies.size(); i++)	
	{
		int randValue = enemyDistribution(engine);		
		Enemy* enemy = m_enemies[i];

		Player* targetPlayer = core->GetPlayers()[randValue];	

		enemy->Attack(targetPlayer);
		enemy->SetStamina(enemy->GetStamina() - 1);	
	}

	m_stateMachine->ChangeState(TURN::SELECTPLAYER);		
}
