#pragma once

#include <vector>
#include "Character.h"

using std::vector;

class Enemy;

typedef struct _playerSkill {
	std::string name;
	int useStamina;
	int attack;
} PlayerSkill, *PPlayerSkill;

class Player : public Character {
public:
	virtual void Init();
	Enemy* GetTarget();
	void SetTarget(Enemy* target);
	bool Attack(int index);
public:
	bool isAttacked = false;
private:
	Enemy* m_target;
private:
	void CommonAttack();
	const int _commonAttackStamina = 1;
public:
	vector<PlayerSkill>* GetSkills();
	PlayerSkill GetSkillInfo(int index);
protected:
	vector<PlayerSkill> m_skills;
};

class PlayerMen;