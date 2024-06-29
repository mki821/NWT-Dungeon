#pragma once

#include <vector>
#include "StateMachine.h"

class Core;	

class EnemyAttackTurn : public State
{
public:
	EnemyAttackTurn(StateMachine* stateMachine);
public:
	void Enter() override;
private:
	std::vector<Enemy*>* m_enemies;
};

