#include <iostream>
#include <Windows.h>
#include "console.h"
#include "Player.h"

void Player::Init() {
	_health = _maxHealth;
	_attack = 3;
	_stamina = _maxStamina;
}

void Player::ApplyDamage(int damage) {
	SetHealth(_health - damage);
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
			if (SetStamina(_stamina - _commonAttackStamina)) {
				CommonAttack();
				return true;
			}
			return false;
		case PlayerSkillEnum::Tackle:
			if (SetStamina(_stamina - _tackleStamina)) {
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
	_stamina -= 3;

	//Animation
}

void Player::Tackle() {
	//_targetPtr->ApplyDamage((int)(_attack * 1.1));
	GotoXY(0, 0);
	std::cout << "몸통박치기!";

	//Animation
}

int Player::GetHealth() const {
	return _health;
}

void Player::SetHealth(int value) {
	if (value < 0) _health = 0;
	else if (value > _maxHealth) _health = _maxHealth;
	else _health = value;
}

int Player::GetAttack() const {
	return _attack;
}

int Player::GetStamina() const {
	return _stamina;
}

bool Player::SetStamina(int value) {
	if (value < 0) return false;

	if (value > _maxStamina) _stamina = _maxStamina;
	else _stamina = value;

	return true;
}
