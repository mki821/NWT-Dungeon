#pragma once

#include "StateMachine.h"

class NextStageTurn : public State
{
public:
	NextStageTurn(StateMachine* stateMachine);
public:
	void Enter() override;
};

