#include "Core.h"
#include "GameLogic.h"
#include "SelectEnemyTurn.h"

SelectEnemyTurn::SelectEnemyTurn(StateMachine* stateMachine) {
	m_core = Core::GetInst();
	m_stateMachine = stateMachine;

	m_enemies = m_core->GetEnemies();
}

void SelectEnemyTurn::UpdateState() {
	if (ChooseIndex(0, m_enemies->size() - 1, true, m_core->renderer->select)) {
		m_core->GetSelectedPlayer()->SetTarget((*m_enemies)[m_core->renderer->select]);
		m_core->renderer->select = 0;

		m_stateMachine->ChangeState(TURN::SELECTSKILL);	
	}
}
