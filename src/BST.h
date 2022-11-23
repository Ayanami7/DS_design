#pragma once
#include"BinTree.h"

template <typename T>
class BST : public BinTree<T>   //����BinTree������BST
{
public:         //ʹ���鷽��ʹ�̳г�Ա����д�÷���
    virtual BinNode<T> *&Search(const T &e);    //����e
    virtual BinNode<T> *Insert(const T &e);     //����e
    virtual bool Del(const T &e);               //ɾ��e
};



template <typename T>
BinNode<T> *BST<T>::Insert(const T &e)
{
    BinNode<T> *sa = nullptr;
    return sa;
}

template <typename T>
bool BST<T>::Del(const T &e)
{
    return false;
}

template <typename T>
BinNode<T> *& BST<T>::Search(const T &e)
{
    return Search_In(this->_root, e);
}

template <typename T>
BinNode<T> *&Search_In(BinNode<T> *&x, const T &e)
{
    if (x == nullptr || x->data == e)
        return x;
    else if (e < x->data)
        return Search_In(x->lc, e);
    else
        return Search_In(x->rc, e);
}