#pragma once

#include "StateMachine.h"

class Core;

class SelectPlayerTurn : public State
{
public:
	SelectPlayerTurn(Core* core, StateMachine* stateMachine);
public:
	void UpdateState() override;
private:
	int m_select = 0;
};

