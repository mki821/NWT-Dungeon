#include <iostream>
#include <Windows.h>
#include "console.h"
#include "define.h"
#include "Core.h"
#include "Enemy.h"
#include "Player.h"

void Player::Init() {
	m_originCharacter = m_character;
}

Enemy* Player::GetTarget() {
	return m_target;
}

void Player::SetTarget(Enemy* target) {
	m_target = target;
}

bool Player::Attack(int index) {
	PlayerSkill currentSkill = m_skills[index];

	if (SetStamina(m_stamina - currentSkill.useStamina)) {
		Animation(currentSkill);

		m_target->ApplyDamage(currentSkill.attack);
		isAttacked = true;
		return true;
	}

	return false;
}

void Player::Animation(const PlayerSkill& ps) {
	for (int i = 0; i < 5; ++i) {
		copy(ps.animation[i].begin(), ps.animation[i].end(), m_character);
		Core::GetInst()->renderer->Render();
		Sleep(50);
	}

	m_character = m_originCharacter;
}

vector<PlayerSkill>* Player::GetSkills() {
	return &m_skills;
}

PlayerSkill Player::GetSkillInfo(int index) {
	return m_skills[index];
}
