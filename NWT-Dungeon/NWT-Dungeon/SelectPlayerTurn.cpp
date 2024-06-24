#include "GameLogic.h"
#include "Core.h"
#include "SelectPlayerTurn.h"

SelectPlayerTurn::SelectPlayerTurn(Core* core, StateMachine* stateMachine) {
	m_core = core;
	m_stateMachine = stateMachine;
}

void SelectPlayerTurn::UpdateState() {
	if (ChooseIndex(0, 2, true, m_select)) {
		m_core->SetSelectedPlayer(m_select);
		m_select = 0;
		m_stateMachine->ChangeState(TURN::SELECTENEMY);
	}
}
