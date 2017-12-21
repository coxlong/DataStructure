
//邻接表图顶点结点类模板

#ifndef _ADJLISTGRAPHVEXNODE_H_
#define _ADJLISTGRAPHVEXNODE_H_

#include "LinkList.h"

template<class T>
struct AdjListGraphVexNode
{
	T data;
	LinkList<int> *adjLink;
	AdjListGraphVexNode();
	AdjListGraphVexNode(T val, LinkList<int> *adjL = NULL);
};
template<class T>
AdjListGraphVexNode<T>::AdjListGraphVexNode()
{
	adjLink = NULL;
}template<class T>
AdjListGraphVexNode<T>::AdjListGraphVexNode(T val, LinkList<int> *adjL)
{
	data = val;
	adjLink = adjL;
}

#endif // !_ADJLISTGRAPHVEXNODE_H_
