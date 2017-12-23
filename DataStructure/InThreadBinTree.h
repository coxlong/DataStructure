
//中序线索二叉树类模板

#ifndef _INTHREADBINTREE_H_
#define _INTHREADBINTREE_H_

#include "ThreadBinTreeNode.h"
#include "BinTree.h"

template<class T>
class InThreadBinTree
{
public:
	InThreadBinTree(const BinTree<T> &bt);
	virtual~InThreadBinTree();
	ThreadBinTreeNode<T> *GetRoot() const;
	void InThread();	//中序线索化二叉树
	void InOrder(void(*visit)(const T &)) const;
	InThreadBinTree(const InThreadBinTree<T> &copy);
	InThreadBinTree<T> &operator=(const InThreadBinTree<T> &copy);

protected:
	ThreadBinTreeNode<T> *root;

	//辅助函数模板
	void InThreadHelp(ThreadBinTreeNode<T> *cur, ThreadBinTreeNode<T> *&pre);	//中序线索化以cur为根的二叉树
	ThreadBinTreeNode<T> *TransformHelp(BinTreeNode<T> *r);
	ThreadBinTreeNode<T> *CopyHelp(const ThreadBinTreeNode<T> &copy);
	void DestroyHelp(ThreadBinTreeNode<T> *&r);
};

template<class T>
void InThreadBinTree<T>::InThreadHelp(ThreadBinTreeNode<T> *cur, ThreadBinTreeNode<T> *&pre)
{
	if (cur != NULL)
	{
		if (cur->leftTag == CHILD_PTR)
			InThreadHelp(cur->leftChild, pre);		//线索化左子树
		if (cur->leftChild == NULL)
		{//cur无左孩子，加线索
			cur->leftChild = pre;
			cur->leftTag = THREAD_PTR;
		}

		if (pre != NULL && pre->rightChild == NULL)
		{//pre无右孩子，加线索
			pre->rightChild = cur;
			pre->rightTag = THREAD_PTR;
		}
		pre = cur;
		if (cur->rightTag == CHILD_PTR)
			InThreadHelp(cur->rightChild, pre);		//线索化右子树
	}
}
template<class T>
ThreadBinTreeNode<T> *InThreadBinTree<T>::TransformHelp(BinTreeNode<T> *r)
{
	if (r == NULL)
		return NULL;
	else
	{
		ThreadBinTreeNode<T> *lChild = TransformHelp(r->leftChild);
		ThreadBinTreeNode<T> *rChild = TransformHelp(r->rightChild);
		ThreadBinTreeNode<T> *tmp = new ThreadBinTreeNode<T>(r->data, lChild, rChild);
		return tmp;
	}
}
template<class T>
ThreadBinTreeNode<T> *InThreadBinTree<T>::CopyHelp(const ThreadBinTreeNode<T> &copy)
{
	ThreadBinTreeNode<T> *tmp = new ThreadBinTreeNode<T>(copy.data);
	if (copy.leftTag == CHILD_PTR)
		tmp->leftChild = CopyHelp(*copy.leftChild);
	if (copy.rightTag == CHILD_PTR)
		tmp->rightChild = CopyHelp(*copy.rightChild);
	return tmp;
}
template<class T>
void InThreadBinTree<T>::DestroyHelp(ThreadBinTreeNode<T> *&r)
{
	if (r != NULL)
	{
		if(r->leftTag==CHILD_PTR)
			DestroyHelp(r->leftChild);
		if(r->rightTag==CHILD_PTR)
			DestroyHelp(r->rightChild);
		delete r;
		r = NULL;
	}
}


template<class T>
InThreadBinTree<T>::InThreadBinTree(const BinTree<T> &bt)
{
	root = TransformHelp(bt.GetRoot());
	InThread();
}
template<class T>
InThreadBinTree<T>::~InThreadBinTree()
{
	DestroyHelp(root);
}
template<class T>
ThreadBinTreeNode<T> *InThreadBinTree<T>::GetRoot() const
{
	return root;
}
template<class T>
void InThreadBinTree<T>::InThread()
{
	ThreadBinTreeNode<T> *pre = NULL;
	InThreadHelp(root, pre);
	if (pre->rightChild == NULL)
		pre->rightTag = THREAD_PTR;
}
template<class T>
void InThreadBinTree<T>::InOrder(void(*visit)(const T &)) const
{
	if (root != NULL)
	{
		ThreadBinTreeNode<T> *cur = root;
		//查找最左侧的结点，此结点为中序序列的第一个结点
		while (cur->leftTag == CHILD_PTR)
			cur = cur->leftChild;
		while (cur != NULL)
		{
			(*visit)(cur->data);
			if (cur->rightTag == THREAD_PTR)
				cur = cur->rightChild;
			else
			{
				cur = cur->rightChild;
				while (cur->leftTag == CHILD_PTR)
					cur = cur->leftChild;
			}
		}
	}
}
template<class T>
InThreadBinTree<T>::InThreadBinTree(const InThreadBinTree<T> &copy)
{
	root = CopyHelp(*copy.root);
	InThread();
}
template<class T>
InThreadBinTree<T> &InThreadBinTree<T>::operator=(const InThreadBinTree<T> &copy)
{
	if (&copy != this)
	{
		DestroyHelp(root);
		root = CopyHelp(*copy.root);
		InThread();
	}
	return *this;
}

#endif // !_INTHREADBINTREE_H_
