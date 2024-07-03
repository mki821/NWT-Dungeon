#include "define.h"
#include "Enemy.h"

Boss::Boss() {}

void Boss::Init()
{
	m_attack = ModifyStat(RandomValue(4, 6), 1);
	m_health = ModifyStat(RandomValue(30, 32), 2);
	m_stamina = 10;

	m_maxHealth = m_health;
	m_maxStamina = m_stamina;

	m_character = BossSword;
	m_characterSize = 16;
	m_characterOffset = 0;
}

void Boss::Attack(Player* player)
{
	player->ApplyDamage(m_attack);
}
