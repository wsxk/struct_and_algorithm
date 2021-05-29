#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mintablesize 7

typedef int element;
struct listnode; 
typedef struct listnode * position;
struct hashtb1;
typedef struct hashtb1 * hashtable;

struct listnode{
    element x;
    position next;
};

struct hashtb1{
    int tablesize;
    position * list;
};

hashtable createtable(int tablesize);//创建空散列
position find(element x,hashtable s);//查找元素
void insert(element x,hashtable s);//插入元素
void delete(element x,hashtable s);//删除元素
void show(hashtable s);//展示所有元素
int findpoint(element x,hashtable s);//找到应该插入的点
void release(hashtable s);//清空内存