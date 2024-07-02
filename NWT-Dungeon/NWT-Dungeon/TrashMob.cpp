#include "Enemy.h"

void TrashMob::Init()
{
	m_attack = ModifyStat(RandomValue(1, 3));
	m_health = ModifyStat(RandomValue(3, 5));
	m_stamina = 5;

	m_character = TrashMobVisual[RandomValue(0, 2)];
	m_characterSize = 10;
	m_characterOffset = 0;
}

void TrashMob::Attack(Player* player)
{
	//���ϸ��̼�?? 
	player->ApplyDamage(m_attack);
}

TrashMob::TrashMob() {}
