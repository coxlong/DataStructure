
//二叉链表类模板

#ifndef _BINTREE_H_
#define _BINTREE_H_
#include "BinTreeNode.h"
#include "Stack.h"
#include "Queue.h"

template<class T>
class BinTree
{
public:
	BinTree();
	BinTree(const T &e);
	BinTree(BinTreeNode<T> *r);
	BinTree(const BinTree<T> &copy);
	BinTree<T> &operator=(const BinTree<T> &copy);
	virtual~BinTree();
	BinTreeNode<T> *GetRoot() const;
	bool isEmpty() const;
	int NodeCount() const;
	int Height() const; 
	bool GetElem(const BinTreeNode<T> *cur, T &e) const;
	bool SetElem(BinTreeNode<T> *cur, const T &e);
	BinTreeNode<T> *LeftChild(const BinTreeNode<T> *cur) const;
	BinTreeNode<T> *RightChild(const BinTreeNode<T> *cur) const;
	//BinTreeNode<T> *Parent(const BinTreeNode<T> *cur) const;
	void InsertLeftChild(BinTreeNode<T> *cur, const T &e);
	void InsertRightChild(BinTreeNode<T> *cur, const T &e);
	void DeleteLeftChild(BinTreeNode<T> *cur);
	void DeleteRightChild(BinTreeNode<T> *cur);
	void RecurInOrder(void(*visit)(const T &)) const;
	void RecurPreOrder(void(*visit)(const T &)) const;
	void RecurPostOrder(void(*visit)(const T &)) const;
	void InOrder(void(*visit)(const T &)) const;
	void PreOrder(void(*visit)(const T &)) const;
	void PostOrder(void(*visit)(const T &)) const;
	void LevelOrder(void(*visit)(const T &)) const;
	

protected:
	BinTreeNode<T> *root;
	BinTreeNode<T> *CopyTreeHelp(const BinTreeNode<T> *r);
	void DestroyHelp(BinTreeNode<T> *&r);
	int NodeCountHelp(const BinTreeNode<T> *r) const;
	int HeightHelp(const BinTreeNode<T> *r) const;
	void RecurInOrderHelp(const BinTreeNode<T> *r, void(*visit)(const T &)) const;
	void RecurPreOrderHelp(const BinTreeNode<T> *r, void(*visit)(const T &)) const;
	void RecurPostOrderHelp(const BinTreeNode<T> *r, void(*visit)(const T &)) const;
};

template<class T>
BinTreeNode<T> *BinTree<T>::CopyTreeHelp(const BinTreeNode<T> *r)
{
	if (r == NULL)
		return NULL;
	else
	{
		BinTreeNode<T> *lChild = CopyTreeHelp(r->leftChild);
		BinTreeNode<T> *rChild = CopyTreeHelp(r->rightChild);
		BinTreeNode<T> *tmp = new BinTreeNode<T>(r->data, lChild, rChild);
		return tmp;
	}
}
template<class T>
void BinTree<T>::DestroyHelp(BinTreeNode<T> *&r)
{
	if (r != NULL)
	{
		DestroyHelp(r->leftChild);
		DestroyHelp(r->rightChild);
		delete r;
		r = NULL;
	}
}
template<class T>
int BinTree<T>::NodeCountHelp(const BinTreeNode<T> *r) const
{
	if (r == NULL)
		return 0;
	else
		return NodeCountHelp(r->leftChild) + NodeCountHelp(r->rightChild) + 1;
}
template<class T>
int BinTree<T>::HeightHelp(const BinTreeNode<T> *r) const
{
	if (r == NULL)
		return 0;
	else
	{
		int lH, rH;
		lH = HeightHelp(r->leftChild);
		rH = HeightHelp(r->rightChild);
		return (lH > rH ? lH : rH) + 1;
	}
}
template<class T>
void BinTree<T>::RecurInOrderHelp(const BinTreeNode<T> *r, void(*visit)(const T &)) const
{
	if (r != NULL)
	{
		RecurInOrderHelp(r->leftChild, visit);
		(*visit)(r->data);
		RecurInOrderHelp(r->rightChild, visit);
	}
}
template<class T>
void BinTree<T>::RecurPreOrderHelp(const BinTreeNode<T> *r, void(*visit)(const T &)) const
{
	if (r != NULL)
	{
		(*visit)(r->data);
		RecurPreOrderHelp(r->leftChild, visit);
		RecurPreOrderHelp(r->rightChild, visit);
	}
}
template<class T>
void BinTree<T>::RecurPostOrderHelp(const BinTreeNode<T> *r, void(*visit)(const T &)) const
{
	if (r != NULL)
	{
		RecurPostOrderHelp(r->leftChild, visit);
		RecurPostOrderHelp(r->rightChild, visit);
		(*visit)(r->data);
	}
}

