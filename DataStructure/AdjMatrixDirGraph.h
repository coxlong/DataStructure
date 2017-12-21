
//有向图的邻接矩阵类模板

#ifndef _ADJMATRIXDIRGRAPH_H_
#define _ADJMATRIXDIRGRAPH_H_

#include "Queue.h"

#define DEFAULT_SIZE 10

template<class T>
class AdjMatrixDirGraph
{
public:
	AdjMatrixDirGraph(T es[], int vertexNum = DEFAULT_SIZE);
	AdjMatrixDirGraph(int vertexNum = DEFAULT_SIZE);
	~AdjMatrixDirGraph();
	bool GetElem(int v, T &e) const;
	bool SetElem(int v, const T &e);
	int GetVexNum() const;
	int GetEdgeNum() const;
	void InsertEdge(int v1, int v2);
	void DeleteEdge(int v1, int v2);
	bool GetTag(int v) const;
	void SetTag(int v, bool val) const;
	AdjMatrixDirGraph(const AdjMatrixDirGraph<T> &copy);
	AdjMatrixDirGraph<T> &operator=(const AdjMatrixDirGraph<T> &copy);

	int FirstAdjVex(int v) const;
	int NextAdjVex(int v1, int v2) const;
	void DFSTraverse(void(*visit)(const T &)) const;
	void BFSTraverse(void(*visit)(const T &)) const;


	void ShowMatrix()
	{
		for (int i = 0; i < vexNum; i++)
		{
			for (int j = 0; j < vexNum; j++)
				std::cout << Matrix[i][j] << " ";
			std::cout << endl;
		}
	}

protected:
	int vexNum, edgeNum;
	int **Matrix;
	T *elems;
	mutable bool *tag;		//指向标志数组的指针

	void DestroyHelp();
	void DFS(int v, void(*visit)(const T &)) const;
	void BFS(int v, void(*visit)(const T &)) const;
};

template<class T>
void AdjMatrixDirGraph<T>::DestroyHelp()
{
	delete[]elems;
	delete[]tag;
	for (int i = 0; i < vexNum; i++)
		delete[]Matrix[i];
	delete[]Matrix;
}

template<class T>
AdjMatrixDirGraph<T>::AdjMatrixDirGraph(T es[], int vertexNum)
{
	vexNum = vertexNum;
	edgeNum = 0;
	Matrix = new int[vexNum];
	for (int i = 0; i < vexNum; i++)
	{
		Matrix[i] = new int[vexNum];
		for (int j = 0; j < vexNum; j++)
			Matrix[i][j] = 0;
	}
	elems = new T[vexNum];
	for (int i = 0; i < vexNum; i++)
		elems[i] = es[i];
	tag = new bool[vexNum];
}
template<class T>
AdjMatrixDirGraph<T>::AdjMatrixDirGraph(int vertexNum)
{
	vexNum = vertexNum;
	edgeNum = 0;
	Matrix = new int*[vexNum];
	for (int i = 0; i < vexNum; i++)
	{
		Matrix[i] = new int[vexNum];
		for (int j = 0; j < vexNum; j++)
			Matrix[i][j] = 0;
	}
	elems = new T[vexNum];
	tag = new bool[vexNum];
}
template<class T>
AdjMatrixDirGraph<T>::~AdjMatrixDirGraph()
{
	DestroyHelp();
}
template<class T>
bool AdjMatrixDirGraph<T>::GetElem(int v, T &e) const
{
	if (v < 0 || v >= vexNum)
		return false;
	else
	{
		e = elems[v];
		return true;
	}
}
template<class T>
bool AdjMatrixDirGraph<T>::SetElem(int v, const T &e)
{
	if (v<0 || v>vexNum)
		return false;
	else
	{
		elems[v] = e;
		return true;
	}
}
template<class T>
int AdjMatrixDirGraph<T>::GetVexNum() const
{
	return vexNum;
}
template<class T>
int AdjMatrixDirGraph<T>::GetEdgeNum() const
{
	return edgeNum;
}
template<class T>
void AdjMatrixDirGraph<T>::InsertEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2 && Matrix[v1][v2] == 0)
	{
		Matrix[v1][v2] = 1;
		edgeNum++;
	}
}
template<class T>
void AdjMatrixDirGraph<T>::DeleteEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2 && Matrix[v1][v2] == 1)
	{
		Matrix[v1][v2] = 0;
		edgeNum--;
	}
}
template<class T>
bool AdjMatrixDirGraph<T>::GetTag(int v) const
{
	if (v >= 0 && v < vexNum&&tag[v])
		return true;
	else
		return false;
}
template<class T>
void AdjMatrixDirGraph<T>::SetTag(int v, bool val) const
{
	if (v >= 0 && v < vexNum)
		tag[v] = val;
}
template<class T>
AdjMatrixDirGraph<T>::AdjMatrixDirGraph(const AdjMatrixDirGraph<T> &copy)
{
	vexNum = copy.vexNum;
	edgeNum = copy.edgeNum;
	Matrix = new int*[vexNum];
	for (int i = 0; i < vexNum; i++)
	{
		Matrix[i] = new int[vexNum];
		for (int j = 0; j < vexNum; j++)
			Matrix[i][j] = copy.Matrix[i][j];
	}
	elems = new T[vexNum];
	for (int i = 0; i < vexNum; i++)
		elems[i] = copy.elems[i];
	tag = new bool[vexNum];
}
template<class T>
AdjMatrixDirGraph<T> &AdjMatrixDirGraph<T>::operator=(const AdjMatrixDirGraph<T> &copy)
{
	if (&copy != this)
	{
		DestroyHelp();
		vexNum = copy.vexNum;
		edgeNum = copy.edgeNum;
		Matrix = new int*[vexNum];
		for (int i = 0; i < vexNum; i++)
		{
			Matrix[i] = new int[vexNum];
			for (int j = 0; j < vexNum; j++)
				Matrix[i][j] = copy.Matrix[i][j];
		}
		elems = new T[vexNum];
		for (int i = 0; i < vexNum; i++)
			elems[i] = copy.elems[i];
		tag = new bool[vexNum];
	}
	return *this;
}

