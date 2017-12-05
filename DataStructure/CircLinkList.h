
//循环链表模板类

#ifndef _CIRCLINKLIST_H_
#define _CIRCLINKLIST_H_
#include "Node.h"

template<class T>
class CircLinkList
{
public:
	CircLinkList();
	virtual~CircLinkList();
	int Length() const;
	bool isEmpty() const;
	void Clear();
	void Traverse(void(*visit)(const T &)) const;
	bool GetElem(int position, T &e) const;
	bool SetElem(int position, const T &e);
	bool Delete(int position, T &e);
	bool Insert(int position, const T &e);
	CircLinkList(const CircLinkList<T> &copy);
	CircLinkList<T> &operator=(const CircLinkList<T> &copy);

protected:
	Node<T> *head;
	Node<T> *GetElemPtr(int pos) const;
};

template<class T>
Node<T> *CircLinkList<T>::GetElemPtr(int pos) const
{
	if (pos == 0)
		return head;
	Node<T> *tmpPtr = head->next;
	int p = 1;
	while (tmpPtr != head&&p < pos)
	{
		tmpPtr = tmpPtr->next;
		p++;
	}
	if (tmpPtr != head&&pos == p)
		return tmpPtr;
	else	//查找失败
		return NULL;
}

template<class T>
CircLinkList<T>::CircLinkList()
{
	head = new Node<T>;
	head->next = head;
}
template<class T>
CircLinkList<T>::~CircLinkList()
{
	Clear();
	delete head;
}
template<class T>
int CircLinkList<T>::Length() const
{
	int count = 0;
	for (Node<T> *tmpPtr = head->next; tmpPtr != head; tmpPtr = tmpPtr->next)
		count++;
	return count;
}
template<class T>
bool CircLinkList<T>::isEmpty() const
{
	return head->next == head;
}
template<class T>
void CircLinkList<T>::Clear()
{
	T tmp;
	while (!isEmpty())
		Delete(1, tmp);
}
template<class T>
void CircLinkList<T>::Traverse(void(*visit)(const T &)) const
{
	for (Node<T> *tmpPtr = head->next; tmpPtr != head; tmpPtr = tmpPtr->next)
		(*visit)(tmpPtr->data);
}
template<class T>
bool CircLinkList<T>::GetElem(int position, T &e) const
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
bool CircLinkList<T>::SetElem(int positon, const T &e)
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
bool CircLinkList<T>::Delete(int position, T &e)
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
		return true;
	}
}
template<class T>
bool CircLinkList<T>::Insert(int position, const T &e)
{
	if (position<1 || position>Length() + 1)
		return false;
	else
	{
		Node<T> *tmpPtr = GetElemPtr(position - 1);
		Node<T> *newPtr = new Node<T>(e, tmpPtr->next);
		tmpPtr->next = newPtr;
		return true;
	}
}
template<class T>
CircLinkList<T>::CircLinkList(const CircLinkList<T> &copy)
{
	head = new Node<T>;
	head->next = head;
	Node<T> *tmpPtr = head->next;
	Node<T> *curPtr = copy.head->next;
	while (curPtr != copy.head)
	{
		tmpPtr->next = new Node<T>(curPtr->data);
		curPtr = curPtr->next;
		tmpPtr = tmpPtr->next;
	}
	tmpPtr->next = head;
}
template<class T>
CircLinkList<T> &CircLinkList<T>::operator=(const CircLinkList<T> &copy)
{
	if (&copy != this)
	{
		Clear();
		Node<T> *tmpPtr = head;
		Node<T> *curPtr = copy.head->next;
		while (curPtr != copy.head)
		{
			tmpPtr->next = new Node<T>(curPtr->data);
			curPtr = curPtr->next;
			tmpPtr = tmpPtr->next;
		}
		tmpPtr->next = head;
	}
	return *this;
}

#endif // !_CIRCLINKLIST_H_
