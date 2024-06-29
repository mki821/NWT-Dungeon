#pragma once

#include "StateMachine.h"

class Enemy;

class SelectEnemyTurn : public State
{
public:
	SelectEnemyTurn(StateMachine* stateMachine);
public:
	void UpdateState() override;
private:
	vector<Enemy*>* m_enemies;
};
