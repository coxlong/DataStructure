#include <iostream>
//#include "SqList.h"
//#include "LinkList.h"
//#include "CircLinkList.h"
//#include "DblLinkList.h"
//#include "SqStack.h"
//#include "Stack.h"
//#include "Queue.h"
//#include "SqQueue.h"
//#include "SortTime.h"
//#include "BinTree.h"
//#include "InThreadBinTree.h"
//#include "PreThreadBinTree.h"
//#include "AdjMatrixDirGraph.h"
//#include "AdjMatrixUndirGraph.h"
//#include "AdjMatrixUndirNetwork.h"
//#include "AdjListDirGraph.h"
//#include "AdjListUndirGraph.h"
#include "ChildSiblingTree.h"
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
//int main()
//{
//	Stack<int> s;
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
//	Stack<int> s2(s);
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

//Queue test
//int main()
//{
//	Queue<int> q;
//	for (int i = 10; i <= 20; i++)
//		q.InQueue(i);
//	q.Traverse(visit);
//	cout << endl;
//
//	int tmp;
//	q.GetHead(tmp);
//	cout << tmp << endl;
//
//	q.OutQueue(tmp);
//	q.Traverse(visit);
//	cout << endl;
//
//	q.InQueue(100);
//	q.Traverse(visit);
//	cout << endl;
//
//	Queue<int> q2(q);
//
//	q2.Traverse(visit);
//	cout << endl;
//
//	q2.InQueue(100);
//	q = q2;
//	q.Traverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//SqQueue test
//int main()
//{
//	SqQueue<int> q;
//	for (int i = 10; i <= 20; i++)
//		q.InQueue(i);
//	q.Traverse(visit);
//	cout << endl;
//
//	int tmp;
//	q.GetHead(tmp);
//	cout << tmp << endl;
//
//	q.OutQueue(tmp);
//	q.Traverse(visit);
//	cout << endl;
//
//	q.InQueue(100);
//	q.Traverse(visit);
//	cout << endl;
//
//	SqQueue<int> q2(q);
//
//	q2.Traverse(visit);
//	cout << endl;
//
//	q2.InQueue(100);
//	q = q2;
//	q.Traverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//Sort test
//int main()
//{
//	int size;
//
//
//	cout << "Num\t" << "Insert\t" << "Shell\t" << "Bubble\t" << "Quick\t" << "Select\t" << "Heap\t" << "Merge\t" << "Radix" << endl;
//
//	for (size = 5000; size <= 160000; size *= 2)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			SortTime(size);
//		}
//	}
//
//	system("pause");
//	return 0;
//}

//BinTree test
//int main() 
//{
//	int pre[] = { 1,2,4,7,3,5,6 };
//	int in[] = { 4,7,2,1,5,3,6 };
//	BinTree<int> bt = CreateBinTree(pre, in, 7);
//	DisplayBinTree(bt);
//
//	cout << "RecurPreOrder: ";
//	bt.RecurPreOrder(visit);
//	cout << endl << "RecurInOrder: ";
//	bt.RecurInOrder(visit);
//	cout << endl << "RecurPostOrder: ";
//	bt.RecurPostOrder(visit);
//	cout << endl << "NonRecurPreOrder: ";
//	bt.PreOrder(visit);
//	cout << endl << "NonRecurInOrder: ";
//	bt.InOrder(visit);
//	cout << endl << "NonRecurPostOrder: ";
//	bt.PostOrder(visit);
//
//	cout << endl << "LevelOrder: ";
//	bt.LevelOrder(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//InThreadBinTree test
//int main() 
//{
//	int pre[] = { 1,2,4,7,3,5,6 };
//	int in[] = { 4,7,2,1,5,3,6 };
//	BinTree<int> bt = CreateBinTree(pre, in, 7);
//	DisplayBinTree(bt);
//	cout << endl << "NonRecurInOrder: ";
//	bt.InOrder(visit);
//	cout << endl;
//
//	InThreadBinTree<int> threadTree(bt);
//	threadTree.InOrder(visit);
//	cout << endl;
//
//	InThreadBinTree<int> threadTree2(threadTree);
//	threadTree2.InOrder(visit);
//	cout << endl;
//
//	InThreadBinTree<int> threadTree3 = threadTree;
//	threadTree3.InOrder(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//PreThreadBinTree test
//int main()
//{
//	int pre[] = { 1,2,4,7,3,5,6 };
//	int in[] = { 4,7,2,1,5,3,6 };
//	BinTree<int> bt = CreateBinTree(pre, in, 7);
//	DisplayBinTree(bt);
//	cout << endl << "RecurPreOrder: ";
//	bt.RecurPreOrder(visit);
//	cout << endl;
//
//	PreThreadBinTree<int> tree(bt);
//	tree.PreOrder(visit);
//
//
//	system("pause");
//	return 0;
//}

