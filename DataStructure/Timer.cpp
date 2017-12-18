#include "Timer.h"

Timer::Timer()
{
	startTime = clock();
}

double Timer::ElapsedTime()
{
	clock_t endTime = clock();
	return (double)(endTime - startTime) / (double)CLK_TCK;
}

void Timer::Reset()
{
	startTime = clock();
}