template<class T>
int AdjMatrixDirGraph<T>::FirstAdjVex(int v) const
{//返回顶点v的第一个邻接点
	if (v < 0 || v >= vexNum)
		return -1;
	else
	{
		for (int i = 0; i < vexNum; i++)
			if (Matrix[v][i] == 1)
				return i;
		return -1;	//循环结束，v没有邻接结点
	}
}
template<class T>
int AdjMatrixDirGraph<T>::NextAdjVex(int v1, int v2) const
{//返回顶点v1相对于v2的下一个邻接点
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		return -1;
	else
	{
		for (int i = v2 + 1; i < vexNum; i++)
			if (Matrix[v1][i] == 1)
				return i;
		return -1;	//循环结束，不存在下一个邻接点
	}
}

template<class T>
void AdjMatrixDirGraph<T>::DFS(int v, void(*visit)(const T &)) const
{//从顶点v出发进行深度优先搜索图
	SetTag(v, true);
	T tmp;
	GetElem(v, tmp);
	(*visit)(tmp);
	for (int w = FirstAdjVex(v); w >= 0; w = NextAdjVex(v, w))
		if (!GetTag(w))
			DFS(w, visit);
}
template<class T>
void AdjMatrixDirGraph<T>::BFS(int v, void(*visit)(const T &)) const
{//从顶点v出发进行广度优先搜索图
	SetTag(v, true);
	T tmp;
	GetElem(v, tmp);
	(*visit)(tmp);
	Queue<int> q;
	q.InQueue(v);
	while (!q.isEmpty())
	{
		int u, w;
		q.OutQueue(u);
		for (w = FirstAdjVex(u); w >= 0; w = NextAdjVex(u, w))
		{
			if (!GetTag(w))
			{
				SetTag(w, true);
				GetElem(w, tmp);
				(*visit)(tmp);
				q.InQueue(w);
			}
		}
	}
}

template<class T>
void AdjMatrixDirGraph<T>::DFSTraverse(void(*visit)(const T &)) const
{//对图进行深度优先遍历
	int v;
	for (v = 0; v < vexNum; v++)
		SetTag(v, false);
	for (v = 0; v < vexNum; v++)
		if (!GetTag(v))
			DFS(v, visit);
}
template<class T>
void AdjMatrixDirGraph<T>::BFSTraverse(void(*visit)(const T &)) const
{//对图进行广度优先遍历
	int v;
	for (v = 0; v < vexNum; v++)
		SetTag(v, false);
	for (v = 0; v < vexNum; v++)
		if (!GetTag(v))
			BFS(v, visit);
}

#endif // !_ADJMATRIXDIRGRAPH_H_
