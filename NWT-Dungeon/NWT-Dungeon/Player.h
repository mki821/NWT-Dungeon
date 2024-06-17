#pragma once

enum class PlayerSkillEnum {
	Attack, Tackle
};

class Player {
public:
	void Init();
	void ApplyDamage(int damage);
	int ChooseAttack();
	bool Attack(PlayerSkillEnum way);
	//void Attack(Eenmy* target, PlayerSkillEnum way);
private:
	//Enemy* _targetPtr;
	void CommonAttack();
	void Tackle();
private:
	const int _commonAttackStamina = 1;
	const int _tackleStamina = 2;
public:
	int GetHealth() const;
	void SetHealth(int value);
	int GetAttack() const;
	int GetStamina() const;
	bool SetStamina(int value);
private:
	int _health;
	int _maxHealth = 10;
	int _attack;
	int _stamina;
	int _maxStamina = 5;
};