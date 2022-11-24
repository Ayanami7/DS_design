#include "DS_impl.h"

void print(int x)       //�������������������BinNode.h
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

    std::cout << "��������Ϊ" << std::endl;
    tree.In_travel(print);

    Solution solution;
    solution.MaxsumBST(&tree);

    BinNode<int> *temp = solution.maxNode;
    int max = solution.maxRes;

    std::cout << "����ֵΪ" << max << std::endl;
    std::cout << "����������ڵ��Ӧ��ֵΪ" << temp->data << std::endl;
    std::cout << "���������������Ϊ" << std::endl;
    In_travel_At(temp, print);
    std::cout << std::endl;
    std::cout << std::endl;

    BST<int> tree2;
    tree2.Insert(2);
    tree2.Insert(2);
    tree2.Insert(3);
    tree2.Insert(4);
    tree2.Insert(6);
    tree2.Insert(5);

    tree2.Del(2);
    auto t = tree2.Search(4);
    auto par = tree2.Find_Parent(t);
    if(par->lc == t)
        std::cout << par->lc->data << std::endl;
    else
        std::cout << par->rc->data << std::endl;
    std::cout << t->data << std::endl;
    std::cout << tree2.size() << std::endl;

    tree2.Pred_travel(print);
    tree2.In_travel(print);
    tree2.Succ_travel(print);

    system("pause");
    return 0;
}