
//循环队列类模板

#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_
#define DEFAULT_SIZE 30

template<class T>
class SqQueue
{
public:
	SqQueue(int size = DEFAULT_SIZE);
	virtual~SqQueue();
	int Length() const;
	bool isEmpty() const;
	void Clear();
	void Traverse(void(*visit)(const T &)) const;
	bool GetHead(T &e) const;
	bool OutQueue(T &e);
	bool InQueue(const T &e);
	SqQueue(const SqQueue<T> &copy);
	SqQueue<T> &operator=(const SqQueue<T> &copy);

protected:
	int front, rear;
	int count;
	int maxSize;
	T *elems;
};

template<class T>
SqQueue<T>::SqQueue(int size)
{
	maxSize = size;
	count = 0;
	front = rear = 0;
	elems = new T[maxSize];
}
template<class T>
SqQueue<T>::~SqQueue()
{
	delete[]elems;
}
template<class T>
int SqQueue<T>::Length() const
{
	return count;
}
template<class T>
bool SqQueue<T>::isEmpty() const
{
	return count == 0;
}
template<class T>
void SqQueue<T>::Clear()
{
	count == 0;
	rear = front = 0;
}
template<class T>
void SqQueue<T>::Traverse(void(*visit)(const T &)) const
{
	for (int i = front; i != rear; i = (i + 1) % maxSize)
		(*visit)(elems[i]);
}
template<class T>
bool SqQueue<T>::GetHead(T &e) const
{
	if (!isEmpty())
	{
		e = elems[front];
		return true;
	}
	else
		return false;
}
template<class T>
bool SqQueue<T>::OutQueue(T &e)
{
	if (!isEmpty())
	{
		e = elems[front];
		front = (front + 1) % maxSize;
		count--;
		return true;
	}
	else
		return false;
}
template<class T>
bool SqQueue<T>::InQueue(const T &e)
{
	if (count == maxSize)
		return false;
	else
	{
		elems[rear] = e;
		rear = (rear + 1) % maxSize;
		count++;
		return true;
	}
}
template<class T>
SqQueue<T>::SqQueue(const SqQueue<T> &copy)
{
	maxSize = copy.maxSize;
	count = copy.count;
	front = copy.front;
	rear = copy.rear;
	elems = new T[maxSize];
	
	for (int i = front; i != rear; i = (i + 1) % maxSize)
		elems[i] = copy.elems[i];
}
template<class T>
SqQueue<T> &SqQueue<T>::operator=(const SqQueue<T> &copy)
{
	if (&copy != this)
	{
		delete[]elems;
		maxSize = copy.maxSize;
		count = copy.count;
		front = copy.front;
		rear = copy.rear;
		elems = new T[maxSize];

		for (int i = front; i != rear; i = (i + 1) % maxSize)
			elems[i] = copy.elems[i];
	}
	return *this;
}

#endif // !_SQQUEUE_H_
