#include "define.h"
#include "Player.h"
#include "Enemy.h"

void TrashMob::Init()
{
	m_attack = 5;
	m_health = 3;

	m_character = TrashMobVisual;
	m_characterSize = 10;
}

TrashMob::TrashMob() {}
