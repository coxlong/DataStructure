
//有向图的邻接表类模板

#ifndef _ADJLISTDIRGRAPH_H_
#define _ADJLISTDIRGRAPH_H_

#include "AdjListGraphVexNode.h"
#include "Queue.h"

#define DEFAULT_SIZE 10

template<class T>
class AdjListDirGraph
{
public:
	AdjListDirGraph(T es[], int vertexNum = DEFAULT_SIZE);
	AdjListDirGraph(int vertexNum = DEFAULT_SIZE);
	~AdjListDirGraph();
	bool GetElem(int v, T &e) const;
	bool SetElem(int v, const T &e);
	int GetVexNum() const;
	int GetEdgeNum() const;
	void InsertEdge(int v1, int v2);
	void DeleteEdge(int v1, int v2);
	bool GetTag(int v) const;
	void SetTag(int v, bool val) const;
	AdjListDirGraph(const AdjListDirGraph<T> &copy);
	AdjListDirGraph<T> &operator=(const AdjListDirGraph<T> &copy);

	int FirstAdjVex(int v) const;
	int NextAdjVex(int v1, int v2) const;

	void DFSTraverse(void(*visit)(const T &)) const;
	void BFSTraverse(void(*visit)(const T &)) const;

protected:
	int vexNum, edgeNum;
	AdjListGraphVexNode<T> *adjList;	//由顶点数组组成的邻接表
	mutable bool *tag;

	void DestroyHelp();
	int IndexHelp(const LinkList<int> *la, int v) const;
	void DFS(int v, void(*visit)(const T &)) const;
	void BFS(int v, void(*visit)(const T &)) const;

};

template<class T>
void AdjListDirGraph<T>::DestroyHelp()
{
	for (int i = 0; i < vexNum; i++)
		if (adjList[i].adjLink != NULL)
			delete adjList[i].adjLink;
	delete[]adjList;
	delete[]tag;
}
template<class T>
int AdjListDirGraph<T>::IndexHelp(const LinkList<int> *la, int v) const
{//返回顶点v在邻接表中的位置
	int curPos, adjVex;
	for (curPos = 1; curPos <= la->Length(); curPos++)
	{
		la->GetElem(curPos, adjVex);
		if (adjVex == v)
			break;
	}
	return curPos;
}

