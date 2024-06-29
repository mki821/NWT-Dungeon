#include "Core.h"
#include "GameLogic.h"
#include "SelectSkillTurn.h"

SelectSkillTurn::SelectSkillTurn(StateMachine* stateMachine) {
	m_core = Core::GetInst();
	m_stateMachine = stateMachine;

	m_selectedPlayer = m_core->GetSelectedPlayerPtr();
	m_enemies = m_core->GetEnemies();
}

void SelectSkillTurn::Enter() {
	m_max = (int)(*m_selectedPlayer)->GetSkills()->size() - 1;
}

void SelectSkillTurn::UpdateState() {
	if (ChooseIndex(0, m_max, false, m_core->renderer->select)) {
		if ((*m_selectedPlayer)->Attack(m_core->renderer->select)) {
			m_core->renderer->select = 0;

			Enemy* target = (*m_selectedPlayer)->GetTarget();
			if (target->GetHealth() < 1) {
				m_core->RemoveEnemy(target);
				delete target;
			}

			(*m_selectedPlayer)->SetTarget(nullptr);
			m_core->SetSelectedPlayer(-1);

			if (m_core->CanPlayerAttack())
				m_stateMachine->ChangeState(TURN::SELECTPLAYER);
			else if (m_core->GetEnemies()->size() < 1)
				m_stateMachine->ChangeState(TURN::NEXTSTAGE);
			else {
				m_core->ResetPlayersAttack();
				m_stateMachine->ChangeState(TURN::ENEMYATTACK);
			}
		}
	}
}
