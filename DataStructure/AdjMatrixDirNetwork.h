
//有向网的领接矩阵类模板

#ifndef _ADJMATRIXDIRNETWORK_H_
#define _ADJMATRIXDIRNETWORK_H_

#include "Queue.h"

#define DEFAULT_SIZE 10
#define DEFAULT_INFINITY 0x7F

template<class ET,class WT>
class AdjMatrixDirNetwork
{
public:
	AdjMatrixDirNetwork(ET es[], int vertexNum = DEFAULT_SIZE, WT inf = DEFAULT_INFINITY);
	AdjMatrixDirNetwork(int vertexNum = DEFAULT_SIZE, WT inf = DEFAULT_INFINITY);
	~AdjMatrixDirNetwork();
	bool GetElem(int v, ET &e) const;
	bool SetElem(int v, const ET &e);
	WT GetInfinity() const;
	int GetVexNum() const;
	int GetEdgeNum() const;
	void InsertEdge(int v1, int v2, const WT &w);
	void DeleteEdge(int v1, int v2);
	WT GetWeight(int v1, int v2) const;
	void SetWeight(int v1, int v2, const WT &w);
	bool GetTag(int v) const;
	void SetTag(int v, bool val) const;
	AdjMatrixDirNetwork(const AdjMatrixDirNetwork<ET, WT> &copy);
	AdjMatrixDirNetwork<ET, WT> &operator=(const AdjMatrixDirNetwork<ET, WT> &copy);
	int FirstAdjVex(int v) const;
	int NextAdjVex(int v1, int v2) const;
	void DFSTraverse(void(*visit)(const ET &)) const;
	void BFSTraverse(void(*visit)(const ET &)) const;
	

protected:
	int vexNum, edgeNum;
	WT **Matrix;
	ET *elems;
	mutable bool *tag;
	WT infinity;			//无穷大

	void DestroyHelp();
	void DFS(int v, void(*visit)(const ET &)) const;
	void BFS(int v, void(*visit)(const ET &)) const;

};


template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::DestroyHelp()
{
	delete[]tag;
	delete[]elems;
	for (int i = 0; i < vexNum; i++)
		delete[]Matrix[i];
	delete[]Matrix;
}

