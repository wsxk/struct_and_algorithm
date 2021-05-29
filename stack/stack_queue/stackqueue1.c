#include <stdio.h>
#include <stdlib.h>

#define minsize 10
#define min 0
#define first (-1)

typedef int element;
typedef struct  stack * queue;

struct stack{
    int front;//队首的位置
    int sum;//队列总数
    element * line;//队伍
    int capacity;//队列能装多少人
    int tail;//队伍的末尾
};

int isempty(queue s);//确认队列是否为空
int isfull(queue s);//确认队列是否已满
queue makequeue(int X);//创建队列
void enqueue(element X,queue s);//入队
void outqueue(queue s);//出队
void makeempty(queue s);//清空队列的内容
element pop(queue s);//展示队首
element popandout(queue s);//弹出并删除队首
void freequeue(queue s);//释放内存，结束进程