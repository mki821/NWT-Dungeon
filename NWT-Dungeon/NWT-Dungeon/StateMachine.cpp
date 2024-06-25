#include "StateMachine.h"

void StateMachine::Init(TURN stateEnum) {
    CurrentState = m_stateDictionary[stateEnum];
    CurrentState->Enter();
}

void StateMachine::ChangeState(TURN turn) {
    CurrentState->Exit();
    CurrentState = m_stateDictionary[turn];
    CurrentState->Enter();
}

void StateMachine::AddState(TURN stateEnum, State* state) {
    m_stateDictionary[stateEnum] = state;
}

void State::Enter() { }
void State::UpdateState() { }
void State::Exit() { }
