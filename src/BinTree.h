#pragma once
#include"BinNode.h"

template <typename T> 
class BinTree           //基于BinNode抽象出BinTree类
{
protected:
	int _size;                                   //规模
    BinNode<T> *_root;                           //根节点
public:
	BinTree() : _size(0), _root(nullptr) {};        //构造函数
    ~BinTree()                                      //析构函数
    {
        if (0 < _size)
            Remove(_root);
    }

    //基本操作接口
    int size() const { return _size; }              //返回规模大小
    BinNode<T> *root() { return _root; }	        //返回根节点
	bool Empty() const { return !_root; }           //判空
    void Del(BinNode<T> *x);                        //递归的删除以位置x处节点为根的子树
    BinNode<T> *Insert_as_root(T const &e);         //将数据作为根节点插入
	BinNode<T> *Attach_as_lc(BinNode<T> *x, BinTree<T> *&S);		//将一棵二叉树S作为x的左子树插入
	BinNode<T> *Attach_as_rc(BinNode<T> *x, BinTree<T> *&S);		//将一棵二叉树S作为x的右子树插入
};