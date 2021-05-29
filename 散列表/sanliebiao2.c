#include "sanliebiao1.c"

hashtable createtable(int tablesize)//创建新散列
{
    hashtable s;
    if(tablesize<mintablesize)//如果散列表的大小太小，不给予散列
    {
        printf("the size is too small!\n");
        return NULL;
    }else
    {
        s=(hashtable)malloc(sizeof(struct hashtb1));
        if(s==NULL)
        {
            printf("out of space!\n");
            return NULL;
        }else
        {
            s->tablesize=tablesize;
            s->list=(position *)malloc(sizeof(position)*tablesize);
            if(s->list==NULL)
            {
                printf("the space is full!\n");
                return NULL;
            }else
            {
                
                int i=0;
                for(i=0;i<tablesize;i++)
                {
                    s->list[i]=(position)malloc(sizeof(struct listnode));
                    s->list[i]->next=NULL;
                }            //将下一个指针清0
                return s;
            }         
        }   
    }
}

int findpoint(element x,hashtable s)//找到插入点
{
    return x%s->tablesize;
}

void insert(element x,hashtable s)//插入元素
{
    int a=findpoint(x,s);
    position b=NULL;
    if(s==NULL)
    {
        printf("the hashtable dosen't exist\n");
    }else
    {
        b=(position)malloc(sizeof(struct listnode));
        if(b==NULL)
        {
            printf("the space is full\n");
        }else
        {
            b->next=s->list[a]->next;
            b->x=x;
        }
    }
    s->list[a]->next=b;
}

position find(element x,hashtable s)//找到目标
{
    int a=findpoint(x,s);
    position b=s->list[a]->next;

    while(b!=NULL&&b->x!=x)
        b=b->next;
    return b;
}

void delete(element x,hashtable s)//删除元素
{
    int a=findpoint(x,s);
    position b=s->list[a]->next;
    position before=s->list[a];

    while(b!=NULL&&b->x!=x)
    {
        b=b->next;
        before=b;
    }
    if(b!=NULL)
    {
        position c=b->next;
        before->next=c;
        free(b);
        b=NULL;
    }
}

//展示所有元素
void show(hashtable s)
{
    int i;
    for(i=0;i<s->tablesize;i++)
    {
        position p=s->list[i]->next;
        while(p!=NULL)
        {
            printf("%d ",p->x);
            p=p->next;
        }
    }
    printf("\n");
}

//释放内存
void release(hashtable s)
{
    int i=0;
    for(i=0;i<s->tablesize;i++)
        free(s->list[i]);
    free(s->list);
    free(s);
}