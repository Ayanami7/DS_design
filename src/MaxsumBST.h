#pragma once
#include "BST.h"

//该算法需要同时迭代多个值，故将解决方法写成一个类


class Solution
{
public:
    int maxRes;
    BinNode<int> *maxNode;

    void MaxsumBST(BinTree<int> *tree)
    {
        maxRes = INT_MIN;
        maxNode = nullptr;
        DFS(tree->root());
    }

    //是否为BST，最小值，最大值，节点和
    std::vector<int> DFS(BinNode<int> *x)
    {
        if(x==nullptr)      //递归基
            return {true, INT_MAX, INT_MIN, 0};
        auto lcvec = DFS(x->lc);
        auto rcvec = DFS(x->rc);
        int sum = lcvec[3] + rcvec[3];  //将两个子树的键值和相加

        bool isBST;                                     //判断标志，即返回值第一项
        // BST判断条件，大于左子树最大值且小于右子树最小值且子树均为BST
        if (x->data > lcvec[2] && x->data < rcvec[1] && lcvec[0] && rcvec[0]) 
        {
            isBST = true;
        }
        else
        {
            isBST = false;
        }

        if(isBST)
        {
            if(maxRes < sum)
            {
                maxRes = sum;       //更新最大值并保存节点位置
                maxNode = x;
            }
        }
        //更新最大最小值
        int maxNum = std::max(std::max(lcvec[2], rcvec[2]), x->data);
        int minNum = std::min(std::min(lcvec[1], rcvec[1]), x->data);
        return {isBST, minNum, maxNum, sum};
    }
};