#include "Enemy.h"

void TrashMob::Init()
{
	m_attack = RandomValue(1, 3);
	m_health = RandomValue(3, 5);
	m_stamina = 5;

	m_character = TrashMobSlime;
	m_characterSize = 10;
	m_characterOffset = -1;
}

void TrashMob::Attack(Player* player)
{
	//에니메이션?? 
	player->ApplyDamage(m_attack);
}

TrashMob::TrashMob() {}
