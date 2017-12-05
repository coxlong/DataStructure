
//双向链表

#ifndef _DBLLINKLIST_H_
#define _DBLLINKLIST_H_

//结点类模板
template<class T>
struct DblNode
{
	T data;
	DblNode<T> *back;
	DblNode<T> *next;

	DblNode();
	DblNode(T val, DblNode<T> *bPtr = NULL, DblNode<T> *nPtr = NULL);
};
template<class T>
DblNode<T>::DblNode()
{
	back = NULL;
	next = NULL;
}
template<class T>
DblNode<T>::DblNode(T val, DblNode<T> *bPtr, DblNode<T> *nPtr)
{
	data = val;
	back = bPtr;
	next = nPtr;
}

template<class T>
class DblLinkList
{
public:
	DblLinkList();
	virtual~DblLinkList();
	int Length() const;
	bool isEmpty() const;
	void Clear();
	void Traverse(void(*visit)(const T &)) const;
	bool GetElem(int position, T &e) const;
	bool SetElem(int position, const T &e);
	bool Delete(int position, T &e);
	bool Insert(int position, const T &e);
	DblLinkList(const DblLinkList<T> &copy);
	DblLinkList<T> &operator=(const DblLinkList<T> &copy);

protected:
	DblNode<T> *head;
	DblNode<T> *GetElemPtr(int position) const;
};

template<class T>
DblNode<T> *DblLinkList<T>::GetElemPtr(int position) const
{
	DblNode<T> *tmpPtr = head;
	int p = 0;
	while (tmpPtr != NULL&&p < position)
	{
		tmpPtr = tmpPtr->next;
		p++;
	}
	return tmpPtr;
}

template<class T>
DblLinkList<T>::DblLinkList()
{
	head = new DblNode<T>;
}
template<class T>
DblLinkList<T>::~DblLinkList()
{
	Clear();
	delete head;
}
template<class T>
int DblLinkList<T>::Length() const
{
	int count = 0;
	DblNode<T> *tmpPtr = head->next;
	while (tmpPtr != NULL)
	{
		count++;
		tmpPtr = tmpPtr->next;
	}
	return count;
}
template<class T>
bool DblLinkList<T>::isEmpty() const
{
	return head->next == NULL;
}
template<class T>
void DblLinkList<T>::Clear()
{
	T tmp;
	while (!isEmpty())
		Delete(1, tmp);
}
template<class T>
void DblLinkList<T>::Traverse(void(*visit)(const T &)) const
{
	DblNode<T> *curPtr = head->next;
	while (curPtr != NULL)
	{
		(*visit)(curPtr->data);
		curPtr = curPtr->next;
	}
}
template<class T>
bool DblLinkList<T>::GetElem(int position, T &e) const
{
	if (position<1 || position>Length())
		return false;
	else
	{
		DblNode<T> *tmpPtr = GetElemPtr(position);
		e = tmpPtr->data;
		return true;
	}
}
template<class T>
bool DblLinkList<T>::SetElem(int position, const T &e)
{
	if (position<1 || position>Length())
		return false;
	else
	{
		DblNode<T> *tmpPtr = GetElemPtr(position);
		tmpPtr->data = e;
		return true;
	}
}
template<class T>
bool DblLinkList<T>::Delete(int position, T &e)
{
	if (position<1 || position>Length())
		return false;
	else
	{
		DblNode<T> *tmpPtr = GetElemPtr(position);
		tmpPtr->back->next = tmpPtr->next;
		if (tmpPtr->next != NULL)
			tmpPtr->next->back = tmpPtr->back;
		e = tmpPtr->data;
		delete tmpPtr;
		return true;
	}
}
template<class T>
bool DblLinkList<T>::Insert(int position, const T &e)
{
	if (position<1 || position>Length() + 1)
		return false;
	else
	{
		DblNode<T> *backPtr = GetElemPtr(position - 1);
		DblNode<T> *nextPtr = backPtr->next;
		DblNode<T> *newPtr = new DblNode<T>(e, backPtr, nextPtr);
		backPtr->next = newPtr;
		if (nextPtr != NULL)
			nextPtr->back = newPtr;
		return true;
	}
}
template<class T>
DblLinkList<T>::DblLinkList(const DblLinkList<T> &copy)
{
	head = new DblNode<T>;
	DblNode<T> *tmpPtr = head;
	DblNode<T> *curPtr = copy.head->next;
	while (curPtr != NULL)
	{
		tmpPtr->next = new DblNode<T>(curPtr->data);
		tmpPtr->next->back = tmpPtr;
		curPtr = curPtr->next;
		tmpPtr = tmpPtr->next;
	}
}
template<class T>
DblLinkList<T> &DblLinkList<T>::operator=(const DblLinkList<T> &copy)
{
	if (&copy != this)
	{
		Clear();
		DblNode<T> *tmpPtr = head;
		DblNode<T> *curPtr = copy.head->next;
		while (curPtr != NULL)
		{
			tmpPtr->next = new DblNode<T>(curPtr->data);
			tmpPtr->next->back = tmpPtr;
			curPtr = curPtr->next;
			tmpPtr = tmpPtr->next;
		}
	}
	return *this;
}

#endif // !_DBLLINKLIST_H_
