#include "define.h"
#include "Player.h"
#include "Enemy.h"

void TrashMob::Init()
{
	m_attack = 2;
	m_health = 3;

	m_character = Ghost;
	m_characterSize = 12;
}

TrashMob::TrashMob() {}
