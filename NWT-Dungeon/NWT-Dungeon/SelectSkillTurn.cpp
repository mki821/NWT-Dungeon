#include "Core.h"
#include "GameLogic.h"
#include "SelectSkillTurn.h"

SelectSkillTurn::SelectSkillTurn(Core* core, StateMachine* stateMachine) {
	m_core = core;
	m_stateMachine = stateMachine;
}

void SelectSkillTurn::Enter() {
	m_selectedPlayer = m_core->GetSelectedPlayer();

	m_max = (int)m_selectedPlayer->GetSkills()->size() - 1;
}

void SelectSkillTurn::UpdateState() {
	if (ChooseIndex(0, m_max, false, m_core->renderer->select)) {
		if (m_selectedPlayer->Attack(m_core->renderer->select)) {
			m_core->renderer->select = 0;

			m_selectedPlayer->SetTarget(nullptr);
			m_core->SetSelectedPlayer(-1);

			m_stateMachine->ChangeState(TURN::ENEMYATTACK);
		}
	}
}