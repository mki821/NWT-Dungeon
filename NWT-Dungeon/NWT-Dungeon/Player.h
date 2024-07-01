#pragma once

#include <vector>
#include "Character.h"

using std::vector;

class Enemy;

typedef struct _playerSkill {
	std::string name;
	int useStamina;
	int attack;
	std::string sfxName;
	vector<std::wstring>* animation;
} PlayerSkill, *PPlayerSkill;

class Player : public Character {
public:
	virtual void Init();
	void InitState();
	Enemy* GetTarget();
	void SetTarget(Enemy* target);
	bool Attack(int index);
private:
	void Animation(const PlayerSkill &ps);
public:
	bool isAttacked = false;
private:
	Enemy* m_target;
public:
	vector<PlayerSkill>* GetSkills();
	PlayerSkill GetSkillInfo(int index);
protected:
	vector<PlayerSkill> m_skills;
};