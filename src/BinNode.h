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