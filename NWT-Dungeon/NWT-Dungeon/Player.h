#pragma once

enum class PlayerSkillEnum {
	Attack, Tackle
};

class Player {
public:
	void ApplyDamage(int damage);
	void Attack(PlayerSkillEnum way);
	//void Attack(Eenmy* target, PlayerSkillEnum way);
private:
	//Enemy* _targetPtr;
	void CommonAttack();
	void Tackle();
public:
	int GetHealth();
	void SetHealth(int value);
	int GetAttack();
	int GetStamina();
private:
	int _health;
	int _attack;
	int _stamina;
	int _maxHealth;
};