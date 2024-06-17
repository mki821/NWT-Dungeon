#pragma once
#include "Player.h"

class Core {
private:
	Core() = default;
	static Core* m_pInstance;
public:
	static Core* GetInst() {
		if(m_pInstance == nullptr)
			m_pInstance = new Core;

		return m_pInstance;
	}
	static void DestroyInst() {
		if(m_pInstance != nullptr)
			delete m_pInstance;

		m_pInstance = nullptr;
	}
public:
	bool Init();
	void Run();
private:
	void Update();
	void Render();
	void FrameSync(int frameRate);
private:
	int _select = 0;

	char _ui[14][128];
	void UISet(int x, int y, std::string value);

	Player* m_player;
};
