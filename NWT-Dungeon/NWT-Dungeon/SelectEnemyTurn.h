#pragma once

#include "StateMachine.h"

class Enemy;

class SelectEnemyTurn : public State
{
public:
	SelectEnemyTurn(Core* core, StateMachine* stateMachine);
public:
	void Enter() override;
	void UpdateState() override;
private:
	vector<Enemy*> m_enemies;
};

