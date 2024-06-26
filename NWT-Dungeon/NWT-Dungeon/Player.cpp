#include <iostream>
#include <Windows.h>
#include "console.h"
#include "define.h"
#include "Enemy.h"
#include "Player.h"

void Player::Init() {
	m_health = m_maxHealth;
	m_attack = 3;
	m_stamina = m_maxStamina;

	m_character = MEN;
	m_characterSize = 11;

	m_skills.push_back({ "일반 공격", 0, 3 });
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
		m_target->ApplyDamage(currentSkill.attack);
		isAttacked = true;
		return true;
	}

	return false;
}

void Player::CommonAttack() {
	m_target->ApplyDamage(m_attack);
	GotoXY(0, 0);

	//Animation
}

vector<PlayerSkill>* Player::GetSkills()
{
	return &m_skills;
}

PlayerSkill Player::GetSkillInfo(int index) {
	return m_skills[index];
}
