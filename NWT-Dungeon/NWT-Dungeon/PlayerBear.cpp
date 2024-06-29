#include "define.h"
#include "PlayerBear.h"

void PlayerBear::Init() {
	Player::Init();

	m_maxHealth = 15;
	m_health = m_maxHealth;
	m_attack = 3;
	m_maxStamina = 8;
	m_stamina = m_maxStamina;

	m_character = BEAR;
	m_characterSize = 14;
	m_characterOffset = 2;

	m_skills.push_back({ "�Ϲ� ����", 0, 3, "", CAT_SCRATCH });
	m_skills.push_back({ "������", 2, 6 });
	m_skills.push_back({ "������", 3, 8 });
}
