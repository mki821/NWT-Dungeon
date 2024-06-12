#include <iostream>
#include "Player.h"

void Player::ApplyDamage(int damage) {
	SetHealth(_health - damage);
}

void Player::Attack(PlayerSkillEnum way) {
	//this->target = target;

	switch (way) {
		case PlayerSkillEnum::Attack:
			CommonAttack();
			break;
		case PlayerSkillEnum::Tackle:
			Tackle();
			break;
	}
}

void Player::CommonAttack() {
	//_targetPtr->ApplyDamage(_attack);
	std::cout << "공격!";

	//Animation
}

void Player::Tackle() {
	//_targetPtr->ApplyDamage((int)(_attack * 1.1));
	std::cout << "몸통박치기!";

	//Animation
}

int Player::GetHealth() {
	return _health;
}

void Player::SetHealth(int value) {
	if (value < 0) _health = 0;
	else if (value > _maxHealth) _health = _maxHealth;
	else _health = value;
}

int Player::GetAttack() {
	return _attack;
}

int Player::GetStamina() {
	return _stamina;
}
