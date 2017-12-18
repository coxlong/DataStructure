
//����

#ifndef _SORT_H_
#define _SORT_H_

//����
template<class T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//һ����������
//1.ֱ�Ӳ�������
template<class T>
void StraightInsertSort(T elem[], int n)
{
	for (int i = 1; i < n; i++)
	{	//��i��ֱ�Ӳ�������
		T e = elem[i];
		int j;
		for (j = i - 1; j >= 0 && e < elem[j]; j--)
			elem[j + 1] = elem[j];
		elem[j + 1] = e;
	}
}
//2.Shell����
template<class T>
void ShellInsert(T elem[], int n, int incr)
{
	for (int i = incr; i < n; i++)
	{
		T e = elem[i];
		int j;
		for (j = i - incr; j >= 0 && e < elem[j]; j -= incr)
			elem[j + incr] = elem[j];
		elem[j + incr] = e;
	}
}
template<class T>
void ShellSort(T elem[], int n, int inc[], int t)
{
	for (int k = 0; k < t; k++)
		ShellInsert(elem, n, inc[k]);
}

//������������
//1.��������
template<class T>
void BubbleSort(T elem[], int n)
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (elem[j] > elem[j + 1])
				Swap(elem[j], elem[j + 1]);
}
//2.��������
template<class T>
void QuickSortHelp(T elem[], int low, int high)
{
	if (low < high)
	{
		int l = low;
		int h = high;
		while (l < h)
		{
			while (l < h&&elem[h] >= elem[l])
			{	//elem[l]Ϊ���ᣬʹh�ұߵ�Ԫ�ز�С��elem[l]
				h--;
			}
			Swap(elem[l], elem[h]);

			while (l < h&&elem[l] <= elem[h])
			{	//elem[h]Ϊ���ᣬʹl��ߵ�Ԫ�ز�����elem[h]
				l++;
			}
			Swap(elem[l], elem[h]);
		}
		//��ʱl==h
		QuickSortHelp(elem, low, l - 1);
		QuickSortHelp(elem, h + 1, high);
	}
}
template<class T>
void QuickSort(T elem[], int n)
{
	QuickSortHelp(elem, 0, n - 1);
}

//����ѡ������
//1.��ѡ������
template<class T>
void SimpleSelectionSort(T elem[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < n; j++)
			if (elem[j] < elem[lowIndex])
				lowIndex = j;
		Swap(elem[i], elem[lowIndex]);
	}
}
//2.������
template<class T>
void SiftAdjust(T elem[], int low, int high)
//���������elem[low..high]�г���elem[low]���ⶼ����Ѷ��壬��
//��elem[low]ʹelem[low..high]��Ϊһ����Ѷ�
{
	for (int f = low, i = 2 * low + 1; i <= high; i = 2 * i + 1)
	{
		if (i < high&&elem[i] < elem[i + 1])
		{	//�Һ��Ӹ���iָ���Һ���
			i++;
		}
		if (elem[f] >= elem[i])
		{	//�ѳ�Ϊ��׶
			break;
		}
		Swap(elem[f], elem[i]);
		f = i;
	}
}
template<class T>
void HeapSort(T elem[], int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
		SiftAdjust(elem, i, n - 1);
	for (int i = n - 1; i > 0; --i)
	{
		Swap(elem[0], elem[i]);
		SiftAdjust(elem, 0, i - 1);
	}
}

//�ġ��鲢����
//1.2-·�鲢
template<class T>
void Merge(T elem[], T tmpElem[], int low, int mid, int high)
//���������������������elem[low..mid]��elem[mid+1..high]�鲢Ϊ�µ���������elem[low..high]
{
	int i = low, j = mid + 1, k = low;
	for (; i <= mid && j <= high; k++)
	{
		if (elem[i] <= elem[j])
			tmpElem[k] = elem[i++];
		else
			tmpElem[k] = elem[j++];
	}
	for (; i <= mid; i++)			//�鲢elem[low..mid]�е�ʣ��Ԫ��
		tmpElem[k++] = elem[i];
	for (; j <= high; j++)			//�鲢elem[mid+1..high]�е�ʣ��Ԫ��
		tmpElem[k++] = elem[j];
	for (i = low; i <= high; i++)
		elem[i] = tmpElem[i];
}
template<class T>
void MergeSortHelp(T elem[], T tmpElem[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSortHelp(elem, tmpElem, low, mid);
		MergeSortHelp(elem, tmpElem, mid + 1, high);
		Merge(elem, tmpElem, low, mid, high);
	}
}
template<class T>
void MergeSort(T elem[], int n)
{
	T *tmpElem = new T[n];
	MergeSortHelp(elem, tmpElem, 0, n - 1);
	delete[]tmpElem;
}

//�塢��������
#include "LinkList.h"
template<class T>
void Distribute(T elem[], int n, int r, int d, int i, LinkList<T> list[])
//��ʼ������rΪ������dΪ�ؼ���λ����list[0,r-1]Ϊ��������Ա�����
//������������е�i�˷���
{
	for (int power = (int)pow((double)r, i - 1), j = 0; j < n; j++)
	{
		int index = (elem[j] / power) % r;
		list[index].Insert(list[index].Length() + 1, elem[j]);
	}
}
template<class T>
void Colect(T elem[], int n, int r, int d, int i, LinkList<T> list[])
//��ʼ������rΪ������dΪ�ؼ���λ����list[0,r-1]Ϊ��������Ա�����
//������������е�i���ռ�
{
	for (int k = 0, j = 0; j < r; j++)
	{
		T tmpElem;
		while (!list[j].isEmpty())
		{
			list[j].Delete(1, tmpElem);
			elem[k++] = tmpElem;
		}
	}
}
template<class T>
void RadixSort(T elem[], int n, int r, int d)
//��ʼ������rΪ������dΪ�ؼ���λ��
{
	LinkList<T> *list = new LinkList<T>[r];
	for (int i = 1; i <= d; i++)
	{
		Distribute(elem, n, r, d, i, list);
		Colect(elem, n, r, d, i, list);
	}
	delete[]list;
}

#endif // !_SORT_H_
