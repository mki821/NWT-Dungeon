#include <iostream>
#include <io.h>
#include <ctime>
#include "Core.h"
#include "Scene.h"

void Init();

int main() {
	Init();

	Scene* scene = new Scene;

	if (scene->ShowScene(SceneType::Title()) > 1) return 0;

	if (scene->ShowScene(SceneType::Title()) == 1) {	
		exit(0);
		return 0;
	}
	scene->SceneAnimation();

	if (!Core::GetInst()->Init()) {
		std::cout << "Game Init Error" << std::endl;
		Core::DestroyInst();
		return 0;
	}
	Core::GetInst()->Run();

	Core::DestroyInst();
}

void Init() {
	srand((unsigned int)time(NULL));

	system("title NWT_DUNGEON | mode con cols=140 lines=40");
	LockResize();
	CursorVisible(false, 1);
}
