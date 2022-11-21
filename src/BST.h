#pragma once
#include"BinTree.h"

template <typename T>
class BST : public BinTree<T>   //����BinTree������BST
{
public:
    virtual BinNode<T> *&Search(const T &e);    //����e
    virtual BinNode<T> *Insert(const T &e);     //����e
    virtual bool Del(const T &e);               //ɾ��e
};