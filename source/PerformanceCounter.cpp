#include "PerformanceCounter.h"

PerformanceCounter& PerformanceCounter::instance()
{
	static PerformanceCounter result;
	return result;
}

void PerformanceCounter::start()
{
	QueryPerformanceCounter(&start_);
}

double PerformanceCounter::stop()
{
	LARGE_INTEGER now;
	QueryPerformanceCounter(&now);
	return static_cast<double>(now.QuadPart - start_.QuadPart) / static_cast<double>(frequency_.QuadPart);
}

PerformanceCounter::PerformanceCounter()
{
	QueryPerformanceFrequency(&frequency_);
}

