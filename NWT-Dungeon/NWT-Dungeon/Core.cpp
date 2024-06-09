#include <fstream>
#include "Core.h"

bool Core::Init() {
	return false;
}

void Core::Run() {
	while (true) {
		Update();
		Render();
		FrameSync(60);
	}
}

void Core::Update() {

}

void Core::Render() {

}

void Core::FrameSync(int frameRate) {
	clock_t oldTime = clock();
	clock_t curTime;

	while (true) {
		curTime = clock();
		if (curTime - oldTime > 1000 / frameRate) {
			oldTime = curTime;
			break;
		}
	}
}
