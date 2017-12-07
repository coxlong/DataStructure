
//链式栈类模板

#ifndef _STACK_H_
#define _STACK_H_
#include "Node.h"

template<class T>
class Stack
{
public:
	Stack();
	virtual~Stack();
	int Length() const;
	bool isEmpty() const;
	void Clear();
	void Traverse(void(*visit)(const T &)) const;
	bool Push(const T &e);
	bool Top(T &e) const;
	bool Pop(T &e);
	Stack(const Stack<T> &copy);
	Stack<T> &operator=(const Stack<T> &copy);

protected:
	Node<T> *top;
	int count;
};

template<class T>
Stack<T>::Stack()
{
	top = NULL;
	count = 0;
}
template<class T>
Stack<T>::~Stack()
{
	Clear();
}
template<class T>
int Stack<T>::Length() const
{
	return count;
}
template<class T>
bool Stack<T>::isEmpty() const
{
	return top == NULL;
}
template<class T>
void Stack<T>::Clear()
{
	T tmp;
	while (!isEmpty())
		Pop(tmp);
}
template<class T>
void Stack<T>::Traverse(void(*visit)(const T &)) const
{
	Node<T> *tmpPtr;
	Stack<T> tmpS;
	for (tmpPtr = top; tmpPtr != NULL; tmpPtr = tmpPtr->next)
		tmpS.Push(tmpPtr->data);
	for (tmpPtr = tmpS.top; tmpPtr != NULL; tmpPtr = tmpPtr->next)
		(*visit)(tmpPtr->data);
}
template<class T>
bool Stack<T>::Push(const T &e)
{
	Node<T> *newTop = new Node<T>(e, top);
	if (newTop == NULL)		//内存耗尽
		return false;
	else
	{
		top = newTop;
		count++;
		return true;
	}
}
template<class T>
bool Stack<T>::Top(T &e) const
{
	if (isEmpty())
		return false;
	else
	{
		e = top->data;
		return true;
	}
}
template<class T>
bool Stack<T>::Pop(T &e)
{
	if (isEmpty())
		return false;
	else
	{
		Node<T> *oldTop = top;
		e = top->data;
		top = oldTop->next;
		count--;
		delete oldTop;
		return true;
	}
}
template<class T>
Stack<T>::Stack(const Stack<T> &copy)
{
	if (copy.isEmpty())
	{
		top = NULL;
		count = 0;
	}
	else
	{
		top = new Node<T>(copy.top->data);
		count = copy.count;

		Node<T> *curPtr = top;
		for (Node<T> *tmpPtr = copy.top->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
		{
			curPtr->next = new Node<T>(tmpPtr->data);
			curPtr = curPtr->next;
		}
	}
}
template<class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &copy)
{
	if (&copy != this)
	{
		Clear();
		if (!copy.isEmpty())
		{
			top = new Node<T>(copy.top->data);
			count = copy.count;

			Node<T> *curPtr = top;
			for (Node<T> *tmpPtr = copy.top->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
			{
				curPtr->next = new Node<T>(tmpPtr->data);
				curPtr = curPtr->next;
			}
		}
	}
	return *this;
}

#endif // !_STACK_H_
