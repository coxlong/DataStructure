
//先序线索二叉树类模板

#ifndef _PRETHREADBINTREE_H_
#define _PRETHREADBINTREE_H_

#include "ThreadBinTreeNode.h"
#include "BinTree.h"

template<class T>
class PreThreadBinTree
{
public:
	PreThreadBinTree(const BinTree<T> &bt);
	virtual~PreThreadBinTree();
	ThreadBinTreeNode<T> *GetRoot() const;
	void PreThread();	//先序线索化二叉树
	void PreOrder(void(*visit)(const T &)) const;
	PreThreadBinTree(const PreThreadBinTree<T> &copy);
	PreThreadBinTree<T> &operator=(const PreThreadBinTree<T> &copy);

protected:
	ThreadBinTreeNode<T> *root;

	//辅助函数模板
	void PreThreadHelp(ThreadBinTreeNode<T> *cur, ThreadBinTreeNode<T> *&pre);	//先序线索化以cur为根的二叉树
	ThreadBinTreeNode<T> *TransformHelp(BinTreeNode<T> *r);
	ThreadBinTreeNode<T> *CopyHelp(const ThreadBinTreeNode<T> &copy);
	void DestroyHelp(ThreadBinTreeNode<T> *&r);
};

template<class T>
void PreThreadBinTree<T>::PreThreadHelp(ThreadBinTreeNode<T> *cur, ThreadBinTreeNode<T> *&pre)
{
	if (cur != NULL)
	{
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
		if (cur->leftTag == CHILD_PTR)
			PreThreadHelp(cur->leftChild, pre);		//线索化左子树
		if (cur->rightTag == CHILD_PTR)
			PreThreadHelp(cur->rightChild, pre);		//线索化右子树
	}
}
template<class T>
ThreadBinTreeNode<T> *PreThreadBinTree<T>::TransformHelp(BinTreeNode<T> *r)
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
ThreadBinTreeNode<T> *PreThreadBinTree<T>::CopyHelp(const ThreadBinTreeNode<T> &copy)
{
	ThreadBinTreeNode<T> *tmp = new ThreadBinTreeNode<T>(copy.data);
	if (copy.leftTag == CHILD_PTR)
		tmp->leftChild = CopyHelp(*copy.leftChild);
	if (copy.rightTag == CHILD_PTR)
		tmp->rightChild = CopyHelp(*copy.rightChild);
	return tmp;
}
template<class T>
void PreThreadBinTree<T>::DestroyHelp(ThreadBinTreeNode<T> *&r)
{
	if (r != NULL)
	{
		if (r->leftTag == CHILD_PTR)
			DestroyHelp(r->leftChild);
		if (r->rightTag == CHILD_PTR)
			DestroyHelp(r->rightChild);
		delete r;
		r = NULL;
	}
}


template<class T>
PreThreadBinTree<T>::PreThreadBinTree(const BinTree<T> &bt)
{
	root = TransformHelp(bt.GetRoot());
	PreThread();
}
template<class T>
PreThreadBinTree<T>::~PreThreadBinTree()
{
	DestroyHelp(root);
}
template<class T>
ThreadBinTreeNode<T> *PreThreadBinTree<T>::GetRoot() const
{
	return root;
}
template<class T>
void PreThreadBinTree<T>::PreThread()
{
	ThreadBinTreeNode<T> *pre = NULL;
	PreThreadHelp(root, pre);
	if (pre->rightChild == NULL)
		pre->rightTag = THREAD_PTR;
}
template<class T>
void PreThreadBinTree<T>::PreOrder(void(*visit)(const T &)) const
{
	if (root != NULL)
	{
		ThreadBinTreeNode<T> *cur = root;
		while (cur != NULL)
		{
			(*visit)(cur->data);
			if (cur->rightTag == THREAD_PTR)
				cur = cur->rightChild;
			else
			{
				if (cur->leftTag == CHILD_PTR)
					cur = cur->leftChild;
				else
					cur = cur->rightChild;
			}
		}
	}
}
template<class T>
PreThreadBinTree<T>::PreThreadBinTree(const PreThreadBinTree<T> &copy)
{
	root = CopyHelp(*copy.root);
	InThread();
}
template<class T>
PreThreadBinTree<T> &PreThreadBinTree<T>::operator=(const PreThreadBinTree<T> &copy)
{
	if (&copy != this)
	{
		DestroyHelp(root);
		root = CopyHelp(*copy.root);
		InThread();
	}
	return *this;
}

#endif // !_PRETHREADBINTREE_H_
