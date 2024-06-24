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
}

Enemy* Player::GetTarget() {
	return m_target;
}

void Player::SetTarget(Enemy* target) {
	m_target = target;
}

bool Player::Attack(PlayerSkillEnum way) {
	switch (way) {
		case PlayerSkillEnum::Attack:
			if (SetStamina(m_stamina - _commonAttackStamina)) {
				CommonAttack();
				return true;
			}
			return false;
		case PlayerSkillEnum::Tackle:
			if (SetStamina(m_stamina - _tackleStamina)) {
				Tackle();
				return true;
			}
			return false;
	}

	return false;
}

void Player::CommonAttack() {
	m_target->ApplyDamage(m_attack);
	GotoXY(0, 0);

	//Animation
}

void Player::Tackle() {
	m_target->ApplyDamage(m_attack * 1.1);
	GotoXY(0, 0);

	//Animation
}
