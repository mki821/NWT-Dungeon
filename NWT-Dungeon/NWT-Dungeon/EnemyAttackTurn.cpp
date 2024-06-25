#include "Core.h"
#include "EnemyAttackTurn.h"

EnemyAttackTurn::EnemyAttackTurn(Core* core, StateMachine* stateMachine)
{
	m_core = core;
	m_stateMachine = stateMachine;
}

void EnemyAttackTurn::Enter()
{
	Core* core = m_core->GetInst();

	int randEnemy = rand() % core->GetEnemies().size() - 1;
	Enemy* attackEnemy = core->GetEnemies()[randEnemy];	

	int randPlayer = rand() % core->GetPlayers().size() - 1;
	Player* targetPlayer = core->GetPlayers()[randPlayer];

	targetPlayer->ApplyDamage(attackEnemy->GetAttack());

	m_stateMachine->ChangeState(TURN::SELECTPLAYER);		
}
