
//����ͼ����Ӿ�����ģ��

#ifndef _ADJMATRIXUNDIRGRAPH_H_
#define _ADJMATRIXUNDIRGRAPH_H_

#include "Queue.h"

#define DEFAULT_SIZE 10

template<class T>
class AdjMatrixUndirGraph
{
public:
	AdjMatrixUndirGraph(T es[], int vertexNum = DEFAULT_SIZE);
	AdjMatrixUndirGraph(int vertexNum = DEFAULT_SIZE);
	~AdjMatrixUndirGraph();
	bool GetElem(int v, T &e) const;
	bool SetElem(int v, const T &e);
	int GetVexNum() const;
	int GetEdgeNum() const;
	void InsertEdge(int v1, int v2);
	void DeleteEdge(int v1, int v2);
	bool GetTag(int v) const;
	void SetTag(int v, bool val) const;
	AdjMatrixUndirGraph(const AdjMatrixUndirGraph<T> &copy);
	AdjMatrixUndirGraph<T> &operator=(const AdjMatrixUndirGraph<T> &copy);

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
	mutable bool *tag;		//ָ���־�����ָ��

	void DestroyHelp();
	void DFS(int v, void(*visit)(const T &)) const;
	void BFS(int v, void(*visit)(const T &)) const;
};

template<class T>
void AdjMatrixUndirGraph<T>::DestroyHelp()
{
	delete[]elems;
	delete[]tag;
	for (int i = 0; i < vexNum; i++)
		delete[]Matrix[i];
	delete[]Matrix;
}

template<class T>
AdjMatrixUndirGraph<T>::AdjMatrixUndirGraph(T es[], int vertexNum)
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
AdjMatrixUndirGraph<T>::AdjMatrixUndirGraph(int vertexNum)
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
AdjMatrixUndirGraph<T>::~AdjMatrixUndirGraph()
{
	DestroyHelp();
}
template<class T>
bool AdjMatrixUndirGraph<T>::GetElem(int v, T &e) const
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
bool AdjMatrixUndirGraph<T>::SetElem(int v, const T &e)
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
int AdjMatrixUndirGraph<T>::GetVexNum() const
{
	return vexNum;
}
template<class T>
int AdjMatrixUndirGraph<T>::GetEdgeNum() const
{
	return edgeNum;
}
template<class T>
void AdjMatrixUndirGraph<T>::InsertEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2 && Matrix[v1][v2] == 0 && Matrix[v2][v1] == 0)
	{
		Matrix[v1][v2] = Matrix[v2][v1] = 1;
		edgeNum++;
	}
}
template<class T>
void AdjMatrixUndirGraph<T>::DeleteEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < vexNum&&v2 >= 0 && v2 < vexNum&&v1 != v2 && Matrix[v1][v2] == 1 && Matrix[v2][v1] == 1)
	{
		Matrix[v1][v2] = Matrix[v2][v1] = 0;
		edgeNum--;
	}
}
template<class T>
bool AdjMatrixUndirGraph<T>::GetTag(int v) const
{
	if (v >= 0 && v < vexNum&&tag[v])
		return true;
	else
		return false;
}
template<class T>
void AdjMatrixUndirGraph<T>::SetTag(int v, bool val) const
{
	if (v >= 0 && v < vexNum)
		tag[v] = val;
}
template<class T>
AdjMatrixUndirGraph<T>::AdjMatrixUndirGraph(const AdjMatrixUndirGraph<T> &copy)
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
AdjMatrixUndirGraph<T> &AdjMatrixUndirGraph<T>::operator=(const AdjMatrixUndirGraph<T> &copy)
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
int AdjMatrixUndirGraph<T>::FirstAdjVex(int v) const
{//���ض���v�ĵ�һ����ӵ�
	if (v < 0 || v >= vexNum)
		return -1;
	else
	{
		for (int i = 0; i < vexNum; i++)
			if (Matrix[v][i] == 1)
				return i;
		return -1;	//ѭ��������vû���ڽӽ��
	}
}
template<class T>
int AdjMatrixUndirGraph<T>::NextAdjVex(int v1, int v2) const
{//���ض���v1�����v2����һ����ӵ�
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		return -1;
	else
	{
		for (int i = v2 + 1; i < vexNum; i++)
			if (Matrix[v1][i] == 1)
				return i;
		return -1;	//ѭ����������������һ����ӵ�
	}
}

template<class T>
void AdjMatrixUndirGraph<T>::DFS(int v, void(*visit)(const T &)) const
{//�Ӷ���v�������������������ͼ
	SetTag(v, true);
	T tmp;
	GetElem(v, tmp);
	(*visit)(tmp);
	for (int w = FirstAdjVex(v); w >= 0; w = NextAdjVex(v, w))
		if (!GetTag(w))
			DFS(w, visit);
}
template<class T>
void AdjMatrixUndirGraph<T>::BFS(int v, void(*visit)(const T &)) const
{//�Ӷ���v�������й����������ͼ
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
void AdjMatrixUndirGraph<T>::DFSTraverse(void(*visit)(const T &)) const
{//��ͼ����������ȱ���
	int v;
	for (v = 0; v < vexNum; v++)
		SetTag(v, false);
	for (v = 0; v < vexNum; v++)
		if (!GetTag(v))
			DFS(v, visit);
}
template<class T>
void AdjMatrixUndirGraph<T>::BFSTraverse(void(*visit)(const T &)) const
{//��ͼ���й�����ȱ���
	int v;
	for (v = 0; v < vexNum; v++)
		SetTag(v, false);
	for (v = 0; v < vexNum; v++)
		if (!GetTag(v))
			BFS(v, visit);
}

#endif // !_AdjMatrixUndirGraph_H_
