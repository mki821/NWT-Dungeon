#pragma once
class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;
public:
	virtual void init();	
	virtual void Update();
	virtual void Render();
};

