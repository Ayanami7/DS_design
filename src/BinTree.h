#pragma once
#include "BinNode.h"

template <typename T>
class BinTree //基于BinNode抽象出BinTree类
{
protected:
	int _size;                                   //规模
    BinNode<T> *_root;                           //根节点
public:
	BinTree() : _size(0), _root(nullptr) {};        //构造函数
    virtual ~BinTree()                                      //析构函数
    {
        if (0 < _size)
            Remove_At(_root);
    }

    //基本操作接口.
    int size() const { return _size; }                      //返回规模大小
    BinNode<T> *root() { return _root; }	                //返回根节点
	bool Empty() const { return !_root; }                   //判空
    void Reomve(BinNode<T> *x) { Remove_At(x); }        //递归的删除以位置x处节点为根的子树
    BinNode<T> *Find_Parent(BinNode<T> *x);
    BinNode<T> *Insert_as_root(T const &e);                 //将数据作为根节点插入      返回接入位置（下同）
    BinNode<T> *Insert_as_lc(BinNode<T> *x, T const &e);    //将数据作为某节点的左节点插入
    BinNode<T> *Insert_as_rc(BinNode<T> *x, T const &e);    //将数据作为某节点的右节点插入
    BinNode<T> *Attach_as_lc(BinNode<T> *x, BinTree<T> *&S);		//将一棵二叉树S作为x的左子树插入
	BinNode<T> *Attach_as_rc(BinNode<T> *x, BinTree<T> *&S);		//将一棵二叉树S作为x的右子树插入
    int Level_init(std::vector<T> &v);                              //使用vector层次构建一棵二叉树  返回-1则构建失败
    template <typename VST> void Pred_travel(VST *visit)         //前中后序遍历，通过对根节点调用对应的BinNode遍历方法实现
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
	BinTree(const BinTree<T>&);		        //阻止copying
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
    int n = static_cast<int>(v.size());     //size_t转为int
    std::queue<BinNode<T> *> q;             //辅助队列
    _root = new BinNode<T>(v[0]);           //先将根节点插入
    _size++;
    q.push(_root);
    int i = 1;
    bool flag = true;       //用于判断插入左侧还是右侧
    while (i != n)          //若为false时，证明左子节点虽为空但已经被构造过
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
                q.pop();        //弹出该节点
                i++;
            }
            else
            {
                q.pop();        //弹出该节点
                i++;
            }
            flag = true;
        }
    }

    return 0;
}


