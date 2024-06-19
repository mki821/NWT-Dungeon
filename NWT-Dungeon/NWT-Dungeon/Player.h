#pragma once

#include "Character.h"

enum class PlayerSkillEnum {
	Attack, Tackle
};

class Player : public Character {
public:
	void Init();
	//void SetTarget(Enemy* target);
	void ApplyDamage(int damage);
private:
	//Enemy* m_target;
private:
	bool Attack(PlayerSkillEnum way);
	void CommonAttack();
	void Tackle();
private:
	const int _commonAttackStamina = 1;
	const int _tackleStamina = 2;
};