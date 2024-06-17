#pragma once

#include "Character.h"

enum class PlayerSkillEnum {
	Attack, Tackle
};

class Player : public Character {
public:
	void Init();
	void ApplyDamage(int damage);
	int ChooseAttack();
	bool Attack(PlayerSkillEnum way);
	//void Attack(Eenmy* target, PlayerSkillEnum way);
private:
	//Enemy* _targetPtr;
	void CommonAttack();
	void Tackle();
private:
	const int _commonAttackStamina = 1;
	const int _tackleStamina = 2;
};