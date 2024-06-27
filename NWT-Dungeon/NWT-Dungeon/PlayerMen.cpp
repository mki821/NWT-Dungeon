#include "define.h"
#include "PlayerMen.h"

void PlayerMen::Init() {
	Player::Init();

	m_health = m_maxHealth;
	m_attack = 3;
	m_stamina = m_maxStamina;

	m_character = MEN;
	m_characterSize = 11;
	m_characterOffset = 0;

	m_skills.push_back({ "¸öÅë¹ÚÄ¡±â", 1, 5 });
	m_skills.push_back({ "Èû²¯ÆİÄ¡", 5, 10 });
}
