#include <iostream>
#include "Core.h"

int main() {
	if (!Core::GetInst()->Init()) {
		std::cout << "Game Init Error" << std::endl;
		Core::DestroyInst();
		return 0;
	}
	Core::GetInst()->Run();

	Core::DestroyInst();
}