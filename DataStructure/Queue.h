
//链队列类模板

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "Node.h"

template<class T>
class Queue
{
public:
	Queue();
	virtual~Queue();
	int Length() const;
	bool isEmpty() const;
	void Clear();
	void Traverse(void(*visit)(const T &)) const;
	bool GetHead(T &e) const;
	bool OutQueue(T &e);
	bool InQueue(const T &e);
	Queue(const Queue<T> &copy);
	Queue<T> &operator=(const Queue<T> &copy);

protected:
	Node<T> *front, *rear;
	int count;
};

template<class T>
Queue<T>::Queue()
{
	rear = front = new Node<T>;
	count = 0;
}
template<class T>
Queue<T>::~Queue()
{
	Clear();
	delete front;
}
template<class T>
int Queue<T>::Length() const
{
	return count;
}
template<class T>
bool Queue<T>::isEmpty() const
{
	return count == 0;
}
template<class T>
void Queue<T>::Clear()
{
	T tmp;
	while (!isEmpty())
		OutQueue(tmp);
}
template<class T>
void Queue<T>::Traverse(void(*visit)(const T &)) const
{
	for (Node<T> *tmpPtr = front->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
		(*visit)(tmpPtr->data);
}
template<class T>
bool Queue<T>::GetHead(T &e) const
{
	if (!isEmpty())
	{
		e = front->next->data;
		return true;
	}
	else
		return false;
}
template<class T>
bool Queue<T>::OutQueue(T &e)
{
	if (!isEmpty())
	{
		Node<T> *tmpPtr = front->next;
		e = tmpPtr->data;
		front->next = tmpPtr->next;
		if (rear == tmpPtr)
			rear = front;
		delete tmpPtr;
		count--;
		return true;
	}
	else
		return false;
}
template<class T>
bool Queue<T>::InQueue(const T &e)
{
	rear->next = new Node<T>(e);
	rear = rear->next;
	count++;
	return true;
}
template<class T>
Queue<T>::Queue(const Queue<T> &copy)
{
	rear = front = new Node<T>;
	count = 0;
	for (Node<T> *tmpPtr = copy.front->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
		InQueue(tmpPtr->data);
}
template<class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &copy)
{
	if (&copy != this)
	{
		Clear();
		for (Node<T> *tmpPtr = copy.front->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
			InQueue(tmpPtr->data);
	}
	return *this;
}

#endif // !_QUEUE_H_
