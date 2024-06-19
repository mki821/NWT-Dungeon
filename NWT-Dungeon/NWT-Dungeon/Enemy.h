#pragma once
#include "Core.h"
#include "console.h"
#include "EnemyManager.h"
#include "Character.h"

class Enemy : public Character
{
public:
	void Init();	
	Enemy(float atk, float health);
	virtual ~Enemy() = default;
protected:
	float m_atk;
	float m_health;
};

class TrashMob : public Enemy
{
public:
	TrashMob(float atk, float health);
};

class Boss : public Enemy
{
public:
	Boss(float atk, float health);
};

