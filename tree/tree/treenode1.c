#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct treenode * tree;

struct treenode{
    element x;
    tree left;
    tree right;
};

tree insert(tree s,element x);//插入数据
tree delete(tree s,element x);//delete data
void retrieve(tree s);//show the data
tree find(tree s,element x);//查找数据
tree findmin(tree s);//找最小
tree findmax(tree s);//找最大
tree freetree(tree s);//清空树，释放内存
