#ifndef _SORTTIME_H_
#define _SORTTIME_H_
#include "Timer.h"
#include "Rand.h"
#include "Sort.h"
#include <iostream>
using namespace std;
void CreatArray(int a[], int n)
{
	Rand::SetRandSeed();
	for (int i = 0; i < n; i++)
		a[i] = Rand::GetRand();
}

void SortTime(int size)
{
	int *a;
	a = new int[size];
	double time;
	Timer objTime;
	
	cout << size << "\t";

	CreatArray(a, size);
	objTime.Reset();
	StraightInsertSort(a, size);
	time = objTime.ElapsedTime();
	cout << time << "s\t";

	int t = int(log((float)size + 1) / log((float)2)) - 1;
	int *inc = new int[t];
	for (int i = 0; i < t; i++)
		inc[i] = (int)pow((double)2, t - i) - 1;
	CreatArray(a, size);
	objTime.Reset();
	ShellSort(a, size, inc, t);
	time = objTime.ElapsedTime();
	cout << time << "s\t";
	delete[]inc;

	CreatArray(a, size);
	objTime.Reset();
	BubbleSort(a, size);
	time = objTime.ElapsedTime();
	cout << time << "s\t";

	CreatArray(a, size);
	objTime.Reset();
	QuickSort(a, size);
	time = objTime.ElapsedTime();
	cout << time << "s\t";

	CreatArray(a, size);
	objTime.Reset();
	SimpleSelectionSort(a, size);
	time = objTime.ElapsedTime();
	cout << time << "s\t";

	CreatArray(a, size);
	objTime.Reset();
	HeapSort(a, size);
	time = objTime.ElapsedTime();
	cout << time << "s\t";

	CreatArray(a, size);
	objTime.Reset();
	MergeSort(a, size);
	time = objTime.ElapsedTime();
	cout << time << "s\t";

	CreatArray(a, size);
	objTime.Reset();
	RadixSort(a, size, 10, 5);
	time = objTime.ElapsedTime();
	cout << time << "s";

	cout << endl;

	delete[]a;
}

#endif // !_SORTTIME_H_