template<class T>
BinTree<T>::BinTree()
{
	root = NULL;
}
template<class T>
BinTree<T>::BinTree(const T &e)
{
	root = new BinTreeNode<T>(e);
}
template<class T>
BinTree<T>::BinTree(BinTreeNode<T> *r)
{
	root = r;
}
template<class T>
BinTree<T>::BinTree(const BinTree<T> &copy)
{
	root = CopyTreeHelp(copy.root);
}
template<class T>
BinTree<T> &BinTree<T>::operator=(const BinTree<T> &copy)
{
	if (&copy != this)
	{
		DestroyHelp(root);
		root = CopyTreeHelp(copy.root);
	}
	return *this;
}
template<class T>
BinTree<T>::~BinTree()
{
	DestroyHelp(root);
}
template<class T>
BinTreeNode<T> *BinTree<T>::GetRoot() const
{
	return root;
}
template<class T>
bool BinTree<T>::isEmpty() const
{
	return root == NULL;
}
template<class T>
int BinTree<T>::NodeCount() const
{
	return NodeCountHelp(root);
}
template<class T>
int BinTree<T>::Height() const
{
	return HeightHelp(root);
}
template<class T>
bool BinTree<T>::GetElem(const BinTreeNode<T> *cur, T &e) const
{
	if (cur == NULL)
		return false;
	else
	{
		e = cur->data;
		return true;
	}
}
template<class T>
bool BinTree<T>::SetElem(BinTreeNode<T> *cur, const T &e)
{
	if (cur == NULL)
		return false;
	else
	{
		cur->data = e;
		return true;
	}
}
template<class T>
BinTreeNode<T> *BinTree<T>::LeftChild(const BinTreeNode<T> *cur) const
{
	if (cur == NULL)
		return NULL;
	else
		return cur->leftChild;
}
template<class T>
BinTreeNode<T> *BinTree<T>::RightChild(const BinTreeNode<T> *cur) const
{
	if (cur == NULL)
		return NULL;
	else
		return cur->rightChild;
}
template<class T>
void BinTree<T>::InsertLeftChild(BinTreeNode<T> *cur, const T &e)
{
	if (cur != NULL)
	{
		cur->leftChild = new BinTreeNode<T>(e);
	}
}
template<class T>
void BinTree<T>::InsertRightChild(BinTreeNode<T> *cur, const T &e)
{
	if (cur != NULL)
	{
		cur->rightChild = new BinTreeNode<T>(e);
	}
}
template<class T>
void BinTree<T>::DeleteLeftChild(BinTreeNode<T> *cur)
{
	if (cur->leftChild != NULL)
	{
		delete cur->leftChild;
		cur->leftChild = NULL;
	}
}
template<class T>
void BinTree<T>::DeleteRightChild(BinTreeNode<T> *cur)
{
	if (cur->rightChild != NULL)
	{
		delete cur->rightChild;
		cur->rightChild = NULL;
	}
}
template<class T>
void BinTree<T>::RecurInOrder(void(*visit)(const T &)) const
{
	RecurInOrderHelp(root, visit);
}
template<class T>
void BinTree<T>::RecurPreOrder(void(*visit)(const T &)) const
{
	RecurPreOrderHelp(root, visit);
}
template<class T>
void BinTree<T>::RecurPostOrder(void(*visit)(const T &)) const
{
	RecurPostOrderHelp(root, visit);
}

//中序遍历非递归算法
template<class T>
BinTreeNode<T> *GoFarLeft(BinTreeNode<T> *r, Stack<BinTreeNode<T> *> &s)
{//返回以r 为根的二叉树的最左侧的结点，并将搜索过程中的结点加入到栈s中
	if (r == NULL)
		return NULL;
	else
	{
		BinTreeNode<T> *cur = r;
		while (cur->leftChild != NULL)
		{
			s.Push(cur);
			cur = cur->leftChild;
		}
		return cur;
	}
}
template<class T>
void BinTree<T>::InOrder(void(*visit)(const T &)) const
{
	BinTreeNode<T> *cur;
	Stack<BinTreeNode<T> *> s;
	cur = GoFarLeft(root, s);
	while (cur != NULL)
	{
		(*visit)(cur->data);
		if (cur->rightChild != NULL)
		{//cur的中序序列后继为右子树的最左侧的结点
			cur = GoFarLeft(cur->rightChild, s);
		}
		else if (!s.isEmpty())
		{//cur的中序序列后继为栈s的栈顶结点
			s.Pop(cur);
		}
		else
		{//栈s为空，无中序序列后继
			cur = NULL;
		}
	}
}

