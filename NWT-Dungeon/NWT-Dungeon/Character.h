#pragma once

#include <string>

class Character
{
public:
	std::wstring* GetCharacter();
	int GetCharacterSize();
	int GetCharacterOffset();
protected:
	std::wstring* m_character;
	int m_characterSize;
	int m_characterOffset = 0;
public:
	void ApplyDamage(int damage);
public:
	int GetHealth() const;
	void SetHealth(int value);
	int GetAttack() const;
	int GetStamina() const;
	bool SetStamina(int value);
protected:
	int m_health;
	int m_maxHealth = 10;
	int m_attack;
	int m_stamina;
	int m_maxStamina = 5;
};

