#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//这是一个构建链表的程序
#define Maxsize 100

typedef int element;    //定义                
typedef struct listnode * list;

struct listnode
{
    element ele;
    list next ;
};
//链表带有表头
//链表具有的功能
list InitList(list L);            
list DestroyList(list L);
list ClearList(list L);
int IsEmpty(list L);
int ListLength(list L);
element GetItem(list L,int i,element * e);
element LocateElem(list L,element e,int (*compare)(element i,element j));
element PriorElem(list L,element cur_e,element pre_e);
element NextElem(list L,element cur_e,element next_e);
void InsertList(list L,int i,element e);
void DeleteList(list L,int i,element *e);
void ListTraverse(list L,void (*visit)(list L));


