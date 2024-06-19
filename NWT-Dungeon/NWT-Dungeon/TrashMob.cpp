#include "Enemy.h"

void Enemy::Init()
{
	m_character = TrashMob;
	m_characterSize = 10;
}

TrashMob::TrashMob(float atk, float health) : Enemy(atk, health)
{
	atk = 1;
	health = 100;
}