template<class ET, class WT>
AdjMatrixDirNetwork<ET, WT>::AdjMatrixDirNetwork(ET es[], int vertexNum, WT inf)
{
	vexNum = vertexNum;
	edgeNum = 0;
	infinity = inf;
	Matrix = new WT*[vexNum];
	for (int i = 0; i < vexNum; i++)
	{
		Matrix[i] = new WT[vexNum];
		for (int j = 0; j < vexNum; j++)
			Matrix[i][j] = infinity;
	}
	elems = new ET[vexNum];
	for (int i = 0; i < vexNum; i++)
		elems[i] = es[i];
	tag = new bool[vexNum];
}
template<class ET, class WT>
AdjMatrixDirNetwork<ET, WT>::AdjMatrixDirNetwork(int vertexNum, WT inf)
{
	vexNum = vertexNum;
	edgeNum = 0;
	infinity = inf;
	Matrix = new WT*[vexNum];
	for (int i = 0; i < vexNum; i++)
	{
		Matrix[i] = new WT[vexNum];
		for (int j = 0; j < vexNum; j++)
			Matrix[i][j] = infinity;
	}
	elems = new ET[vexNum];
	tag = new bool[vexNum];
}
template<class ET, class WT>
AdjMatrixDirNetwork<ET, WT>::~AdjMatrixDirNetwork()
{
	DestroyHelp();
}
template<class ET, class WT>
bool AdjMatrixDirNetwork<ET, WT>::GetElem(int v, ET &e) const
{
	if (v < 0 || v >= vexNum)
		return false;
	else
	{
		e = elems[v];
		return true;
	}
}
template<class ET, class WT>
bool AdjMatrixDirNetwork<ET, WT>::SetElem(int v, const ET &e)
{
	if (v<0 || v>vexNum)
		return false;
	else
	{
		elems[v] = e;
		return true;
	}
}
template<class ET, class WT>
WT AdjMatrixDirNetwork<ET, WT>::GetInfinity() const
{
	return infinity;
}
template<class ET, class WT>
int AdjMatrixDirNetwork<ET, WT>::GetVexNum() const
{
	return vexNum;
}
template<class ET, class WT>
int AdjMatrixDirNetwork<ET, WT>::GetEdgeNum() const
{
	return edgeNum;
}
template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::InsertEdge(int v1, int v2, const WT &w)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2 && Matrix[v1][v2] == infinity)
	{
		Matrix[v1][v2] = w;
		edgeNum++;
	}
}
template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::DeleteEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2 && Matrix[v1][v2] != infinity)
	{
		Matrix[v1][v2] = infinity;
		edgeNum--;
	}
}
template<class ET, class WT>
WT AdjMatrixDirNetwork<ET, WT>::GetWeight(int v1, int v2) const
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2)
		return Matrix[v1][v2];
	else
		return infinity;
}
template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::SetWeight(int v1, int v2, const WT &w)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2)
		Matrix[v1][v2] = w;
}
template<class ET, class WT>
bool AdjMatrixDirNetwork<ET, WT>::GetTag(int v) const
{
	if (v >= 0 && v < vexNum&&tag[v])
		return true;
	else
		return false;
}
template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::SetTag(int v, bool val) const
{
	if (v >= 0 && v < vexNum)
		tag[v] = val;
}
template<class ET, class WT>
AdjMatrixDirNetwork<ET, WT>::AdjMatrixDirNetwork(const AdjMatrixDirNetwork<ET, WT> &copy)
{
	vexNum = copy.vexNum;
	edgeNum = copy.edgeNum;
	infinity = copy.infinity;
	Matrix = new WT*[vexNum];
	for (int i = 0; i < vexNum; i++)
	{
		Matrix[i] = new WT[vexNum];
		for (int j = 0; j < vexNum; j++)
			Matrix[i][j] = copy.Matrix[i][j];
	}
	elems = new ET[vexNum];
	for (int i = 0; i < vexNum; i++)
		elems[i] = copy.elems[i];
	tag = new bool[vexNum];
}
template<class ET, class WT>
AdjMatrixDirNetwork<ET, WT> &AdjMatrixDirNetwork<ET, WT>::operator=(const AdjMatrixDirNetwork<ET, WT> &copy)
{
	if (&copy != this)
	{
		DestroyHelp();
		vexNum = copy.vexNum;
		edgeNum = copy.edgeNum;
		infinity = copy.infinity;
		Matrix = new WT*[vexNum];
		for (int i = 0; i < vexNum; i++)
		{
			Matrix[i] = new WT[vexNum];
			for (int j = 0; j < vexNum; j++)
				Matrix[i][j] = copy.Matrix[i][j];
		}
		elems = new ET[vexNum];
		for (int i = 0; i < vexNum; i++)
			elems[i] = copy.elems[i];
		tag = new bool[vexNum];
	}
	return *this;
}
template<class ET, class WT>
int AdjMatrixDirNetwork<ET, WT>::FirstAdjVex(int v) const
{//返回顶点v的第一个领接点
	if (v < 0 || v >= vexNum)
		return -1;
	else
	{
		for (int i = 0; i < vexNum; i++)
			if (Matrix[v][i] != infinity)
				return i;
		return -1;	//循环结束，v没有邻接结点
	}
}
template<class ET, class WT>
int AdjMatrixDirNetwork<ET, WT>::NextAdjVex(int v1, int v2) const
{//返回顶点v1相对于v2的下一个领接点
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		return -1;
	else
	{
		for (int i = v2 + 1; i < vexNum; i++)
			if (Matrix[v1][i] != infinity)
				return i;
		return -1;	//循环结束，不存在下一个领接点
	}
}

template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::DFS(int v, void(*visit)(const ET &)) const
{//从顶点v出发进行深度优先搜索网
	SetTag(v, true);
	ET tmp;
	GetElem(v, tmp);
	(*visit)(tmp);
	for (int w = FirstAdjVex(v); w >= 0; w = NextAdjVex(v, w))
		if (!GetTag(w))
			DFS(w, visit);
}
template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::BFS(int v, void(*visit)(const ET &)) const
{//从顶点v出发进行广度优先搜索网
	SetTag(v, true);
	ET tmp;
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

template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::DFSTraverse(void(*visit)(const ET &)) const
{//对网进行深度优先遍历
	int v;
	for (v = 0; v < vexNum; v++)
		SetTag(v, false);
	for (v = 0; v < vexNum; v++)
		if (!GetTag(v))
			DFS(v, visit);
}
template<class ET, class WT>
void AdjMatrixDirNetwork<ET, WT>::BFSTraverse(void(*visit)(const ET &)) const
{//对网进行广度优先遍历
	int v;
	for (v = 0; v < vexNum; v++)
		SetTag(v, false);
	for (v = 0; v < vexNum; v++)
		if (!GetTag(v))
			BFS(v, visit);
}

#endif // !_ADJMATRIXDIRNETWORK_H_
