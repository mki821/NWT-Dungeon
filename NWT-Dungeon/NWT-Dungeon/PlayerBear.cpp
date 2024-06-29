#include "define.h"
#include "PlayerBear.h"

void PlayerBear::Init() {
	m_maxHealth = 15;
	m_health = m_maxHealth;
	m_attack = 3;
	m_maxStamina = 8;
	m_stamina = m_maxStamina;

	m_character = BEAR;
	m_characterSize = 16;
	m_characterOffset = 2;

	m_skills.push_back({ "일반 공격", 0, 3, "", BEAR_ATTACK });
	m_skills.push_back({ "할퀴기", 2, 6, "", BEAR_ATTACK });
	m_skills.push_back({ "누르기", 3, 8, "", BEAR_ATTACK });

	Player::Init();
}
