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
	cout << "�ƾƾƾ� ���ݶ�";
}
