
//树的孩子兄弟表示法

#ifndef _CHILDSIBLINGTREE_H_
#define _CHILDSIBLINGTREE_H_

#include "Queue.h"

//孩子兄弟表示树结点类模板
template<class T>
struct ChildSiblingTreeNode
{
	T data;
	ChildSiblingTreeNode<T> *firstChild;	//指向首孩子的指针
	ChildSiblingTreeNode<T> *rightSibling;	//指向右兄弟的指针

	ChildSiblingTreeNode();
	ChildSiblingTreeNode(const T &val, ChildSiblingTreeNode<T> *fChild = NULL,
		ChildSiblingTreeNode<T> *rSibling = NULL);
};
template<class T>
ChildSiblingTreeNode<T>::ChildSiblingTreeNode()
{
	firstChild = NULL;
	rightSibling = NULL;
}
template<class T>
ChildSiblingTreeNode<T>::ChildSiblingTreeNode(const T &val, ChildSiblingTreeNode<T> *fChild, ChildSiblingTreeNode<T> *rSibling)
{
	data = val;
	firstChild = fChild;
	rightSibling = rSibling;
}


//孩子兄弟表示树类模板
template<class T>
class ChildSiblingTree
{
public:
	ChildSiblingTree();
	virtual~ChildSiblingTree();
	ChildSiblingTreeNode<T> *GetRoot() const;
	bool isEmpty() const;
	bool GetElem(const ChildSiblingTreeNode<T> *cur, T &e) const;
	bool SetElem(ChildSiblingTreeNode<T> *cur, const T &e);
	void PreRootOrder(void(*visit)(const T &)) const;
	void PostRootOrder(void(*visit)(const T &)) const;
	void LevelOrder(void(*visit)(const T &)) const;
	int NodeCount() const;
	int NodeDegree(const ChildSiblingTreeNode<T> *cur) const;
	int Degree() const;
	int Height() const;
	ChildSiblingTreeNode<T> *FirstChild(const ChildSiblingTreeNode<T> *cur) const;
	ChildSiblingTreeNode<T> *RightSibling(const ChildSiblingTreeNode<T> *cur) const;
	//ChildSiblingTreeNode<T> *Parent(const ChildSiblingTreeNode<T> *cur) const;
	bool InsertChild(ChildSiblingTreeNode<T> *cur, int i, const T &e);
	bool DeleteChild(ChildSiblingTreeNode<T> *cur, int i);
	ChildSiblingTree(const T &e);
	ChildSiblingTree(const ChildSiblingTree<T> &copy);
	ChildSiblingTree(T item[], int parents[], int r, int n);
	ChildSiblingTree(ChildSiblingTreeNode<T> *r);
	ChildSiblingTree<T> &operator=(const ChildSiblingTree<T> &copy);

protected:
	ChildSiblingTreeNode<T> *root;

	void DestroyHelp(ChildSiblingTreeNode<T> *&r);
	void PreRootOrderHelp(const ChildSiblingTreeNode<T> *r, void(*visit)(const T &)) const;
	void PostRootOrderHelp(const ChildSiblingTreeNode<T> *r, void(*visit)(const T &)) const;
	int NodeCountHelp(const ChildSiblingTreeNode<T> *r) const;
	int HeightHelp(const ChildSiblingTreeNode<T> *r) const;
	int DegreeHelp(const ChildSiblingTreeNode<T> *r) const;
	void DeleteHelp(ChildSiblingTreeNode<T> *&r);
	//ChildSiblingTreeNode<T> *ParentHelp(ChildSiblingTreeNode<T> *r, const ChildSiblingTreeNode<T> *cur) const;
	ChildSiblingTreeNode<T> *CopyTreeHelp(const ChildSiblingTreeNode<T> *r);
	ChildSiblingTreeNode<T> *CreateTreeHelp(T items[], int parents[], int r, int n);	
	//r为根结点位置
};

