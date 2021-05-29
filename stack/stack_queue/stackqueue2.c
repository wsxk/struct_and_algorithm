#include "t20.c"

//是否为空队伍
int isempty(queue s)
{
    return s->sum==0;
}

//是否为满队伍
int isfull(queue s)
{
    return s->sum==s->capacity;
}

//造队列
queue makequeue(int X)
{
    queue s;

    s=(queue)malloc(sizeof(struct stack));
    if(s==0)
        perror("the space is not enough");
    else
    {
        if(X<minsize)
            perror("the size for queue is too small");
        s->line=(element *)malloc(sizeof(element)*X);
        if(s->line==0)
            perror("the space is not enough");
        else
        {
            s->capacity=X;
            s->front=first;
            s->sum=min;
            s->tail=min;
        }
    }
    return s;
}

//入队
void enqueue(element X,queue s)
{
    if(isfull(s))
        perror("the queue is full");
    else
    {
        if(s->front==first)
        {
            s->line[++s->front]=X;
            s->sum++;
            s->tail++;
        }
        else   
        {
            if(s->tail==s->capacity)
                s->tail=min;
            s->line[s->tail++]=X;
            s->sum++;
        }
    }
}

//出队
void outqueue(queue s)
{
    if(isempty(s))
        perror("the queue is empty!");
    else
    {
        s->sum--;
        if(s->front==s->capacity)
            s->front=min;
        s->front++;
    }
}

//清空队列
void makeempty(queue s)
{
    s->front=first;
    s->sum=min;
    s->tail=min;
}

//展示队首
element pop(queue s)
{
    if(isempty(s))
        perror("the empty is empty");
    else
    {
        return s->line[s->front];
    }
}

//出队
element popandout(queue s)
{
    if(isempty(s))
        perror("the queue is empty");
    else
    {
        element c=s->line[s->front];
        s->front++;
        s->sum--;
        if(s->front==s->capacity&&s->sum!=0)
            s->front=min;
        return c;
    }
}

//释放内存
void freequeue(queue s)
{
    if(s!=NULL)
    {
        if(s->line!=NULL)
        {
            free(s->line);
            free(s);
        }
    }else
    {
        perror("can't free empty fp!");
    }   
}