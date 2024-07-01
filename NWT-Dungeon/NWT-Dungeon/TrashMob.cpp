#include "Enemy.h"

void TrashMob::Init()
{
	m_attack = RandomValue(1, 3);
	m_health = RandomValue(3, 5);
	m_stamina = 5;

	m_maxHealth = m_health;
	m_maxStamina = m_stamina;

	m_character = TrashMobVisual[RandomValue(0, 2)];
	m_characterSize = 10;
	m_characterOffset = -1;
}

void TrashMob::Attack(Player* player)
{
	player->ApplyDamage(m_attack);
}

TrashMob::TrashMob() {}
