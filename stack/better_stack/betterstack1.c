#include <stdio.h>
#include <stdlib.h>

#define emptytos1 (-1)
#define minstacksize (5)

typedef struct Stack * stack;
typedef int elementtype;

struct Stack{          //zhan de leixing
    int capacity;
    int topofstack1;
    int topofstack2;
    elementtype *array;
};

int isempty1(stack s);     //1号栈是否为空
int isempty2(stack s);       //2号栈是否为空
int isfull(stack s);       //栈是否满了
stack createstack(int maxelements);  //造栈
void disposestack(stack s); //清空所有栈的内容释放内存
void makeempty1(stack s);   //清空一号栈
void makeempty2(stack s);   //清空二号栈
void push1(int X,stack s);  //压入1号栈
void push2(int X,stack s);   //压入2号栈
elementtype top1(stack s);           //返回1号栈的顶点 的位置
elementtype top2(stack s);           //返回二号栈的顶点 的位置
void pop1(stack s);           //清空栈1的首位值
void pop2(stack s);           //清空栈2的首位元素
elementtype topandpop1(stack s);      //找到1号栈顶点并返回它的值
elementtype topandpop2(stack s);          //找到2号顶点并返回它的值



