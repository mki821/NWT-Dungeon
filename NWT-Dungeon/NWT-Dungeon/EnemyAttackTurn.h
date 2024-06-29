#pragma once

#include "StateMachine.h"

class Core;	

class EnemyAttackTurn : public State
{
public:
	EnemyAttackTurn(StateMachine* stateMachine);
public:
	void Enter() override;
};