//AdjMatrixDirGraph test
//int main()
//{
//	AdjMatrixDirGraph<int> g(9);
//	for (int i = 0; i < 9; i++)
//		g.SetElem(i, i);
//	g.InsertEdge(0, 1);
//	g.InsertEdge(0, 3);
//	g.InsertEdge(0, 4);
//	g.InsertEdge(1, 2);
//	g.InsertEdge(1, 4);
//	g.InsertEdge(2, 5);
//	g.InsertEdge(3, 6);
//	g.InsertEdge(4, 6);
//	g.InsertEdge(6, 7);
//	g.InsertEdge(7, 8);
//	g.ShowMatrix();
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//AdjMatrixUndirGraph test
//int main()
//{
//	AdjMatrixUndirGraph<int> g(9);
//	for (int i = 0; i < 9; i++)
//		g.SetElem(i, i);
//	g.InsertEdge(0, 1);
//	g.InsertEdge(0, 3);
//	g.InsertEdge(0, 4);
//	g.InsertEdge(1, 2);
//	g.InsertEdge(1, 4);
//	g.InsertEdge(2, 5);
//	g.InsertEdge(3, 6);
//	g.InsertEdge(4, 6);
//	g.InsertEdge(6, 7);
//	g.InsertEdge(7, 8);
//	g.ShowMatrix();
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	AdjMatrixUndirGraph<int> g2(g);
//	cout << "g2深度优先遍历：";
//	g2.DFSTraverse(visit);
//	cout << endl;
//	cout << "g2广度优先遍历：";
//	g2.BFSTraverse(visit);
//	cout << endl;
//	
//	g2.DeleteEdge(0, 1);
//	g = g2;
//	g.ShowMatrix();
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//AdjMatrixUndirNetwork test
//int main()
//{
//	AdjMatrixUndirNetwork<int, int> g(9);
//	for (int i = 0; i < 9; i++)
//		g.SetElem(i, i);
//	g.InsertEdge(0, 1, 1);
//	g.InsertEdge(0, 3, 1);
//	g.InsertEdge(0, 4, 1);
//	g.InsertEdge(1, 2, 1);
//	g.InsertEdge(1, 4, 1);
//	g.InsertEdge(2, 5, 1);
//	g.InsertEdge(3, 6, 1);
//	g.InsertEdge(4, 6, 1);
//	g.InsertEdge(6, 7, 1);
//	g.InsertEdge(7, 8, 1);
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	AdjMatrixUndirNetwork<int, int> g2(g);
//	cout << "g2深度优先遍历：";
//	g2.DFSTraverse(visit);
//	cout << endl;
//	cout << "g2广度优先遍历：";
//	g2.BFSTraverse(visit);
//	cout << endl;
//
//	g2.DeleteEdge(0, 1);
//	g = g2;
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//AdjListDirGraph test
//int main()
//{
//	AdjListDirGraph<int> g(9);
//	for (int i = 0; i < 9; i++)
//		g.SetElem(i, i);
//	g.InsertEdge(0, 1);
//	g.InsertEdge(0, 3);
//	g.InsertEdge(0, 4);
//	g.InsertEdge(1, 2);
//	g.InsertEdge(1, 4);
//	g.InsertEdge(2, 5);
//	g.InsertEdge(3, 6);
//	g.InsertEdge(4, 6);
//	g.InsertEdge(6, 7);
//	g.InsertEdge(7, 8);
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	AdjListDirGraph<int> g2(g);
//	cout << "g2深度优先遍历：";
//	g2.DFSTraverse(visit);
//	cout << endl;
//	cout << "g2广度优先遍历：";
//	g2.BFSTraverse(visit);
//	cout << endl;
//	
//	g2.DeleteEdge(0, 1);
//	g = g2;
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//AdjListUndirGraph test
//int main()
//{
//	AdjListUndirGraph<int> g(9);
//	for (int i = 0; i < 9; i++)
//		g.SetElem(i, i);
//	g.InsertEdge(0, 1);
//	g.InsertEdge(0, 3);
//	g.InsertEdge(0, 4);
//	g.InsertEdge(1, 2);
//	g.InsertEdge(1, 4);
//	g.InsertEdge(2, 5);
//	g.InsertEdge(3, 6);
//	g.InsertEdge(4, 6);
//	g.InsertEdge(6, 7);
//	g.InsertEdge(7, 8);
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	AdjListUndirGraph<int> g2(g);
//	cout << "g2深度优先遍历：";
//	g2.DFSTraverse(visit);
//	cout << endl;
//	cout << "g2广度优先遍历：";
//	g2.BFSTraverse(visit);
//	cout << endl;
//
//	g2.DeleteEdge(0, 1);
//	g = g2;
//	cout << "深度优先遍历：";
//	g.DFSTraverse(visit);
//	cout << endl;
//	cout << "广度优先遍历：";
//	g.BFSTraverse(visit);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//ChilSiblingTree test
int main()
{
	char items[] = "ABCDEFGH";
	int parents[] = { -1,0,0,0,1,1,3,3 };
	ChildSiblingTree<char> tree(items, parents, 0, 8);
	Display(tree);
	tree.PreRootOrder(visit);
	cout << endl;
	tree.PostRootOrder(visit);
	cout << endl;
	tree.LevelOrder(visit);
	cout << endl;

	ChildSiblingTree<char> tree2(tree);
	ChildSiblingTree<char> tree3 = tree;
	Display(tree2);
	Display(tree3);
	cout << tree.Degree() << endl;
	cout << tree.Height() << endl;

	system("pause");
	return 0;
}