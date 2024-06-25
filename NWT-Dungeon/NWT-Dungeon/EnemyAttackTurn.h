#pragma once

#include "StateMachine.h"

class Core;	

class EnemyAttackTurn : public State
{
public:
	EnemyAttackTurn(Core* core, StateMachine* stateMachine);
public:
	void Enter() override;
};

