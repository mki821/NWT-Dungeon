#pragma once
#include "console.h"
#include "Character.h"
#include "define.h"
#include "Core.h"

class Enemy : public Character
{
public:
	Enemy() = default;
	virtual ~Enemy() = default;

	void Init();					
public:
	virtual void NormalAttack();
};

class TrashMob : public Enemy
{
public:
	TrashMob();	
	void NormalAttack() override;	
};

class Boss : public Enemy
{
public:
	Boss();
	void NormalAttack() override;
	void BossSkil();
};

