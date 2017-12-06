#include <iostream>
//#include "SqList.h"
//#include "LinkList.h"
//#include "CircLinkList.h"
//#include "DblLinkList.h"
//#include "SqStack.h"
#include "Stack.h"
using namespace std;

template<class T>
void visit(const T &e)
{
	cout << e << " ";
}

//SqList Test
//int main()
//{
//	SqList<int> s;
//	for (int i = 1; i <= 10; i++)
//		s.Insert(i, i);
//	s.Traverse(visit);
//	cout << endl;
//
//	SqList<int> s2(s);
//	s2.Insert(5, 100);
//	s2.Traverse(visit);
//	cout << endl;
//
//	s = s2;
//	s.Traverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//LinkList Test
//int main()
//{
//	LinkList<int> l;
//	for (int i = 10; i <= 20; i++)
//		l.Insert(1, i);
//	l.Traverse(visit);
//	cout << endl;
//
//	int tmp;
//	l.GetElem(5, tmp);
//	cout << tmp << endl;
//
//	l.Delete(5, tmp);
//	l.Traverse(visit);
//	cout << endl;
//
//	l.Insert(5, 100);
//	l.Traverse(visit);
//	cout << endl;
//
//	LinkList<int> l2(l);
//
//	l2.Traverse(visit);
//	cout << endl;
//
//	l2.Insert(5, 100);
//	l = l2;
//	l.Traverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//CircLinkList test
//int main()
//{
//	CircLinkList<int> l;
//	for (int i = 10; i <= 20; i++)
//		l.Insert(1, i);
//	l.Traverse(visit);
//	cout << endl;
//
//	int tmp;
//	l.GetElem(5, tmp);
//	cout << tmp << endl;
//
//	l.Delete(5, tmp);
//	l.Traverse(visit);
//	cout << endl;
//
//	l.Insert(5, 100);
//	l.Traverse(visit);
//	cout << endl;
//
//	CircLinkList<int> l2(l);
//
//	l2.Traverse(visit);
//	cout << endl;
//
//	l2.Insert(5, 100);
//	l = l2;
//	l.Traverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//DblLinkList Test
//int main()
//{
//	DblLinkList<int> l;
//	for (int i = 10; i <= 20; i++)
//		l.Insert(1, i);
//	l.Traverse(visit);
//	cout << endl;
//
//	int tmp;
//	l.GetElem(5, tmp);
//	cout << tmp << endl;
//
//	l.Delete(5, tmp);
//	l.Traverse(visit);
//	cout << endl;
//
//	l.Insert(5, 100);
//	l.Traverse(visit);
//	cout << endl;
//
//	DblLinkList<int> l2(l);
//
//	l2.Traverse(visit);
//	cout << endl;
//
//	l2.Insert(5, 100);
//	l = l2;
//	l.Traverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//SqStack test
//int main()
//{
//	SqStack<int> s;
//	for (int i = 10; i <= 20; i++)
//		s.Push(i);
//	s.Traverse(visit);
//	cout << endl;
//
//	int tmp;
//	s.Top(tmp);
//	cout << tmp << endl;
//
//	s.Pop(tmp);
//	s.Traverse(visit);
//	cout << endl;
//
//	s.Push(100);
//	s.Traverse(visit);
//	cout << endl;
//
//	SqStack<int> s2(s);
//
//	s2.Traverse(visit);
//	cout << endl;
//
//	s2.Push(100);
//	s = s2;
//	s.Traverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//Stack test
int main()
{
	Stack<int> s;
	for (int i = 10; i <= 20; i++)
		s.Push(i);
	s.Traverse(visit);
	cout << endl;

	int tmp;
	s.Top(tmp);
	cout << tmp << endl;

	s.Pop(tmp);
	s.Traverse(visit);
	cout << endl;

	s.Push(100);
	s.Traverse(visit);
	cout << endl;

	Stack<int> s2(s);

	s2.Traverse(visit);
	cout << endl;

	s2.Push(100);
	s = s2;
	s.Traverse(visit);
	cout << endl;

	system("pause");
	return 0;
}