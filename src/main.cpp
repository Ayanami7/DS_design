#include <vector>
#include "BST.h"
#include "MaxsumBST.h"

std::vector<std::vector<int> > List;
std::vector<int> sample;

void Init_sample()      //��ʼ����������
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

void print(int x)       //�������������������BinNode.h
{                       //�˴���ֱ�Ӵ�ӡ
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

        std::cout << "����Ϊ��" << i++ << "����������" << std::endl;
        std::cout << "�ö�����ӵ��" << tree->size() << "���ڵ�" << std::endl;

        std::cout << "��������Ϊ:" << std::endl;
        tree->Pred_travel(print);

        std::cout << "��������Ϊ:" << std::endl;
        tree->In_travel(print);

        std::cout << "��������Ϊ:" << std::endl;
        tree->Succ_travel(print);

        solution.MaxsumBST(tree);
        int maxRes = solution.maxRes;
        BinNode<int> *maxNode = solution.maxNode;

        if (maxRes <= 0)
        {
            std::cout << "����ֵ��Ϊ" << 0 << std::endl;
            std::cout << "���нڵ��ֵ��Ϊ�����������������Ӷ���������" << std::endl;
        }
        else if (maxNode->lc == nullptr&&maxNode->rc == nullptr)
        {
            std::cout << "����ֵ��Ϊ" << maxRes << std::endl;
            std::cout << "�ö�����û��ӵ�г���һ���ڵ���Ӷ�����������" << std::endl;
        }
        else
        {
            std::cout << "����ֵ��Ϊ" << maxRes << std::endl;
            std::cout << "��Ӧ��BST���ڵ��ֵΪ" << maxNode->data << std::endl;
            std::cout << "��Ӧ��BST�������Ϊ" << std::endl;
            Level_travel_At(maxNode, print);
            std::cout << std::endl;
            std::cout << "��ӦBST��������Ϊ" << std::endl;
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