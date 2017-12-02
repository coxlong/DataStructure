
//结点类模板

#ifndef _NODE_H_
#define _NODE_H_

template<class T>
struct Node
{
	T data;
	Node<T> *next;

	Node();
	Node(T val, Node<T> *nextPtr = NULL);
};

template<class T>
Node<T>::Node()
{
	next = NULL;
}
template<class T>
Node<T>::Node(T val, Node<T> *nextPtr)
{
	data = val;
	next = nextPtr;
}

#endif // !_NODE_H_
