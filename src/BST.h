#pragma once
#include"BinTree.h"

template <typename T>
class BST : public BinTree<T>   //����BinTree������BST
{
public:
    virtual BinNode<T> *&Search(cosnt T &e);    //����e
    virtual BinNode<T> *Insert(cosnt T &e);     //����e
    virtual bool Remove(cosnt T &e);            //ɾ��e
};