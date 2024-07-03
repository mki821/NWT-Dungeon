#include "Core.h"
#include "GameLogic.h"
#include "SelectPlayerTurn.h"

SelectPlayerTurn::SelectPlayerTurn(StateMachine* stateMachine) {
	m_core = Core::GetInst();
	m_stateMachine = stateMachine;
}

void SelectPlayerTurn::UpdateState() {
	if (ChooseIndex(0, m_core->GetPlayerSize() - 1, true, m_core->renderer->select)) {
		if (m_core->SetSelectedPlayer(m_core->renderer->select)) {
			m_core->renderer->select = 0;

			m_stateMachine->ChangeState(TURN::SELECTENEMY);
		}
	}
}



