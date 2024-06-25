#pragma once

#include "Character.h"
class Enemy;

struct PlayerSkill {
	string name;
	int useStamina;
	int attack;
};

class Player : public Character {
public:
	void Init();
	Enemy* GetTarget();
	void SetTarget(Enemy* target);
	bool Attack(int index);
private:
	Enemy* m_target;
private:
	void CommonAttack();
	const int _commonAttackStamina = 1;
public:
	std::vector<PlayerSkill>* GetSkills();
	PlayerSkill GetSkillInfo(int index);
private:
	std::vector<PlayerSkill> m_skills;
};