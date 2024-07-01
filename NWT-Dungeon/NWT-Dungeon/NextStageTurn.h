#pragma once

#include <vector>
#include "StateMachine.h"

class NextStageTurn : public State
{
public:
	NextStageTurn(StateMachine* stateMachine);
public:
	void Enter() override;
private:
	std::vector<Player*>* m_players;
	std::vector<Enemy*>* m_enemies;
};

