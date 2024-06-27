#include <random>   
#include <chrono> 
#include "Core.h"
#include "EnemyAttackTurn.h"

enum class  CharacterEnum
{
	Enemy, Player
};

EnemyAttackTurn::EnemyAttackTurn(Core* core, StateMachine* stateMachine)
{
	m_core = core;
	m_stateMachine = stateMachine;
}

void EnemyAttackTurn::Enter()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);

	GotoXY(0, 0);
	Core* core = m_core->GetInst();
	cout << core;
	for (auto a : core->GetEnemies())
		cout << a;
	//cout << core->GetEnemies().size();

	
	//shuffle(core->GetEnemies().begin(), core->GetEnemies().end(), engine);	
	
		

	/*for (int i = 0; i < core->GetEnemies().size(); i++)
	{
		Enemy* enemy = core->GetEnemies()[i];
		
		int randValue = rand() % (core->GetPlayers().size() - 1);
		Player* targetPlayer = core->GetPlayers()[randValue];	

		targetPlayer->ApplyDamage(enemy->GetAttack());
		enemy->SetStamina(-1);
	}*/

	m_stateMachine->ChangeState(TURN::SELECTPLAYER);
}
