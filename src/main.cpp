#include "DS_impl.h"

void print(int x)
{
    std::cout << x << " ";
}

int main(void)
{
    BinTree<int> tree;
    std::vector<int> v = {1, 4, 3, 2, 4, 2, 5, NULL, NULL, NULL, NULL, NULL, NULL, 4, 6};
    tree.Level_init(v);

    std::cout << "先序序列为" << std::endl;
    tree.Pred_travel(print);
    std::cout << std::endl;

    std::cout << "中序序列为" << std::endl;
    tree.In_travel(print);
    std::cout << std::endl;

    Solution solution;
    solution.MaxsumBST(&tree);

    BinNode<int> *temp = solution.maxNode;
    int max = solution.maxRes;
    
    std::cout << "最大键值为" << max << std::endl;
    std::cout << "最大子树根节点对应键值为" << temp->data << std::endl;
    std::cout << "最大子树中序序列为" << std::endl;
    In_travel_At(temp, print);

    system("pause");
    return 0;
}