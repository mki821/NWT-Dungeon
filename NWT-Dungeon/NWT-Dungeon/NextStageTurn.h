#pragma once

#include "StateMachine.h"

class NextStageTurn : public State
{
public:
	NextStageTurn(Core* core, StateMachine* stateMachine);
public:
	void Enter() override;
};

