#include "betterstack1.c"

// 确认是否为空
int isempty1(stack s)
{
    return s->topofstack1==emptytos1;
}

int isempty2(stack s)
{
    return s->topofstack2==s->capacity;
}

//确认栈满了没有
int isfull(stack s)
{
    return s->topofstack1+1==s->topofstack2;
}

//创建新栈
stack createstack(int X)
{
    stack s;
    if(X<minstacksize)
    {
        perror("Stack is too small");
    }
    s=(stack)malloc(sizeof(struct Stack));
    if(s==NULL)
        perror("out of space");
    else
    {
        s->array=malloc(sizeof(elementtype)*X);
        if(s->array==NULL)
            perror("out of space");
        else
        {
            s->capacity=X;
            makeempty1(s);
            makeempty2(s);
        }   
    }
    return s;
}

//清空栈的内容
void disposestack(stack s)
{
    if(s!=NULL)
    {
        free(s->array);
        free(s);
    }
}

//清空1栈空间的内容
void makeempty1(stack s)
{
    s->topofstack1=-1;
}
//清空2栈空间的内容
void makeempty2(stack s)
{
    s->topofstack2=s->capacity;
}

//压入栈1
void push1(elementtype X,stack s)
{
    if(isfull(s))
        perror("out of space");
    else
    {
        s->array[++s->topofstack1]=X;
    }
}
//压入栈2
void push2(elementtype X,stack s)
{
    if(isfull(s))
        perror("out of space");
    else
    {
        s->array[--s->topofstack2]=X;
    }
}

//显示栈1的最新元素的位置
elementtype top1(stack s)
{
    if(isempty1(s))
         perror("empty stack");
    else
    {
        return s->array[s->topofstack1];
    }
}
//显示栈2的最新元素的位置
elementtype top2(stack s)
{
    if(isempty2(s))
        perror("empty stack");
    else
    {
        return s->array[s->topofstack2];
    }  
}

//清空栈1的一个值
void pop1(stack s)
{
    if(isempty1)
        perror("empty stack");
    s->topofstack1--;
}
//清空栈2的一个值
void pop2(stack s)
{
    if(isempty2)
        perror("empty stack");
    else
    {
        s->topofstack2++;
    }
}

//弹出并清空栈1的一个值
elementtype topandpop1(stack s)
{
    if(isempty1(s))
        perror("empty stack");
    else
    {
        return s->array[s->topofstack1--];
    }
}
//弹出并清空栈2的一个值
elementtype topandpop2(stack s)
{
    if(isempty2(s))
        perror("empty stack");
    else
    {
        return s->array[s->topofstack2++];
    }
    
}



