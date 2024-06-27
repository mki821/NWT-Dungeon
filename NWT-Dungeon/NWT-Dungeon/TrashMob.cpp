#include "define.h"
#include "Player.h"
#include "Enemy.h"

void TrashMob::Init()
{
	m_attack = 2;
	m_health = 3;

	m_character = TrashMobSlime;
	m_characterSize = 15;
	m_characterOffset = -1;
}

TrashMob::TrashMob() {}
