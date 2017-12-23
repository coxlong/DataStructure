
//线索二叉树结点类模板

#ifndef _THREADBINTREENODE_H_
#define _THREADBINTREENODE_H_

enum PointTagType { CHILD_PTR, THREAD_PTR };

template<class T>
struct ThreadBinTreeNode
{
	T data;
	ThreadBinTreeNode<T> *leftChild;
	ThreadBinTreeNode<T> *rightChild;
	PointTagType leftTag, rightTag;

	ThreadBinTreeNode();
	ThreadBinTreeNode(const T &val,
		ThreadBinTreeNode<T> *lChild = NULL,
		ThreadBinTreeNode<T> *rChild = NULL,
		PointTagType lTag = CHILD_PTR,
		PointTagType rTag = CHILD_PTR);
};

template<class T>
ThreadBinTreeNode<T>::ThreadBinTreeNode()
{
	leftChild = NULL;
	rightChild = NULL;
	leftTag = CHILD_PTR;
	rightTag = CHILD_PTR;
}
template<class T>
ThreadBinTreeNode<T>::ThreadBinTreeNode(const T &val, ThreadBinTreeNode<T> *lChild,
	ThreadBinTreeNode<T> *rChild, PointTagType lTag, PointTagType rTag)
{
	data = val;
	leftChild = lChild;
	rightChild = rChild;
	leftTag = lTag;
	rightTag = rTag;
}

#endif // !_THREADBINTREENODE_H_
