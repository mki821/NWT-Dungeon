#include "Enemy.h"

void Enemy::Init() {
	m_health = m_maxHealth;
	m_attack = 3;
	m_stamina = m_maxStamina;

	m_character = TrashMobVisual;
	m_characterSize = 10;
}

void Enemy::NormalAttack() {}
