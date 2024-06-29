#include <Windows.h>
#include "GameLogic.h"

bool ChooseIndex(int min, int max, bool horizontal, int& select) {	
	if (GetAsyncKeyState(VK_SPACE) & 0x0001) return true;

	if (horizontal) {
		if (GetAsyncKeyState(VK_LEFT) & 0x0001) --select;
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001) ++select;
	}
	else {
		if (GetAsyncKeyState(VK_UP) & 0x0001) --select;
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) ++select;
	}

	if (select < min) select = min;
	else if (select > max) select = max;

	return false;
}
