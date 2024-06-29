#include <iostream>
#include <io.h>
#include <ctime>
#include "Core.h"
#include "TitleScene.h";

int main() {
	srand((unsigned int)time(NULL));

	TitleScene* title = new TitleScene;

	if (title->Title() > 1) return 0;

	if (title->Title() == 1) {
		exit(0);
		return 0;
	}
	title->SceneAnimation();

	if (!Core::GetInst()->Init()) {
		std::cout << "Game Init Error" << std::endl;
		Core::DestroyInst();
		return 0;
	}
	Core::GetInst()->Run();

	Core::DestroyInst();
}