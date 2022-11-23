#pragma once
#include "BST.h"

//���������
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

    //���ڸú����ݹ�����Ҫ���ݵı����϶࣬�ʲ���һ��vector����
    //�����ֱ�Ϊ
    //�Ƿ�ΪBST����Сֵ�����ֵ���ڵ��
    std::vector<int> DFS(BinNode<int> *x)
    {
        if (x == nullptr) //�ݹ�������սڵ㷵��ֵ
            return {true, INT_MAX, INT_MIN, 0};
        auto lcvec = DFS(x->lc);
        auto rcvec = DFS(x->rc);
        int sum = lcvec[3] + rcvec[3] + x->data; //�����������ļ�ֵ�����������

        bool isBST;     //�жϱ�־��������ֵ��һ��
        // BST�ж��������������������ֵ��С����������Сֵ��������ΪBST
        if (x->data > lcvec[2] && x->data < rcvec[1] && lcvec[0] && rcvec[0]) 
            isBST = true;
        else
            isBST = false;

        if(isBST)
        {
            if(maxRes < sum)
            {
                maxRes = sum;       //�������ֵ������ڵ�λ��
                maxNode = x;
            }
        }
        //���������Сֵ
        int maxNum = std::max(std::max(lcvec[2], rcvec[2]), x->data);
        int minNum = std::min(std::min(lcvec[1], rcvec[1]), x->data);
        return {isBST, minNum, maxNum, sum};
    }
};