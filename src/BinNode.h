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

template <typename T>
void Remove_At(BinNode<T> *root) //ɾ����rootΪ������
{
    if(root == nullptr)
        return;
    Remove_At(root->lc);
    Remove_At(root->rc);         //�ݹ��ͷ���������
    delete root;                //ɾ����Ӧ�ռ䲢��ָ���ÿ�
    root = nullptr;
}

template <typename T, typename VST>     //�Խڵ�root��������������贫�������
void Pred_travel_At(BinNode<T> *root, VST *visit)
{
    if(root == nullptr)
		return;
    visit(root->data);
    Pred_travel_At(root->lc, visit);
    Pred_travel_At(root->rc, visit);
}

template <typename T, typename VST>     //�Խڵ�root��������������贫�������
void In_travel_At(BinNode<T> *root, VST *visit)
{
    if(root == nullptr)
		return;
    In_travel_At(root->lc, visit);
    visit(root->data);
	In_travel_At(root->rc, visit);
}

template <typename T, typename VST>     //�Խڵ�root���к���������贫�������
void Succ_travel_At(BinNode<T> *root, VST *visit)
{
        if(root == nullptr)
		return;
    visit(root->data);
    Succ_travel_At(root->lc, visit);
	Succ_travel_At(root->rc, visit);
    visit(root->data);
}