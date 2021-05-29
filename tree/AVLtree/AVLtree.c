#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element ;
typedef struct AVLnode * AVLtree;
typedef AVLtree position;

struct AVLnode{
    element x;
    int height;
    AVLtree left;
    AVLtree right;
};

AVLtree makeempty(AVLtree t);//清空树
position find(element x,AVLtree t);//find the data
position findmin(AVLtree t);//find the min
position findmax(AVLtree t);//find the max
AVLtree insert(element x,AVLtree t);
AVLtree delete(element x,AVLtree t);
void show(AVLtree t);

int max(int x,int y);//find the max
int height(AVLtree T);//define the height
position singleft(AVLtree T);//左侧单旋转
position singright(AVLtree T);//右侧单旋转
position doubleleft(AVLtree T);//左侧双旋转
position doubleright(AVLtree T);//右侧双旋转