#pragma once

#include <unordered_map>

class Core;
class StateMachine;

enum class TURN {
	SELECTPLAYER, SELECTENEMY, SELECTSKILL, ENEMYATTACK, NEXTSTAGE, GAMEOVER
};

class State
{
public:
	virtual void Enter();
	virtual void UpdateState();
	virtual void Exit();
protected:
	Core* m_core;
	StateMachine* m_stateMachine;
};

class StateMachine
{
public:
	void Init(TURN stateEnum);
	void ChangeState(TURN turn);
	void AddState(TURN stateEnum, State* state);
public:
	State* CurrentState;
private:
	std::unordered_map<TURN, State*> m_stateDictionary;
};

