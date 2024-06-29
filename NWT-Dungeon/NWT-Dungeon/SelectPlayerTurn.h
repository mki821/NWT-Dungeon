#pragma once

#include "StateMachine.h"

class Core;

class SelectPlayerTurn : public State
{
public:
	SelectPlayerTurn(StateMachine* stateMachine);
public:
	void UpdateState() override;
};

