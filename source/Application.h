#pragma once

#include <vector>
#include "Mouse.h"
#include "Renderer.h"
#include "Cloth.h"

struct Application 
{
public:
	Application() = default;
	~Application() = default;
	
	bool IsRunning() const;

	void Setup(int clothWidth, int clothHeight, int clothSpacing);
	void Input();
	void Update();
	void Render() const;
	void Destroy();

private:
	Renderer* renderer = nullptr;
	Mouse* mouse = nullptr;
	Cloth* cloth = nullptr;

	bool isRunning = false;

	Uint32 lastUpdateTime;

	int frames_{ 0 };
	double framesTime_{ 0.0 };
};