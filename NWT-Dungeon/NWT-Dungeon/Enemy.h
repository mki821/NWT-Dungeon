#pragma once
#include "console.h"
#include "Character.h"

class Core;

class Enemy : public Character
{
public:
	Enemy() = default;
	virtual ~Enemy() = default;

	virtual void Init();
};

class TrashMob : public Enemy
{
public:
	TrashMob();	
	void Init() override;
};

class Boss : public Enemy
{
public:
	Boss();
	void Init() override;
	void BossSkil();
};

