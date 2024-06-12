#pragma once
#include "Define.h"

enum class EnemyEnum
{
	TrashEnemy,
	BossEnemy
};

class EnemyManager
{
public:
	void PushEnemy(int atk, int health, EnemyEnum enem);	
public:
	Enemy GetEnemy();
public:
	void PopEnemy();
private:
	vector<Enemy*> m_vecEnemies;
};

