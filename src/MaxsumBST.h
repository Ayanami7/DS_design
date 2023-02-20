#pragma once
#include "BinTree.h"

// 解决方法类
class Solution
{
public:
	int maxRes;			   // 最大键值的结果
	BinNode<int> *maxNode; // 最大键值子树对应的节点

	// 函数入口
	void MaxsumBST(BinTree<int> *tree);

	// 由于该函数递归中需要传递的变量较多，故采用一个vector储存
	// 变量分别为
	// 是否为BST，最小值，最大值，节点和
	std::vector<int> DFS(BinNode<int> *x);
};

void Solution::MaxsumBST(BinTree<int> *tree)
{
	maxRes = INT_MIN;
	maxNode = nullptr;
	DFS(tree->root());
}

std::vector<int> Solution::DFS(BinNode<int> *x)
{
	if (x == nullptr) // 递归基，即空节点返回值
		return {true, INT_MAX, INT_MIN, 0};
	auto lcvec = DFS(x->lc);
	auto rcvec = DFS(x->rc);
	int sum = lcvec[3] + rcvec[3] + x->data; // 将两个子树的键值和与自身相加

	bool isBST; // 判断标志，即返回值第一项
	// BST判断条件，大于左子树最大值且小于右子树最小值且子树均为BST
	if (x->data > lcvec[2] && x->data < rcvec[1] && lcvec[0] && rcvec[0])
		isBST = true;
	else
		isBST = false;

	if (isBST)
	{
		if (maxRes < sum)
		{
			maxRes = sum; // 更新最大值并保存节点位置
			maxNode = x;
		}
	}
	// 更新最大最小值
	int maxNum = std::max(std::max(lcvec[2], rcvec[2]), x->data);
	int minNum = std::min(std::min(lcvec[1], rcvec[1]), x->data);
	return {isBST, minNum, maxNum, sum};
}
