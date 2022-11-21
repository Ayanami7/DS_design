#pragma once
#include"BinNode.h"

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
            Remove(_root);
    }

    //���������ӿ�
    int size() const { return _size; }              //���ع�ģ��С
    BinNode<T> *root() { return _root; }	        //���ظ��ڵ�
	bool Empty() const { return !_root; }           //�п�
    void Del(BinNode<T> *x);                        //�ݹ��ɾ����λ��x���ڵ�Ϊ��������
    BinNode<T> *Insert_as_root(T const &e);         //��������Ϊ���ڵ����
	BinNode<T> *Attach_as_lc(BinNode<T> *x, BinTree<T> *&S);		//��һ�ö�����S��Ϊx������������
	BinNode<T> *Attach_as_rc(BinNode<T> *x, BinTree<T> *&S);		//��һ�ö�����S��Ϊx������������
};