#include "t17.c"

//确认是否为空
int isempty(stack s)
{
    return s->head==NULL;
}
//创造栈
stack makestack(void)
{
    stack s;
    s=(stack)malloc(sizeof(struct stack));
    if(s==0)
        perror("out of space");
    else
    {
        s->head=0;
        s->tail=0;
        return s;
    }
}
//入队
void enqueue(element X,stack s)
{
    if(s->head==0)
    {
        s->head=(queue)malloc(sizeof(struct queue));
        if(s==0)
            perror("the space is full");
        s->head->X=X;
        s->head->next=0;
        s->tail=s->head;
    }else
    {
        s->tail->next=(queue)malloc(sizeof(struct queue));
        if(s==0)
            perror("the space is full");
        s->tail->next->X=X;
        s->tail->next->next=0;
        s->tail=s->tail->next;
    }
}
//出队
void outqueue(stack s)
{
    queue c=s->head;

    s->head=s->head->next;
    free(c);
}
//清空栈
void makeempty(stack s)
{
    while(s->head)
    {
        queue c=s->head->next;
        free(s->head);
        s->head=c;
    }
    free(s);
}
//弹出
element pop(stack s)
{
    if(isempty(s))
        perror("the stack is empty");
    else
    {
        return s->head->X;
    }
}
//弹出并删除
element outandpop(stack s)
{
    if(isempty(s))
        perror("the stack is empty");
    else
    {
        queue c=s->head;
        element d=s->head->X;
        s->head=s->head->next;
        free(c);
        return d;
    }
}