#include "Enemy.h"

void Enemy::Init()
{
	m_attack = 10;
	m_maxHealth = 10;
	m_maxStamina = 10;
}

Boss::Boss() {}

void Boss::NormalAttack()
{
	
}

void Boss::BossSkil()
{
	cout << "���� ��ų";
	SetStamina(m_maxStamina - 1);
}
