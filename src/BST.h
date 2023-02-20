#pragma once
#include "BinTree.h"

template <typename T>
class BST : public BinTree<T> // 基于BinTree派生出BST
{
public:										 // 使用虚方法使派生类需重写该方法
	virtual BinNode<T> *&Search(const T &e); // 搜索e
	virtual BinNode<T> *Insert(const T &e);	 // 插入e
	virtual bool Del(const T &e);			 // 删除e
};

template <typename T>
BinNode<T> *BST<T>::Insert(const T &e) // 返回根节点
{
	if (this->_root == nullptr) // 若根为空，则先插入根节点
	{
		this->_root = new BinNode<T>(e);
		this->_size++; // 模板类中派生类想要访问基类成员需要加上this->
		return this->_root;
	}
	if (!Search(e)) // 若存在相同值时，插入不会执行，因此需要手动判断规模是否增加
		this->_size++;
	BinNode<T> *node = Insert_In(this->_root, e);
	return node;
}

template <typename T>
BinNode<T> *Insert_In(BinNode<T> *root, const T &e)
{
	// 迭代终止条件：当前节点为空，说明待插入的值就应该插入到这里，构造节点，返回该节点
	if (root == nullptr)
	{
		BinNode<T> *node = new BinNode<T>(e);
		return node;
	}

	// 迭代单层循环，如果当其节点值大于给定值，向左搜索，同时接受递归函数返回的节点作为自己的左孩子，完成父子节点赋值
	if (root->data > e)
		root->lc = Insert_In(root->lc, e);
	// 迭代单层循环，如果当其节点值小于给定值，向右搜索，同时接受递归函数返回的节点作为自己的由孩子，完成父子节点赋值
	if (root->data < e)
		root->rc = Insert_In(root->rc, e);
	return root;
}

template <typename T>
bool BST<T>::Del(const T &e)
{
	BinNode<T> *temp1 = Search(e);
	BinNode<T> *parent = this->Find_Parent(temp1);
	if (temp1 == nullptr)
		return false;
	Del_In(temp1, parent, this->_root);
	this->_size--;
	return true;
}

template <typename T>
void Del_In(BinNode<T> *&x, BinNode<T> *&hot, BinNode<T> *&_root)
{
	BinNode<T> *delNode = x;
	if (x->lc == nullptr && x->rc == nullptr)
	{
		;
	}

	else if (x->lc == nullptr)
	{
		if (hot == nullptr)
		{
			_root = x->rc;
		}
		else if (hot->lc == x)
		{
			hot->lc = x->rc;
		}
		else if (hot->rc == x)
		{
			hot->rc = x->rc;
		}
	}

	else if (x->rc == nullptr)
	{
		if (hot == nullptr)
		{
			_root = x->lc;
		}
		else if (hot->lc == x)
		{
			hot->lc = x->lc;
		}
		else if (hot->rc == x)
		{
			hot->rc = x->lc;
		}
	}

	else
	{
		BinNode<T> *temp = x;
		while (temp->lc != nullptr)
		{
			temp = temp->lc;
		}
		x->data = temp->data;
		delNode = temp;
	}
	delete delNode;
	delNode == nullptr;
}

template <typename T>
BinNode<T> *&BST<T>::Search(const T &e)
{
	return Search_In(this->_root, e);
}

template <typename T>
BinNode<T> *&Search_In(BinNode<T> *&x, const T &e)
{
	if (x == nullptr || x->data == e)
		return x;
	if (e < x->data)
		return Search_In(x->lc, e);
	else
		return Search_In(x->rc, e);
}
