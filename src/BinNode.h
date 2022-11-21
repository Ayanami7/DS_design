#pragma once
#include <iostream>

template <typename T>   //二叉树节点模板类
class BinNode
{
public:
    T data;             //数据
    BinNode<T> *lc;     //左孩子
    BinNode<T> *rc;     //右孩子
    BinNode() : lc(nullptr), rc(nullptr){}      //三个构造函数
    BinNode(T x) : data(x), lc(nullptr), rc(nullptr){}      
	BinNode(T x, BinNode<T> *a, BinNode<T> *b) : data(x), lc(a), rc(b){}
	~BinNode(){};                               //析构函数
};

template <typename T>
void Remove_At(BinNode<T> *root) //删除以root为根的树
{
    if(root == nullptr)
        return;
    Remove_At(root->lc);
    Remove_At(root->rc);         //递归释放左右子树
    delete root;                //删除对应空间并将指针置空
    root = nullptr;
}

template <typename T, typename VST>     //对节点root进行先序遍历，需传入操作器
void Pred_travel_At(BinNode<T> *root, VST *visit)
{
    if(root == nullptr)
		return;
    visit(root->data);
    Pred_travel_At(root->lc, visit);
    Pred_travel_At(root->rc, visit);
}

template <typename T, typename VST>     //对节点root进行中序遍历，需传入操作器
void In_travel_At(BinNode<T> *root, VST *visit)
{
    if(root == nullptr)
		return;
    In_travel_At(root->lc, visit);
    visit(root->data);
	In_travel_At(root->rc, visit);
}

template <typename T, typename VST>     //对节点root进行后序遍历，需传入操作器
void Succ_travel_At(BinNode<T> *root, VST *visit)
{
        if(root == nullptr)
		return;
    visit(root->data);
    Succ_travel_At(root->lc, visit);
	Succ_travel_At(root->rc, visit);
    visit(root->data);
}