template<class T>
void ChildSiblingTree<T>::DestroyHelp(ChildSiblingTreeNode<T> *&r)
{
	if (r != NULL)
	{
		DestroyHelp(r->firstChild);
		DestroyHelp(r->rightSibling);
		delete r;
		r = NULL;
	}
}
template<class T>
void ChildSiblingTree<T>::PreRootOrderHelp(const ChildSiblingTreeNode<T> *r, void(*visit)(const T &)) const
{
	if (r != NULL)
	{
		(*visit)(r->data);
		for (ChildSiblingTreeNode<T> *tmpPtr = r->firstChild; tmpPtr != NULL; tmpPtr = tmpPtr->rightSibling)
			PreRootOrderHelp(tmpPtr, visit);
	}
}
template<class T>
void ChildSiblingTree<T>::PostRootOrderHelp(const ChildSiblingTreeNode<T> *r, void(*visit)(const T &)) const
{
	if (r != NULL)
	{
		for (ChildSiblingTreeNode<T> *tmpPtr = r->firstChild; tmpPtr != NULL; tmpPtr = tmpPtr->rightSibling)
			PostRootOrderHelp(tmpPtr, visit);
		(*visit)(r->data);
	}
}
template<class T>
int ChildSiblingTree<T>::NodeCountHelp(const ChildSiblingTreeNode<T> *r) const
{
	int count == 1;
	ChildSiblingTreeNode<T> *tmpPtr = r->firstChild;
	while (tmpPtr != NULL)
	{
		count += NodeCountHelp(tmpPtr);
		tmpPtr = tmpPtr->rightSibling;
	}
	return count;
}
template<class T>
int ChildSiblingTree<T>::HeightHelp(const ChildSiblingTreeNode<T> *r) const
{
	int height = 0;
	for (ChildSiblingTreeNode<T> *tmpPtr = r->firstChild; tmpPtr != NULL; tmpPtr = tmpPtr->rightSibling)
	{
		int hTmp = HeightHelp(tmpPtr);
		if (hTmp > height)
			height = hTmp;
	}
	return height + 1;
}
template<class T>
int ChildSiblingTree<T>::DegreeHelp(const ChildSiblingTreeNode<T> *r) const
{
	int degree = NodeDegree(r);
	for (ChildSiblingTreeNode<T> *tmpPtr = r->firstChild; tmpPtr != NULL; tmpPtr = tmpPtr->rightSibling)
	{
		int dTmp = NodeDegree(tmpPtr);
		if (dTmp > degree)
			degree = dTmp;
	}
	return degree;
}
template<class T>
void ChildSiblingTree<T>::DeleteHelp(ChildSiblingTreeNode<T> *&r)
{
	if (r != NULL)
	{
		DestroyHelp(r->firstChild);
		ChildSiblingTreeNode<T> *tmpPtr = r->rightSibling;
		delete r;
		r = tmpPtr;
	}
}
//ChildSiblingTreeNode<T> *ParentHelp(ChildSiblingTreeNode<T> *r, const ChildSiblingTreeNode<T> *cur) const;
template<class T>
ChildSiblingTreeNode<T> *ChildSiblingTree<T>::CopyTreeHelp(const ChildSiblingTreeNode<T> *r)
{
	if (r == NULL)
		return NULL;
	else
	{
		ChildSiblingTreeNode<T> *fChild = CopyTreeHelp(r->firstChild);
		ChildSiblingTreeNode<T> *rSibling = CopyTreeHelp(r->rightSibling);
		return new ChildSiblingTreeNode<T>(r->data, fChild, rSibling);
	}
}
template<class T>
ChildSiblingTreeNode<T> *ChildSiblingTree<T>::CreateTreeHelp(T items[], int parents[], int r, int n)
{//r为根结点位置
	ChildSiblingTreeNode<T> *newPtr = new ChildSiblingTreeNode<T>(items[r]);
	ChildSiblingTreeNode<T> *tmpPtr = newPtr->firstChild;
	for (int i = 0; i < n; i++)
	{
		if (parents[i] == r)
		{
			if (newPtr->firstChild == NULL)
			{
				newPtr->firstChild = CreateTreeHelp(items, parents, i, n);
				tmpPtr = newPtr->firstChild;
			}
			else
			{
				tmpPtr->rightSibling = CreateTreeHelp(items, parents, i, n);
				tmpPtr = tmpPtr->rightSibling;
			}
		}
	}
	return newPtr;
}

