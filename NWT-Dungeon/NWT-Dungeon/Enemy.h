#pragma once
#include "console.h"
#include "Character.h"
#include "Player.h"
#include "Core.h"

//class Core;

class Enemy : public Character
{
public:
	Enemy() = default;
	virtual ~Enemy() = default;
public:

	virtual void Init();
	virtual void Attack(Player* player);
	
	int ModifyStat(int stat, float mod);
	int RandomValue(int min, int max);

private:
	int m_enemyAttack;
	int m_enemyHealth;
	int m_enemyStamina;
};

class TrashMob : public Enemy
{
public:
	TrashMob();
	void Init() override;
	void Attack(Player* player) override;
};

class Boss : public Enemy
{
public:
	Boss();
	void Init() override;
	void Attack(Player* player) override;
};

