#pragma once
#include <iostream>
#include <queue>
#include <vector>

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

//��������
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

template <typename T>           //���ڱ�д���������Ĳ����ӿڣ�Ѱ��һ���ڵ�ĸ��ڵ�
BinNode<T> *Find_Parent_At(BinNode<T> *root, BinNode<T> *x)
{
    if (root->lc == x || root->rc == x)
        return root;
    
    if(root->lc)
        return Find_Parent_At(root->lc, x);
    if(root->rc)
        return Find_Parent_At(root->rc, x);

    return nullptr;
}

template <typename T, typename VST>     //�Խڵ�root��������������贫���������
void Pred_travel_At(BinNode<T> *root, VST *visit)
{
    if(root == nullptr)
		return;
    if (visit != nullptr) //������������Ϊ�գ���ִ��
        visit(root->data);
    Pred_travel_At(root->lc, visit);
    Pred_travel_At(root->rc, visit);
}

template <typename T, typename VST>     //�Խڵ�root��������������贫���������
void In_travel_At(BinNode<T> *root, VST *visit)
{
    if(root == nullptr)
		return;
    In_travel_At(root->lc, visit);
    if(visit != nullptr)                          //������������Ϊ�գ���ִ��
        visit(root->data);
	In_travel_At(root->rc, visit);
}

template <typename T, typename VST>     //�Խڵ�root���к���������贫���������
void Succ_travel_At(BinNode<T> *root, VST *visit)
{
    if(root == nullptr)
		return;
    Succ_travel_At(root->lc, visit);
	Succ_travel_At(root->rc, visit);
    if(visit != nullptr)                          //������������Ϊ�գ���ִ��
        visit(root->data);
}

template <typename T, typename VST>     //�Խڵ�root���в�α������贫���������
void Level_travel_At(BinNode<T> *root, VST *visit)
{
    BinNode<T> *temp = root;
    if (root == nullptr)
        return;
    std::queue<BinNode<T> *> q;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp != nullptr)
		{
            visit(temp->data);
            q.push(temp->lc);
			q.push(temp->rc);
		}
	}
}