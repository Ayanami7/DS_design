#pragma once
#include "BinNode.h"
#include <queue>
#include <vector>

template <typename T> 
class BinTree           //����BinNode�����BinTree��
{
protected:
	int _size;                                   //��ģ
    BinNode<T> *_root;                           //���ڵ�
public:
	BinTree() : _size(0), _root(nullptr) {};        //���캯��
    ~BinTree()                                      //��������
    {
        if (0 < _size)
            Remove_At(_root);
    }

    //���������ӿ�
    int size() const { return _size; }                      //���ع�ģ��С
    BinNode<T> *root() { return _root; }	                //���ظ��ڵ�
	bool Empty() const { return !_root; }                   //�п�
    void Reomve(BinNode<T> *x) { Remove_At(x); }        //�ݹ��ɾ����λ��x���ڵ�Ϊ��������
    BinNode<T> *Insert_as_root(T const &e);                 //��������Ϊ���ڵ����
	BinNode<T> *Attach_as_lc(BinNode<T> *x, BinTree<T> *&S);		//��һ�ö�����S��Ϊx������������
	BinNode<T> *Attach_as_rc(BinNode<T> *x, BinTree<T> *&S);		//��һ�ö�����S��Ϊx������������
    int Level_init(std::vector<T> &v);                      //ʹ��vector��ι���һ�ö�����
    template <typename VST> void Pred_travel(VST *visit)         //ǰ�к��������ͨ���Ը��ڵ���ö�Ӧ��BinNode��������ʵ��
    {
        Pred_travel_At(_root, visit);
    }
    template <typename VST> void In_travel(VST *visit)
    {
        In_travel_At(_root, visit);
    }
    template <typename VST> void Succ_travel(VST *visit)
    {
        Succ_travel_At(_root, visit);
    }
};

template <typename T>
BinNode<T> *BinTree<T>::Insert_as_root(T const &e)
{
    BinNode<T> *root = new BinNode<T>(e);
    _root = root;
    _size++;
}

template <typename T>
BinNode<T> *BinTree<T>::Attach_as_lc(BinNode<T> *x, BinTree<T> *&S)
{
    if (S->root())
        x->lc = S->root();
    _size += S->size();     //���¹�ģ

    S->_root = nullptr;     //ɾ����S
    S->_size = 0;
	delete S;
	S = nullptr;
    return x;               //���ؽ���λ��
}

template <typename T>
BinNode<T> *BinTree<T>::Attach_as_rc(BinNode<T> *x, BinTree<T> *&S)
{
    if (S->root())
        x->rc = S->root();
    _size += S->size();     

    S->_root = nullptr;     
    S->_size = 0;
	delete S;
	S = nullptr;
    return x;               
}

template <typename T>
int BinTree<T>::Level_init(std::vector<T> &v)
{
    if(v.empty())
        return -1;
    int n = static_cast<int>(v.size());     //size_tתΪn
    std::queue<BinNode<T> *> q;             //��������
    _root = new BinNode<T>(v[0]);           //�Ƚ����ڵ����
    q.push(_root);
    int i = 1;
    while (i != n)
    {
        if (q.front()->lc == nullptr)
        {
            BinNode<T> *temp = new BinNode<T>(v[i]);
            q.front()->lc = temp;
            q.push(temp);
            i++;
        }
        else if(q.front()->rc == nullptr)
        {
            BinNode<T> *temp = new BinNode<T>(v[i]);
            q.front()->rc = temp;
            q.push(temp);
            q.pop();        //�����ýڵ�
            i++;
        }
    }

    return 0;
}