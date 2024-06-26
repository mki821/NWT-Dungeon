#include "define.h"
#include "Enemy.h"

Boss::Boss() {}

void Boss::Init()
{
	m_attack = 10;
	m_maxHealth = 10;
	m_maxStamina = 10;
}

void Boss::BossSkil()
{
	cout << "보스 스킬";
	SetStamina(m_maxStamina - 1);
}
