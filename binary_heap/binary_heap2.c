#include "binary_heap1.c"

priorityqueue create(int number)//创造堆
{
    priorityqueue s=NULL;
    if(number < minsize)
    {
        printf("sorry,the size is too small!\n");
    }else
    {
        s=(priorityqueue)malloc(sizeof(struct heapstruct));
        if(s==NULL)
        {
            printf("the space is full!\n");
        }else
        {
            s->elements=(element *)malloc(sizeof(element)*(number+1));
            if(s->elements==NULL)
                printf("the space is not enough\n");
            else
            {
                s->capacity=number;
                s->size=0;
            } 
        }
    }
    return s;
}

void destroy(priorityqueue s)//释放内存
{
    free(s->elements);
    free(s);
}

void makeempty(priorityqueue s)//情况堆
{
    s->size=0;
}

int isempty(priorityqueue s)//判断堆是否为空
{
    return s->size==0;
}

int isfull(priorityqueue s)//判断堆是否已满
{
    return s->size==s->capacity;
}

element findmin(priorityqueue s)//查找最小元素
{
    return s->elements[1];
}

void insert(element x,priorityqueue s)//插入
{
    int i;

    if(isfull(s))
    {
        printf("the priorityqueue is full!\n");
        return ;
    }
    for(i=++s->size;s->elements[i/2]>x;i/=2)
        s->elements[i]=s->elements[i/2];//上滤
    s->elements[i]=x;
    
}

void deletemin(priorityqueue s)//删除最小元素
{
    int i,child,a=s->elements[s->size];

    s->size--;
    if(isempty(s))
    {
        printf("the priorityqueue is empty!\n");
        return ;
    }
    for(i=1;2*i<=s->size;i=child)
    {
        child=2*i;
        if(child!=s->size&&s->elements[child+1]<s->elements[child])
            child++;
        if(s->elements[child]>a)
        {
            s->elements[i]=a;
            break;
        }
        s->elements[i]=s->elements[child];    
    }
}

void show(priorityqueue s)//展示所有元素
{
    int i;
    for(i=1;i<=s->size;i++)
    {
        printf("%d ",s->elements[i]);
    }
    printf("\n");
}