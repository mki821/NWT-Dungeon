#pragma once
class Enemy
{
public:
	Enemy(float atk, float health);
	virtual ~Enemy() = default;

	virtual float getStat() abstract;
protected:
	float m_atk;
	float m_helth;
};

class TrashMob : public Enemy
{
public:
	TrashMob(float atk, float health);
	virtual float getStat() override;
};

class Boss : public Enemy
{
public:
	Boss(float atk, float health);
	virtual float getStat() override;
};

