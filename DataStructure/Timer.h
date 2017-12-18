#ifndef _TIMER_H_
#define _TIMER_H_

#include <ctime>

class Timer
{
public:
	Timer();
	double ElapsedTime();
	void Reset();
private:
	clock_t startTime;
};

#endif // !_TIMER_H_