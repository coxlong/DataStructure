
//树的双亲表示法

#ifndef _PARENTTREE_H_
#define _PARENTTREE_H_

#define DEFAULT_SIZE 30

template<class T>
struct ParentTreeNode
{
	T data;
	int parent;
	ParentTreeNode();
	ParentTreeNode(const T &val, int pt = -1);
};
template<class T>
ParentTreeNode<T>::ParentTreeNode()
{
	parent = -1;
}
template<class T>
ParentTreeNode<T>::ParentTreeNode(const T &val, int pt)
{
	data = val;
	parent = pt;
}


template<class T>
class ParentTree
{
public:
	ParentTree();
	virtual~ParentTree();
	int GetRoot() const;
	bool isEmpty() const;
	bool GetElem(int cur, T &e) const;
	bool SetElem(int cur, const T &e);
	void PreRootOrder(void(*visit)(const T &)) const;
	void PostRootOrder(void(*visit)(const T &)) const;
	void LevelOrder(void(*visit)(const T &)) const;
	int NodeCount() const;
	int NodeDegree(int cur) const;
	int Degree() const;
	int FirstChild(int cur) const;
	int RightSibling(int cur) const;
	int Parent(int cur) const;
	bool InsertChild(int cur, int i, const T &e);	//将数据元素插入为cur的第i个孩子
	bool DeleteChild(int cur, int i);				//删除cur的第i棵子树
	int Height() const;
	ParentTree(const ParentTree<T> &copy);
	ParentTree(T items[], int parents[], int r, int n, int size = DEFAULT_SIZE);
	ParentTree<T> &operator=(cosnt ParentTree<T> &copy);
	
protected:
	ParentTreeNode<T> *nodes;
	int maxSize;
	int root, num;

};


#endif // !_PARENTTREE_H_
