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

    std::cout << "��������Ϊ" << std::endl;
    tree.Pred_travel(print);
    std::cout << std::endl;

    std::cout << "��������Ϊ" << std::endl;
    tree.In_travel(print);
    std::cout << std::endl;

    Solution solution;
    solution.MaxsumBST(&tree);

    BinNode<int> *temp = solution.maxNode;
    int max = solution.maxRes;
    
    std::cout << "����ֵΪ" << max << std::endl;
    std::cout << "����������ڵ��Ӧ��ֵΪ" << temp->data << std::endl;
    std::cout << "���������������Ϊ" << std::endl;
    In_travel_At(temp, print);

    system("pause");
    return 0;
}