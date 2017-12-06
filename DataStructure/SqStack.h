
//À≥–Ú’ª

#ifndef _SQSTACK_H_
#define _SQSTACK_H_
#define DEFAULT_SIZE 30

template<class T>
class SqStack
{
public:
	SqStack(int size = DEFAULT_SIZE);
	virtual~SqStack();
	int Length() const;
	bool isEmpty() const;
	void Clear();
	void Traverse(void(*visit)(const T &)) const;
	bool Push(const T &e);
	bool Top(T &e) const;
	bool Pop(T &e);
	SqStack(const SqStack<T> &copy);
	SqStack<T> &operator=(const SqStack<T> &copy);

protected:
	int count;
	int maxSize;
	T *elems;
};

template<class T>
SqStack<T>::SqStack(int size)
{
	maxSize = size;
	elems = new T[maxSize];
	count = 0;
}
template<class T>
SqStack<T>::~SqStack()
{
	delete[]elems;
}
template<class T>
int SqStack<T>::Length() const
{
	return count;
}
template<class T>
bool SqStack<T>::isEmpty() const
{
	return count == 0;
}
template<class T>
void SqStack<T>::Clear()
{
	count = 0;
}
template<class T>
void SqStack<T>::Traverse(void(*visit)(const T &)) const
{
	for (int i = 0; i < count; i++)
		(*visit)(elems[i]);
}
template<class T>
bool SqStack<T>::Push(const T &e)
{
	if (count == maxSize)
		return false;
	else
	{
		elems[count++] = e;
		return true;
	}
}
template<class T>
bool SqStack<T>::Top(T &e) const
{
	if (isEmpty())
		return false;
	else
	{
		e = elems[count - 1];
		return true;
	}
}
template<class T>
bool SqStack<T>::Pop(T &e)
{
	if (isEmpty())
		return false;
	else
	{
		e = elems[--count];
		return true;
	}
}
template<class T>
SqStack<T>::SqStack(const SqStack<T> &copy)
{
	maxSize = copy.maxSize;
	elems = new T[maxSize];
	count = copy.count;
	for (int i = 0; i < count; i++)
		elems[i] = copy.elems[i];
}
template<class T>
SqStack<T> &SqStack<T>::operator=(const SqStack<T> &copy)
{
	if (&copy != this)
	{
		delete[]elems;
		maxSize = copy.maxSize;
		elems = new T[maxSize];
		count = copy.count;
		for (int i = 0; i < count; i++)
			elems[i] = copy.elems[i];
	}
	return *this;
}

#endif // !_SQSTACK_H_
