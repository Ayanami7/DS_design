#pragma once
#include "BinNode.h"
#include <queue>
#include <vector>

template <typename T> 
class BinTree           //基于BinNode抽象出BinTree类
{
protected:
	int _size;                                   //规模
    BinNode<T> *_root;                           //根节点
public:
	BinTree() : _size(0), _root(nullptr) {};        //构造函数
    ~BinTree()                                      //析构函数
    {
        if (0 < _size)
            Remove_At(_root);
    }

    //基本操作接口
    int size() const { return _size; }                      //返回规模大小
    BinNode<T> *root() { return _root; }	                //返回根节点
	bool Empty() const { return !_root; }                   //判空
    void Reomve(BinNode<T> *x) { Remove_At(x); }        //递归的删除以位置x处节点为根的子树
    BinNode<T> *Insert_as_root(T const &e);                 //将数据作为根节点插入
	BinNode<T> *Attach_as_lc(BinNode<T> *x, BinTree<T> *&S);		//将一棵二叉树S作为x的左子树插入
	BinNode<T> *Attach_as_rc(BinNode<T> *x, BinTree<T> *&S);		//将一棵二叉树S作为x的右子树插入
    int Level_init(std::vector<T> &v);                      //使用vector层次构建一棵二叉树
    template <typename VST> void Pred_travel(VST *visit)         //前中后序遍历，通过对根节点调用对应的BinNode遍历方法实现
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
    _size += S->size();     //更新规模

    S->_root = nullptr;     //删除树S
    S->_size = 0;
	delete S;
	S = nullptr;
    return x;               //返回接入位置
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
    int n = static_cast<int>(v.size());     //size_t转为n
    std::queue<BinNode<T> *> q;             //辅助队列
    _root = new BinNode<T>(v[0]);           //先将根节点插入
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
            q.pop();        //弹出该节点
            i++;
        }
    }

    return 0;
}