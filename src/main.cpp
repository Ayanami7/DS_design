#include <vector>
#include "BST.h"
#include "MaxsumBST.h"

std::vector<std::vector<int> > List;
std::vector<int> sample;

void Init_sample()      //初始化测试用例
{
    sample = {1, 4, 3, 2, 4, 2, 5, NULL, NULL, NULL, NULL, NULL, NULL, 4, 6};
    List.push_back(sample);
    sample.clear();

    sample = {-4, -2, -5, -3 -2, -7};
    List.push_back(sample);
    sample.clear();

    sample = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    List.push_back(sample);
    sample.clear();

    sample = {1, 10, 12, 8, 12, 9, 15, 6, 9};
    List.push_back(sample);
    sample.clear();

    sample = {25, 14, 31, 9, 17, 27, 33, 7, 10, NULL, NULL, 26, 28};
    List.push_back(sample);
    sample.clear();

    sample = {20, 14, 15, 7, 16, 13, 30, NULL, NULL, NULL, NULL, 10, 19};
    List.push_back(sample);
    sample.clear();

    sample = {NULL};
    List.push_back(sample);
    sample.clear();

}

void print(int x)       //操作函数，操作器详见BinNode.h
{                       //此处是直接打印
    std::cout << x << " ";
}

int main(void)
{
    Init_sample();
    BinTree<int> *tree;
    Solution solution;
    int i = 1;
    for (auto l : List)
    {
        tree = new BinTree<int>;
        tree->Level_init(l);

        std::cout << "以下为第" << i++ << "个测试用例" << std::endl;
        std::cout << "该二叉树拥有" << tree->size() << "个节点" << std::endl;

        std::cout << "先序序列为:" << std::endl;
        tree->Pred_travel(print);

        std::cout << "中序序列为:" << std::endl;
        tree->In_travel(print);

        std::cout << "后序序列为:" << std::endl;
        tree->Succ_travel(print);

        solution.MaxsumBST(tree);
        int maxRes = solution.maxRes;
        BinNode<int> *maxNode = solution.maxNode;

        if (maxRes <= 0)
        {
            std::cout << "最大键值和为" << 0 << std::endl;
            std::cout << "所有节点键值都为负数，不存在最大的子二叉搜索树" << std::endl;
        }
        else if (maxNode->lc == nullptr&&maxNode->rc == nullptr)
        {
            std::cout << "最大键值和为" << maxRes << std::endl;
            std::cout << "该二叉树没有拥有超过一个节点的子二叉搜索树！" << std::endl;
        }
        else
        {
            std::cout << "最大键值和为" << maxRes << std::endl;
            std::cout << "对应的BST根节点键值为" << maxNode->data << std::endl;
            std::cout << "对应的BST层次序列为" << std::endl;
            Level_travel_At(maxNode, print);
            std::cout << std::endl;
            std::cout << "对应BST中序序列为" << std::endl;
            In_travel_At(maxNode, print);
            std::cout << std::endl;
        }

        std::cout << std::endl;
        std::cout << std::endl;
        delete tree;
        system("pause");
    }

    system("pause");
    return 0;
}