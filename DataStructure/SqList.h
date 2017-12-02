
//顺序表类模板

#ifndef _SQLIST_H_
#define _SQLIST_H_

#define DEFAULT_SIZE 30

template<class T>
class SqList
{
public:
	SqList(int size = DEFAULT_SIZE);
	virtual~SqList();
	int Length() const;
	bool isEmpty() const;
	void Clear();
	void Traverse(void(*visit)(const T &)) const;
	bool GetElem(int position, T &e) const;
	bool SetElem(int position, const T &e);
	bool Delete(int position, T &e);
	bool Insert(int position, const T &e);
	SqList(const SqList<T> &copy);
	SqList<T> &operator=(const SqList<T> &copy);

protected:
	int count;			//元素个数
	int maxSize;		//最大元素个数
	T *elems;			//存储元素
};

template<class T>
SqList<T>::SqList(int size)
{
	maxSize = size;
	elems = new T[maxSize];
	count = 0;
}
template<class T>
SqList<T>::~SqList()
{
	delete[]elems;
}
template<class T>
int SqList<T>::Length() const
{
	return count;
}
template<class T>
bool SqList<T>::isEmpty() const
{
	return count == 0;
}
template<class T>
void SqList<T>::Clear()
{
	count == 0;
}
template<class T>
void SqList<T>::Traverse(void(*visit)(const T &)) const
{
	for (int i = 0; i < count; i++)
		(*visit)(elems[i]);
}
template<class T>
bool SqList<T>::GetElem(int position, T &e) const
{
	if (position<1 || position>count)
		return false;
	else
	{
		e = elems[position - 1];
		return true;
	}
}
template<class T>
bool SqList<T>::SetElem(int position, const T &e)
{
	if (position<1 || position>count)
		return false;
	else
	{
		elems[position] = e;
		return true;
	}
}
template<class T>
bool SqList<T>::Delete(int position, T &e)
{
	if (position<1 || position>count)
		return false;
	else
	{
		e = elems[position - 1];
		for (int pos = position; pos < count; pos++)
			elems[pos - 1] = elems[pos];
		count--;
		return true;
	}
}
template<class T>
bool SqList<T>::Insert(int position, const T &e)
{
	if (count == maxSize)
		return false;
	else if (position<1 || position>count + 1)
		return false;
	else
	{
		for (int pos = count; pos >= position; pos--)
			elems[pos] = elems[pos - 1];
		elems[position - 1] = e;
		count++;
		return true;
	}
}
template<class T>
SqList<T>::SqList(const SqList<T> &copy)
{
	maxSize = copy.maxSize;
	count = copy.count;
	elems = new T[maxSize];

	for (int i = 0; i < count; i++)
		elems[i] = copy.elems[i];
}
template<class T>
SqList<T> &SqList<T>::operator=(const SqList<T> &copy)
{
	if (&copy != this)
	{
		if (elems != NULL)
			delete[]elems;

		maxSize = copy.maxSize;
		count = copy.count;
		elems = new T[maxSize];

		for (int i = 0; i < count; i++)
			elems[i] = copy.elems[i];
	}
	return *this;
}

#endif // !_SQLIST_H_
