#include "define.h"
#include "Enemy.h"

Boss::Boss() {}

void Boss::Init()
{
	m_attack = 5;
	m_health = 10;

	m_character = BossSword;
	m_characterSize = 16;
	m_characterOffset = -1;
}

void Boss::BossSkil()
{
	cout << "보스 스킬";
	SetStamina(m_maxStamina - 1);
}
