#include <functional>
#include "define.h"
#include "PlayerCat.h"

void PlayerCat::Init() {
	m_maxHealth = 8;
	m_health = m_maxHealth;
	m_attack = 3;
	m_maxStamina = 15;
	m_stamina = m_maxStamina;

	m_character = CAT;
	m_characterSize = 14;
	m_characterOffset = -1;

	m_skills.push_back({ "일반 공격", 0, 3, "", CAT_SCRATCH });
	m_skills.push_back({ "할퀴기", 2, 6, "", CAT_SCRATCH });
	m_skills.push_back({ "물기", 4, 10, "", CAT_SCRATCH });

	Player::Init();
}
