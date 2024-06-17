#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "define.h"
using namespace std;

int main() {
	//Player player;

	//while (true) {
	//	if (GetAsyncKeyState('Q') & 0x8000) {
	//		player.Attack(PlayerSkillEnum::Attack);
	//		break;
	//	}
	//	else if (GetAsyncKeyState('W') & 0x8000) {
	//		player.Attack(PlayerSkillEnum::Tackle);
	//		break;
	//	}
	//	Sleep(100);
	//}

	for (int i = 0; i < 11; ++i) {
		cout << MEN[i] << endl;
	}
}