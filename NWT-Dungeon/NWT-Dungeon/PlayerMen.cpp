#include "define.h"
#include "PlayerMen.h"

void PlayerMen::Init() {
	m_health = m_maxHealth;
	m_attack = 3;
	m_stamina = m_maxStamina;

	m_character = MEN;
	m_characterSize = 11;
	m_characterOffset = 0;

	m_skills.push_back({ "�Ϲ� ����", 0, 3, "", MEN_ATTACK });
	m_skills.push_back({ "�����ġ��", 1, 5, "", MEN_ATTACK });
	m_skills.push_back({ "������ġ", 5, 10, "", MEN_ATTACK });

	Player::Init();
}