//先序遍历非递归算法
template<class T>
void BinTree<T>::PreOrder(void(*visit)(const T &)) const
{
	BinTreeNode<T> *cur = root;
	Stack<BinTreeNode<T> *> s;
	while (cur != NULL)
	{
		(*visit)(cur->data);
		s.Push(cur);
		if (cur->leftChild != NULL)
		{//cur的先序序列后继为cur->leftChild
			cur = cur->leftChild;
		}
		else if (!s.isEmpty())
		{//cur的先序序列后继为栈s的栈顶结点的非空右孩子
			while (!s.isEmpty())
			{
				s.Pop(cur);
				cur = cur->rightChild;
				if (cur != NULL)
					break;
			}
		}
		else
		{//栈s为空，无先序序列后继
			cur = NULL;
		}
	}
}

//后序遍历非递归算法
//修改后的结点结构
template<class T>
struct ModiNode
{
	BinTreeNode<T> *node;
	bool rightSubTreevisited;
};
template<class T>
ModiNode<T> *GoFarLeft(BinTreeNode<T> *r, Stack<ModiNode<T> *> &s)
{//返回以r 为根的二叉树的最左侧的结点，并将搜索过程中的结点加入到栈s中
	if (r == NULL)
		return NULL;
	else
	{
		BinTreeNode<T> *cur = r;
		ModiNode<T> *newPtr;
		while (cur->leftChild != NULL)
		{
			newPtr = new ModiNode<T>;
			newPtr->node = cur;
			newPtr->rightSubTreevisited = false;
			s.Push(newPtr);
			cur = cur->leftChild;
		}
		newPtr = new ModiNode<T>;
		newPtr->node = cur;
		newPtr->rightSubTreevisited = false;
		return newPtr;
	}
}
template<class T>
void BinTree<T>::PostOrder(void(*visit)(const T &)) const
{
	ModiNode<T> *cur;
	Stack<ModiNode<T> *> s;

	cur = GoFarLeft(root, s);
	while (cur != NULL)
	{
		if (cur->node->rightChild == NULL || cur->rightSubTreevisited)
		{//当前结点右子树为空或右子树已被访问
			(*visit)(cur->node->data);
			delete cur;
			if (!s.isEmpty())
			{//栈非空，则栈顶将指示下一次要访问的结点
				s.Pop(cur);
			}
			else
				cur = NULL;
		}
		else
		{//当前结点右子树未被访问
			cur->rightSubTreevisited = true;
			s.Push(cur);
			cur = GoFarLeft(cur->node->rightChild, s);
		}
	}
}

//层次遍历
template<class T>
void BinTree<T>::LevelOrder(void(*visit)(const T &)) const
{
	Queue<BinTreeNode<T> *> q;
	BinTreeNode<T> *cur = root;
	if (cur != NULL)
		q.InQueue(cur);
	while (!q.isEmpty())
	{
		q.OutQueue(cur);
		(*visit)(cur->data);
		if (cur->leftChild != NULL)
			q.InQueue(cur->leftChild);
		if (cur->rightChild)
			q.InQueue(cur->rightChild);
	}
}



//二叉树的显示
template<class T>
void DisplayBinTreeHelp(BinTreeNode<T> *r, int level)
{
	if (r != NULL)
	{
		DisplayBinTreeHelp(r->rightChild, level + 1);
		std::cout << endl;
		for (int i = 0; i < level - 1; i++)
			std::cout << " ";
		std::cout << r->data;
		DisplayBinTreeHelp(r->leftChild, level + 1);
	}
}
template<class T>
void DisplayBinTree(const BinTree<T> &bt)
{
	DisplayBinTreeHelp(bt.GetRoot(), 1);
	std::cout << endl;
}
//由先序序列与中序序列构造二叉树
template<class T>
void CreateBinTreeHelp(BinTreeNode<T> *&r, T pre[], T in[], int preLeft, int preRight, int inLeft, int inRight)
{
	if (preLeft > preRight || inLeft > inRight)
		r = NULL;
	else
	{
		r = new BinTreeNode<T>(pre[preLeft]);
		int mid = inLeft;
		while (in[mid] != pre[preLeft])
			mid++;
		CreateBinTreeHelp(r->leftChild, pre, in, preLeft + 1, preLeft + mid - inLeft, inLeft, mid - 1);
		CreateBinTreeHelp(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, inRight);
	}
}
template<class T>
BinTree<T> CreateBinTree(T pre[], T in[], int n)
{
	BinTreeNode<T> *r;
	CreateBinTreeHelp(r, pre, in, 0, n - 1, 0, n - 1);
	return BinTree<T>(r);
}

#endif // !_BINTREE_H_
