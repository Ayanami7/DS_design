#pragma once
#include <iostream>

template <typename T>   //�������ڵ�ģ����
class BinNode
{
public:
    T data;             //����
    BinNode<T> *lc;     //����
    BinNode<T> *rc;     //�Һ���
	BinNode() : lc(nullptr), rc(nullptr){}      //�������캯��
	BinNode(T x) : data(x), lc(nullptr), rc(nullptr){}      
	BinNode(T x, BinNode<T> *a, BinNode<T> *b) : data(x), lc(a), rc(b){}
	~BinNode(){};                               //��������
};