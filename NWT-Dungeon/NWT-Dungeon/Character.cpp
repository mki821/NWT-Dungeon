#include "Character.h"

std::wstring* Character::GetCharacter() {
    return m_character;
}

int Character::GetCharacterSize()
{
    return m_characterSize;
}

int Character::GetCharacterOffset() {
	return m_characterOffset;
}

void Character::ApplyDamage(int damage) {
	SetHealth(m_health - damage);
}

int Character::GetHealth() const {
    return m_health;
}

void Character::SetHealth(int value) {
	if (value < 0) m_health = 0;
	else if (value > m_maxHealth) m_health = m_maxHealth;
	else m_health = value;
}

int Character::GetAttack() const {
	return m_attack;
}

int Character::GetStamina() const {
	return m_stamina;
}

bool Character::SetStamina(int value) {
	if (value < 0) return false;

	if (value > m_maxStamina) m_stamina = m_maxStamina;
	else m_stamina = value;

	return true;
}