template<class T>
ChildSiblingTree<T>::ChildSiblingTree()
{
	root = NULL;
}
template<class T>
ChildSiblingTree<T>::~ChildSiblingTree()
{
	DestroyHelp(root);
}
template<class T>
ChildSiblingTreeNode<T> *ChildSiblingTree<T>::GetRoot() const
{
	return root;
}
template<class T>
bool ChildSiblingTree<T>::isEmpty() const
{
	return root == NULL;
}
template<class T>
bool ChildSiblingTree<T>::GetElem(const ChildSiblingTreeNode<T> *cur, T &e) const
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
bool ChildSiblingTree<T>::SetElem(ChildSiblingTreeNode<T> *cur, const T &e)
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
void ChildSiblingTree<T>::PreRootOrder(void(*visit)(const T &)) const
{
	PreRootOrderHelp(root, visit);
}
template<class T>
void ChildSiblingTree<T>::PostRootOrder(void(*visit)(const T &)) const
{
	PostRootOrderHelp(root, visit);
}
template<class T>
void ChildSiblingTree<T>::LevelOrder(void(*visit)(const T &)) const
{
	Queue<ChildSiblingTreeNode<T> *> q;
	q.InQueue(root);
	ChildSiblingTreeNode<T> *tmpPtr;
	while (!q.isEmpty())
	{
		q.OutQueue(tmpPtr);
		(*visit)(tmpPtr->data);
		for (ChildSiblingTreeNode<T> *child = tmpPtr->firstChild; child != NULL; child = child->rightSibling)
			q.InQueue(child);
	}
	
}
template<class T>
int ChildSiblingTree<T>::NodeCount() const
{
	return NodeCountHelp(root);
}
template<class T>
int ChildSiblingTree<T>::NodeDegree(const ChildSiblingTreeNode<T> *cur) const
{
	int degree = 0;
	for (ChildSiblingTreeNode<T> *tmpPtr = FirstChild(cur); tmpPtr != NULL; tmpPtr = RightSibling(tmpPtr))
		degree++;
	return degree;
}
template<class T>
int ChildSiblingTree<T>::Degree() const
{
	return DegreeHelp(root);
}
template<class T>
int ChildSiblingTree<T>::Height() const
{
	return HeightHelp(root);
}
template<class T>
ChildSiblingTreeNode<T> *ChildSiblingTree<T>::FirstChild(const ChildSiblingTreeNode<T> *cur) const
{
	return cur->firstChild;
}
template<class T>
ChildSiblingTreeNode<T> *ChildSiblingTree<T>::RightSibling(const ChildSiblingTreeNode<T> *cur) const
{
	return cur->rightSibling;
}
//template<class T>
//ChildSiblingTreeNode<T> *Parent(const ChildSiblingTreeNode<T> *cur) const;
template<class T>
bool ChildSiblingTree<T>::InsertChild(ChildSiblingTreeNode<T> *cur, int i, const T &e)
{
	if (i<1 || i>NodeDegree(cur) + 1)
		return false;
	else
	{
		ChildSiblingTreeNode<T> *tmpPtr = cur->firstChild;
		if (i == 1)
			cur->firstChild = new ChildSiblingTreeNode<T>(e, NULL, tmpPtr);
		else
		{
			while (i-- > 2)
				tmpPtr = tmpPtr->rightSibling;
			//tmpPtr为插入结点的上一个兄弟结点
			ChildSiblingTreeNode<T> *newPtr = new ChildSiblingTreeNode<T>(e, NULL, tmpPtr->rightSibling);
			tmpPtr->rightSibling = newPtr;
		}
		return true;
	}
}
template<class T>
bool ChildSiblingTree<T>::DeleteChild(ChildSiblingTreeNode<T> *cur, int i)
{
	if (i<1 || i>NodeDegree(cur))
		return false;
	else
	{
		ChildSiblingTreeNode<T> *tmpPtr = cur->firstChild;
		while (i-- > 1)
			tmpPtr = tmpPtr->rightSibling;
		DeleteHelp(tmpPtr);
		return true;
	}
}
template<class T>
ChildSiblingTree<T>::ChildSiblingTree(const T &e)
{
	root = new ChildSiblingTreeNode(e);
}
template<class T>
ChildSiblingTree<T>::ChildSiblingTree(const ChildSiblingTree<T> &copy)
{
	root = CopyTreeHelp(copy.root);
}
template<class T>
ChildSiblingTree<T>::ChildSiblingTree(T item[], int parents[], int r, int n)
{
	root = CreateTreeHelp(item, parents, r, n);
}
template<class T>
ChildSiblingTree<T>::ChildSiblingTree(ChildSiblingTreeNode<T> *r)
{
	root = r;
}
template<class T>
ChildSiblingTree<T> &ChildSiblingTree<T>::operator=(const ChildSiblingTree<T> &copy)
{
	if (&copy != this)
	{
		DestroyHelp(root);
		root = CopyTreeHelp(copy.root);
	}
	return *this;
}


//树的显示
template<class T>
void DisplayHelp(const ChildSiblingTree<T> &t, ChildSiblingTreeNode<T> *r, int level)
{
	if (r != NULL)
	{
		std::cout << std::endl;
		for (int i = 0; i < level - 1; i++)
			std::cout << " ";
		T e;
		t.GetElem(r, e);
		cout << e;
		for (ChildSiblingTreeNode<T> *child = t.FirstChild(r); child != NULL; child = t.RightSibling(child))
			DisplayHelp(t,child,level+1);
	}
}
template<class T>
void Display(const ChildSiblingTree<T> &t)
{
	DisplayHelp(t, t.GetRoot(), 1);
	std::cout << std::endl;
}

#endif // !_CHILDSIBLINGTREE_H_
