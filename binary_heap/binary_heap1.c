#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minsize 16

typedef int element;

struct heapstruct;
typedef struct heapstruct * priorityqueue;

struct heapstruct
{
    int capacity;
    int size;
    element * elements;
};

priorityqueue create(int number);//创造一个堆
void destroy(priorityqueue s);//释放内存
void makeempty(priorityqueue s);//情况堆
void insert(element x,priorityqueue s);//插入
void deletemin(priorityqueue s);//删除最小元素
element findmin(priorityqueue s);//找到最小元素
int isempty(priorityqueue s);//判断堆是否为空
int isfull(priorityqueue s);//判断堆是否已满
void show(priorityqueue s);//展示所有元素

