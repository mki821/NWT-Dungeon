#pragma once

#include <vector>
#include "StateMachine.h"

class Enemy;

class SelectEnemyTurn : public State
{
public:
	SelectEnemyTurn(StateMachine* stateMachine);
public:
	void UpdateState() override;
private:
	std::vector<Enemy*>* m_enemies;
};
