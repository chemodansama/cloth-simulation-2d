#pragma once

#include <windows.h>

class PerformanceCounter
{
public:
	static PerformanceCounter &instance();

	void start();
	double stop();

private:
	PerformanceCounter();

	LARGE_INTEGER frequency_;
	LARGE_INTEGER start_;
};