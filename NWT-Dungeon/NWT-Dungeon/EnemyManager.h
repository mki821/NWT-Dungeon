#pragma once
#include "define.h"

using std::vector;

enum class EnemyEnum
{
	TrashEnemy,
	BossEnemy
};

class EnemyManager
{
public:
	static EnemyManager* GetInst()
	{
		if (m_enemy == nullptr)
			m_enemy = new EnemyManager;
		return m_enemy;
	}

public:
	void PushEnemy(int atk, int health, EnemyEnum enem);	
public:
	Enemy GetEnemy();
public:
	void PopEnemy();
private:
	vector<Enemy*> m_vecEnemies;
	static EnemyManager* m_enemy;	
};

