
//二叉树结点类模板

#ifndef _BINTREENOFR_H_
#define _BINTREENODE_H_

template<class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T> *leftChild;
	BinTreeNode<T> *rightChild;

	BinTreeNode();
	BinTreeNode(const T &val, BinTreeNode<T> *lChild = NULL, BinTreeNode<T> *rChild = NULL);
};

template<class T>
BinTreeNode<T>::BinTreeNode()
{
	leftChild = NULL;
	rightChild = NULL;
}
template<class T>
BinTreeNode<T>::BinTreeNode(const T &val, BinTreeNode<T> *lChild, BinTreeNode<T> *rChild)
{
	data = val;
	leftChild = lChild;
	rightChild = rChild;
}

#endif // !_BINTREENOFR_H_
