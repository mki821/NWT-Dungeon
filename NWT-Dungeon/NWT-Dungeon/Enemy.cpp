#include "Enemy.h"

void Enemy::Init() {}

void Enemy::Attack(Player* player)
{
}


int Enemy::ModifyStat(int stat)
{
	int* stage = Core::GetInst()->GetStageNum();

	return stat + std::floor((*stage) / 5 * 2);	

}

int Enemy::RandomValue(int min, int max)
{
	if (min > max) {
		std::swap(min, max);
	}

	int range = max - min + 1;
	int random = rand() % range + min;

	return random;		
}
