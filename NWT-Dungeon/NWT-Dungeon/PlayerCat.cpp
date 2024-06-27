#include "define.h"
#include "PlayerCat.h"

void PlayerCat::Init() {
	Player::Init();

	m_maxHealth = 8;
	m_health = m_maxHealth;
	m_attack = 3;
	m_maxStamina = 15;
	m_stamina = m_maxStamina;

	m_character = CAT;
	m_characterSize = 14;
	m_characterOffset = -1;

	m_skills.push_back({ "������", 2, 6 });
	m_skills.push_back({ "����", 4, 10 });
}
