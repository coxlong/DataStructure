#ifndef _RAND_H_
#define _RAND_H_

#include <cstdlib>
#include <ctime>

class Rand
{
public:
	static void SetRandSeed() { srand((unsigned)time(NULL)); }
	static int GetRand(int n = 100000) { return rand() % n; }
};

#endif // !_RAND_H_
