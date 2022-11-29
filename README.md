二叉搜索子树的最大键值和
==

工程结构
```
DS_DESIGN--
    |--bin                          //二进制文件
        |--BST_MaxNum.exe
    |--src                          //源码
        |--BinNode.h
        |--BinTree.h
        |--BST.h
        |--MaxSumBST.h
        |--main.cpp
    .gitignore                      //git配置文件
    CMakeLists.txt                  //CMake配置文件
```
程序使用CMake构建  
BinNode.h、BinTree.h和BST.h实现了对应的数据结构，解决问题的主要算法位于MaxsumBST.h中  
main.cpp中包含了对应的测试用例  