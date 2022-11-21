#pragma once
#include"BinTree.h"

template <typename T>
class BST : public BinTree<T>   //基于BinTree派生出BST
{
public:
    virtual BinNode<T> *&Search(const T &e);    //搜索e
    virtual BinNode<T> *Insert(const T &e);     //插入e
    virtual bool Del(const T &e);               //删除e
};