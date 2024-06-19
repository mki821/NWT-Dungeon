#include <iostream>
#include <Windows.h>
#include "console.h"
#include "define.h"
#include "Player.h"

void Player::Init() {
	m_health = m_maxHealth;
	m_attack = 3;
	m_stamina = m_maxStamina;

	//m_character = MEN;
	m_characterSize = 11;
}

void Player::ApplyDamage(int damage) {
	SetHealth(m_health - damage);
}

int Player::ChooseAttack() {
	static int select = 0;

	if (GetAsyncKeyState(VK_UP) & 0x8000) --select;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) ++select;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) Attack((PlayerSkillEnum)select);

	if (select < 0) select = 0;
	else if (select > 1) select = 1;

	return select;
}

bool Player::Attack(PlayerSkillEnum way) {
	//this->target = target;

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
	//_targetPtr->ApplyDamage(_attack);
	GotoXY(0, 0);
	std::cout << "공격!";

	//Animation
}

void Player::Tackle() {
	//_targetPtr->ApplyDamage((int)(_attack * 1.1));
	GotoXY(0, 0);
	std::cout << "몸통박치기!";

	//Animation
}
