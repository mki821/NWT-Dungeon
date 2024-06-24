#include "Enemy.h"

void Enemy::Init() {
	srand(unsigned int(time(NULL)));
}

Player* Enemy::SetTarget() {
	int randTarget = rand() % 2;
	Player* targetPlayer = Core::GetInst()->GetPlayers()[randTarget];

	return targetPlayer;
}

void Enemy::NormalAttack() {}
