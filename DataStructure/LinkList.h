
//单链表类模板

#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include "Node.h"

template<class T>
class LinkList
{
public:
	LinkList();
	virtual~LinkList();
	int Length() const;
	bool isEmpty() const;
	void Clear();
	void Traverse(void(*visit)(const T &)) const;
	bool GetElem(int position, T &e) const;
	bool SetElem(int position, const T &e);
	bool Delete(int position, T &e);
	bool Insert(int position, const T &e);
	LinkList(const LinkList<T> &copy);
	LinkList<T> &operator=(const LinkList<T> &copy);

protected:
	Node<T> *head;
	mutable int curPosition;
	mutable Node<T> *curPtr;
	int count;

	Node<T> *GetElemPtr(int pos) const;
};

template<class T>
Node<T> *LinkList<T>::GetElemPtr(int pos) const
{
	if (curPosition > pos)
	{
		curPosition = 0;
		curPtr = head;
	}
	for (; curPosition < pos; curPosition++)
		curPtr = curPtr->next;
	return curPtr;
}

template<class T>
LinkList<T>::LinkList()
{
	head = new Node<T>;
	curPosition = 0;
	curPtr = head;
	count = 0;
}
template<class T>
LinkList<T>::~LinkList()
{
	Clear();
	delete head;
}
template<class T>
int LinkList<T>::Length() const
{
	return count;
}
template<class T>
bool LinkList<T>::isEmpty() const
{
	return head->next == NULL;
}
template<class T>
void LinkList<T>::Clear()
{
	T tmp;
	while (!isEmpty())
		Delete(1, tmp);
}
template<class T>
void LinkList<T>::Traverse(void(*visit)(const T &)) const
{
	Node<T> *cPtr = head->next;
	while (cPtr != NULL)
	{
		(*visit)(cPtr->data);
		cPtr = cPtr->next;
	}
}
template<class T>
bool LinkList<T>::GetElem(int position, T &e) const
{
	if (position<1 || position>Length())
		return false;
	else
	{
		Node<T> *tmpPtr = GetElemPtr(position);
		e = tmpPtr->data;
		return true;
	}
}
template<class T>
bool LinkList<T>::SetElem(int positon, const T &e)
{
	if (position<1 || position>Length())
		return false;
	else
	{
		Node<T> *tmpPtr = GetElemPtr(position);
		tmpPtr->data = e;
		return true;
	}
}
template<class T>
bool LinkList<T>::Delete(int position, T &e)
{
	if (position<1 || position>Length())
		return false;
	else
	{
		Node<T> *tmpPtr = GetElemPtr(position - 1);
		Node<T> *delPtr = tmpPtr->next;
		e = delPtr->data;
		tmpPtr->next = delPtr->next;
		delete delPtr;
		if (position == Length())
		{
			curPosition = 0;
			curPtr = head;
		}
		else
		{
			curPosition = position;
			curPtr = tmpPtr->next;
		}
		count--;
		return true;
	}
}
template<class T>
bool LinkList<T>::Insert(int position, const T &e)
{
	if (position<1 || position>Length() + 1)
		return false;
	else
	{
		Node<T> *tmpPtr = GetElemPtr(position - 1);
		Node<T> *newPtr = new Node<T>(e, tmpPtr->next);
		tmpPtr->next = newPtr;
		curPosition = position;
		curPtr = newPtr;
		count++;
		return true;
	}
}
template<class T>
LinkList<T>::LinkList(const LinkList<T> &copy)
{
	head = new Node<T>;
	curPosition = 0;
	curPtr = head;
	count = copy.count;
	Node<T> *tmpPtr = head;
	Node<T> *curPtr = copy.head->next;
	while (curPtr != NULL)
	{
		tmpPtr->next = new Node<T>(curPtr->data);
		curPtr = curPtr->next;
		tmpPtr = tmpPtr->next;
	}
}
template<class T>
LinkList<T> &LinkList<T>::operator=(const LinkList<T> &copy)
{
	if (&copy != this)
	{
		Clear();
		curPosition = 0;
		curPtr = head;
		count = copy.count;
		Node<T> *tmpPtr = head;
		Node<T> *curPtr = copy.head->next;
		while (curPtr != NULL)
		{
			tmpPtr->next = new Node<T>(curPtr->data);
			curPtr = curPtr->next;
			tmpPtr = tmpPtr->next;
		}
	}
	return *this;
}

#endif // !_LINKLIST_H_
