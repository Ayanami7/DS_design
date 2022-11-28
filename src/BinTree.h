#pragma once
#include "BinNode.h"

template <typename T>
class BinTree //����BinNode�����BinTree��
{
protected:
	int _size;                                   //��ģ
    BinNode<T> *_root;                           //���ڵ�
public:
	BinTree() : _size(0), _root(nullptr) {};        //���캯��
    virtual ~BinTree()                                      //��������
    {
        if (0 < _size)
            Remove_At(_root);
    }

    //���������ӿ�.
    int size() const { return _size; }                      //���ع�ģ��С
    BinNode<T> *root() { return _root; }	                //���ظ��ڵ�
	bool Empty() const { return !_root; }                   //�п�
    void Reomve(BinNode<T> *x) { Remove_At(x); }        //�ݹ��ɾ����λ��x���ڵ�Ϊ��������
    BinNode<T> *Find_Parent(BinNode<T> *x);
    BinNode<T> *Insert_as_root(T const &e);                 //��������Ϊ���ڵ����      ���ؽ���λ�ã���ͬ��
    BinNode<T> *Insert_as_lc(BinNode<T> *x, T const &e);    //��������Ϊĳ�ڵ����ڵ����
    BinNode<T> *Insert_as_rc(BinNode<T> *x, T const &e);    //��������Ϊĳ�ڵ���ҽڵ����
    BinNode<T> *Attach_as_lc(BinNode<T> *x, BinTree<T> *&S);		//��һ�ö�����S��Ϊx������������
	BinNode<T> *Attach_as_rc(BinNode<T> *x, BinTree<T> *&S);		//��һ�ö�����S��Ϊx������������
    int Level_init(std::vector<T> &v);                              //ʹ��vector��ι���һ�ö�����  ����-1�򹹽�ʧ��
    template <typename VST> void Pred_travel(VST *visit)         //ǰ�к��������ͨ���Ը��ڵ���ö�Ӧ��BinNode��������ʵ��
    {
        Pred_travel_At(_root, visit);
        std::cout << std::endl;
    }
    template <typename VST> void In_travel(VST *visit)
    {
        In_travel_At(_root, visit);
        std::cout << std::endl;
    }
    template <typename VST> void Succ_travel(VST *visit)
    {
        Succ_travel_At(_root, visit);
        std::cout << std::endl;
    }
    template <typename VST> void Level_travel(VST *visit)
    {
        Level_travel_At(_root, visit);
        std::cout << std::endl;
    }

private:
	BinTree(const BinTree<T>&);		        //��ֹcopying
    BinTree operator=(const BinTree<T> &);
};

template <typename T>
BinNode<T> *BinTree<T>::Find_Parent(BinNode<T> *x)
{
    return Find_Parent_At(_root, x);
}

template <typename T>
BinNode<T> *BinTree<T>::Insert_as_root(T const &e)
{
    BinNode<T> *temp = new BinNode<T>(e);
    _root = temp;
    _size++;
    return temp;
}

template <typename T>
BinNode<T> *BinTree<T>::Insert_as_lc(BinNode<T> *x, T const &e)
{
    BinNode<T> *temp = new BinNode<T>(e);
    x->lc = temp;
    _size++;
    return x;
}

template <typename T>
BinNode<T> *BinTree<T>::Insert_as_rc(BinNode<T> *x, T const &e)
{
    BinNode<T> *temp = new BinNode<T>(e);
    x->rc = temp;
    _size++;
    return x;
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
    int n = static_cast<int>(v.size());     //size_tתΪint
    std::queue<BinNode<T> *> q;             //��������
    _root = new BinNode<T>(v[0]);           //�Ƚ����ڵ����
    _size++;
    q.push(_root);
    int i = 1;
    bool flag = true;       //�����жϲ�����໹���Ҳ�
    while (i != n)          //��Ϊfalseʱ��֤�����ӽڵ���Ϊ�յ��Ѿ��������
    {
        if (q.front()->lc == nullptr && flag)
        {
            if(v[i])
            {
                BinNode<T> *temp = new BinNode<T>(v[i]);
                q.front()->lc = temp;
                _size++;
                q.push(temp);
                i++;
            }
            else
            {
                flag = false;
                i++;
            }

        }
        else if(q.front()->rc == nullptr)
        {
            if(v[i])
            {
                BinNode<T> *temp = new BinNode<T>(v[i]);
                q.front()->rc = temp;
                _size++;
                q.push(temp);
                q.pop();        //�����ýڵ�
                i++;
            }
            else
            {
                q.pop();        //�����ýڵ�
                i++;
            }
            flag = true;
        }
    }

    return 0;
}


