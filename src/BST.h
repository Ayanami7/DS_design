#pragma once
#include"BinTree.h"

template <typename T>
class BST : public BinTree<T>   //����BinTree������BST
{
public:         //ʹ���鷽��ʹ����������д�÷���
    virtual BinNode<T> *&Search(const T &e);    //����e
    virtual BinNode<T> *Insert(const T &e);     //����e
    virtual bool Del(const T &e);               //ɾ��e
};

template <typename T>
BinNode<T> *BST<T>::Insert(const T &e)      //���ظ��ڵ�
{
    if (this->_root == nullptr)             //����Ϊ�գ����Ȳ�����ڵ�
    {                                       
        this->_root = new BinNode<T>(e);
        this->_size++;                      //ģ��������������Ҫ���ʻ����Ա��Ҫ����this->
        return this->_root;
    }
    if(!Search(e))      //��������ֵͬʱ�����벻��ִ�У������Ҫ�ֶ��жϹ�ģ�Ƿ�����
        this->_size++;          
    BinNode<T> *node = Insert_In(this->_root, e);
    return node;
} 

template <typename T>
BinNode<T>* Insert_In(BinNode<T>* root, const T &e) 
{
    //������ֹ��������ǰ�ڵ�Ϊ�գ�˵���������ֵ��Ӧ�ò��뵽�������ڵ㣬���ظýڵ�
    if (root == nullptr) 
    {
        BinNode<T>* node = new BinNode<T>(e);
        return node;
    }

    //��������ѭ�����������ڵ�ֵ���ڸ���ֵ������������ͬʱ���ܵݹ麯�����صĽڵ���Ϊ�Լ������ӣ���ɸ��ӽڵ㸳ֵ
    if (root->data > e)
        root->lc = Insert_In(root->lc, e);
    //��������ѭ�����������ڵ�ֵС�ڸ���ֵ������������ͬʱ���ܵݹ麯�����صĽڵ���Ϊ�Լ����ɺ��ӣ���ɸ��ӽڵ㸳ֵ
    if (root->data < e)
        root->rc = Insert_In(root->rc, e);
    return root;
}

template <typename T>
bool BST<T>::Del(const T &e)
{
    BinNode<T> *temp = Search(e);
    if(temp == nullptr)
        return false;
    Del_In(this->_root, temp);
    return true;
}

template <typename T>
void Del_In(BinNode<T>* &root,BinNode<T>* &cur)
{
    if(cur->lc ==nullptr)
    {
        if(cur == root)
        {
            root = cur->rc;
        }
        if(cur == root->lc)
        {
            root->lc = cur->rc;
        }
        if(cur == root->rc)
        {
            root->rc = cur->rc;
        }
    }
    else if (cur->rc == nullptr)
    {
        if(cur == root)
        {
            root = cur->lc;
        }
        if(cur == root->lc)
        {
            root->lc=cur->lc;
        }
        if(cur == root->rc){
            root->rc=cur->lc;
        }
    }
    else
    {
        BinNode<T> *target = cur->rc;
        BinNode<T> * targetParent = cur;
        while (target->lc!=nullptr)
        {
            targetParent = target;
            target = target->lc;
        }
        cur->data = target->data;
        if(target == targetParent->lc)
        {
            targetParent->lc = target->rc;
        }
        else
        {
            targetParent->rc = target->rc;
        }
    }
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