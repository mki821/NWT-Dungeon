#pragma once

#include "Character.h"
#include "Enemy.h"

enum class PlayerSkillEnum {
	Attack, Tackle
};

class Player : public Character {
public:
	void Init();
	Enemy* GetTarget();
	void SetTarget(Enemy* target);
	bool Attack(PlayerSkillEnum way);
private:
	Enemy* m_target;
private:
	void CommonAttack();
	void Tackle();
private:
	const int _commonAttackStamina = 1;
	const int _tackleStamina = 2;
};