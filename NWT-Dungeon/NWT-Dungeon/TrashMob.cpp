#include "Enemy.h"

void Enemy::Init()
{
	m_attack = 5;
	m_health = 3;

	m_character = TrashMobVisual;
	m_characterSize = 10;
}

TrashMob::TrashMob() {}

void TrashMob::NormalAttack()
{
	Player* player = SetTarget();
	player->ApplyDamage(m_attack);
	GotoPos(0, 0);
	cout << "¾Æ¾Æ¾Æ¾Ó °ø°Ý¶ì";
}