template<class T>
AdjListDirGraph<T>::AdjListDirGraph(T es[], int vertexNum)
{
	vexNum = vertexNum;
	edgeNum = 0;
	adjList = new AdjListGraphVexNode<T>[vexNum];
	for (int i = 0; i < vexNum; i++)
		adjList[i].data = es[i];
	tag = new bool[vexNum];
}
template<class T>
AdjListDirGraph<T>::AdjListDirGraph(int vertexNum)
{
	vexNum = vertexNum;
	edgeNum = 0;
	adjList = new AdjListGraphVexNode<T>[vexNum];
	tag = new bool[vexNum];
}
template<class T>
AdjListDirGraph<T>::~AdjListDirGraph()
{
	DestroyHelp();
}
template<class T>
bool AdjListDirGraph<T>::GetElem(int v, T &e) const
{
	if (v < 0 || v >= vexNum)
		return false;
	else
	{
		e = adjList[v].data;
		return true;
	}
}
template<class T>
bool AdjListDirGraph<T>::SetElem(int v, const T &e)
{
	if (v<0 || v>vexNum)
		return false;
	else
	{
		adjList[v].data = e;
		return true;
	}
}
template<class T>
int AdjListDirGraph<T>::GetVexNum() const
{
	return vexNum;
}
template<class T>
int AdjListDirGraph<T>::GetEdgeNum() const
{
	return edgeNum;
}
template<class T>
void AdjListDirGraph<T>::InsertEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2)
	{
		if (adjList[v1].adjLink == NULL)
			adjList[v1].adjLink = new LinkList<int>;
		adjList[v1].adjLink->Insert(adjList[v1].adjLink->Length() + 1, v2);
		edgeNum++;
	}

}
template<class T>
void AdjListDirGraph<T>::DeleteEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2 && adjList[v1].adjLink != NULL)
	{
		int curPos = IndexHelp(adjList[v1].adjLink, v2);
		if (curPos <= adjList[v1].adjLink->Length())
		{
			adjList[v1].adjLink->Delete(curPos, v2);
			edgeNum--;
		}
	}
}
template<class T>
bool AdjListDirGraph<T>::GetTag(int v) const
{
	if (v >= 0 && v < vexNum&&tag[v])
		return true;
	else
		return false;
}
template<class T>
void AdjListDirGraph<T>::SetTag(int v, bool val) const
{
	if (v >= 0 && v < vexNum)
		tag[v] = val;
}
template<class T>
AdjListDirGraph<T>::AdjListDirGraph(const AdjListDirGraph<T> &copy)
{
	LinkList<int> *tmp;
	vexNum = copy.vexNum;
	edgeNum = copy.edgeNum;
	adjList = new AdjListGraphVexNode<T>[vexNum];
	for (int i = 0; i < vexNum; i++)
	{
		adjList[i].data = copy.adjList[i].data;
		if (copy.adjList[i].adjLink != NULL)
		{
			tmp = new LinkList<int>(*copy.adjList[i].adjLink);
			adjList[i].adjLink = tmp;
		}

	}
	tag = new bool[vexNum];
}
template<class T>
AdjListDirGraph<T> &AdjListDirGraph<T>::operator=(const AdjListDirGraph<T> &copy)
{
	if (&copy != this)
	{
		DestroyHelp();
		LinkList<int> *tmp;
		vexNum = copy.vexNum;
		edgeNum = copy.edgeNum;
		adjList = new AdjListGraphVexNode<T>[vexNum];
		for (int i = 0; i < vexNum; i++)
		{
			adjList[i].data = copy.adjList[i].data;
			if (copy.adjList[i].adjLink != NULL)
			{
				tmp = new LinkList<int>(*copy.adjList[i].adjLink);
				adjList[i].adjLink = tmp;
			}

		}
		tag = new bool[vexNum];
	}
	return *this;
}

template<class T>
int AdjListDirGraph<T>::FirstAdjVex(int v) const
{
	if (v < 0 || v >= vexNum || adjList[v].adjLink == NULL)
		return false;
	else
	{
		int adjVex;
		adjList[v].adjLink->GetElem(1, adjVex);
		return adjVex;
	}
}
template<class T>
int AdjListDirGraph<T>::NextAdjVex(int v1, int v2) const
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2 || adjList[v1].adjLink == NULL)
		return -1;
	else
	{
		int curPos = IndexHelp(adjList[v1].adjLink, v2);
		if (curPos < adjList[v1].adjLink->Length())
		{
			int adjVex;
			adjList[v1].adjLink->GetElem(curPos + 1, adjVex);
			return adjVex;
		}
		else
			return -1;	//不存在下一个邻接点
	}
}


template<class T>
void AdjListDirGraph<T>::DFS(int v, void(*visit)(const T &)) const
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
void AdjListDirGraph<T>::BFS(int v, void(*visit)(const T &)) const
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
void AdjListDirGraph<T>::DFSTraverse(void(*visit)(const T &)) const
{//对图进行深度优先遍历
	int v;
	for (v = 0; v < vexNum; v++)
		SetTag(v, false);
	for (v = 0; v < vexNum; v++)
		if (!GetTag(v))
			DFS(v, visit);
}
template<class T>
void AdjListDirGraph<T>::BFSTraverse(void(*visit)(const T &)) const
{//对图进行广度优先遍历
	int v;
	for (v = 0; v < vexNum; v++)
		SetTag(v, false);
	for (v = 0; v < vexNum; v++)
		if (!GetTag(v))
			BFS(v, visit);
}

#endif // !_ADJLISTDIRGRAPH_H_
