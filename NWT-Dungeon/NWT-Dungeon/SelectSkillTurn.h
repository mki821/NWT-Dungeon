#pragma once

#include "StateMachine.h"

class Player;

class SelectSkillTurn : public State
{
public:
	SelectSkillTurn(Core* core, StateMachine* stateMachine);
public:
	void Enter() override;
	void UpdateState() override;
private:
	Player* m_selectedPlayer = nullptr;
	vector<Enemy*>* m_enemies;
private:
	int m_max = 0;
};

