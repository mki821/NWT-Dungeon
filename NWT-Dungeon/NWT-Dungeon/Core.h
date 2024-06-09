#pragma once
class Core {
private:
	Core();
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
};
