#include "list1.c"

list InitList(list L)   //初始化链表，用于构建一个空表
{
    if(L != NULL)
    {
        printf("\nError,The list has exist!\n");
        return NULL;
    }
    L = (list)malloc(sizeof(struct listnode));
    if(L == NULL)
    {
        printf("\nError,the space is full!\n");
        return NULL;
    }
    L->next = NULL;
    return L;
}     

list DestroyList(list L) //摧毁链表，使之成为空指针
{
    list p=L;
    if(L == NULL)
    {
        printf("\nError,the list doesn't have anything!\n");
        return NULL;
    }
    while(L->next!= NULL)
    {
        p = L->next;
        free(L);
        L = p;
    }
    free(L);
    printf("\nDestroy successfully!\n");
    return NULL;
}

list ClearList(list L) //清空链表，只留表头,成为空表
{
    if(L == NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return NULL;
    }
    list p = L;
    list j ;

    L = L->next;
    while(L!= NULL)
    {
        j = L->next;
        free(L);
        L = j;
    }
    p->next = NULL;
    printf("\nClear successfully!\n\n");
    return p;
}

int IsEmpty(list L) //判断是否空链表
{
    if(L == NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return 0;
    }
    if(L->next==NULL)
        printf("\nThe list is empty!\n");
    else
    {
        printf("\nThe list is not empty!\n");
    }
    return 0;
}

int ListLength(list L)   //判断链表的长度
{
    if(L == NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return 0;
    }
    int length  = 0;
    while(L->next != NULL)
    {
        length++;
        L = L->next;
    }
    printf("\nThe list's length is %d\n",length);
    return length;
}

element GetItem(list L,int i,element * e) //获取链表中第i个元素的值
{
    if(L == NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return 0;
    }
    int length = ListLength(L);
    if(1<=i<=length)
    {
        int count = 0;
        while(count != i)
        {
            L = L->next;
            count++;
        }
    }else
    {
        printf("\nError,out of range!\n");
        return 0;
    }
    printf("\nThe element is %d!\n",L->ele);
    return 0;
}

element LocateElem(list L,element e,int (*compare)(element i,element j)) //查找元素,符合要求则返回位置
{
    int i = 0;
    if(L ==NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return 0;
    }
    while(L->next != NULL)
    {
        i++;
        L = L->next;
        if(compare(L->ele,e)==1)
        {
            printf("\n The element position is %d\n",i);
            return i;
        }
            
    }
    printf("\nThe list doesn't have the element accroded with \n");
    return 0;
}
    

element PriorElem(list L,element cur_e,element pre_e)//返回cur_e的前驱元素，用pre_e返回
{
    list pre;
    if(L ==NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return 0;
    }
    L = L->next;
    if(L->next == NULL)
    {
        printf("\nError,the list doesn't have any element\n");
        return 0;
    }
    if(L->ele==cur_e)
    {
        printf("\nError,the cur_e is the first element!\n");
        return 0;
    }
    while(L->next!=NULL)
    {
        pre = L;
        L = L->next;
        if(L->ele == cur_e)
        {
            pre_e = pre->ele;
            printf("\nThe pre element is %d\n",pre_e);
            return pre_e;
        }
    }
    printf("\nthe ele doesn't exist!\n");
    return 0;
}

element NextElem(list L,element cur_e,element next_e)//返回cur_e的后继元素，放入next_e中
{
    list next;
    if(L ==NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return 0;
    }
    L = L->next;
    while(L!=NULL)
    {
        if(L->ele == cur_e)
        {
            next = L->next;
            if(next == NULL)
            {
                printf("\nError,the element is the last element!\n");
                continue;
            }
            next_e = next->ele;
            printf("\nThe next element is %d\n",next_e);
            return next_e;
        }
        L = L->next;
    }
    printf("\nthe element dosen't exist in the list!\n");
    return 0;
}

void InsertList(list L,int i,element e)//在链表的第i个位置插入元素e
{
    int position = 0;
    list p;
    if(L == NULL)
    {
        printf("\nError! the list doesn't exist!\n");
        return;
    }
    if(1<=i<=ListLength(L))
    {
        p = L;
        L = L->next;
        while(L!=NULL)
        {
            position++;
            if(position==i)
            {
                list a =(list)malloc(sizeof(struct listnode));
                a->next = L;
                p->next = a;
                printf("\ninsert successfully!\n");
                break;
            }
            p = L;
            L = L->next;
        }
    }else
    {
        printf("\nError,out of range!\n");
    }
}

void DeleteList(list L,int i,element *e)          //删除链表中的第i个元素
{
    int count = 0;
    list a,b;
    if(L ==NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return;
    }
    if(1<=i<=ListLength(L))
    {
        while(L->next!=NULL)
        {
            count++;
            a = L;
            L = L->next;
            if(count == i)
            {
                b = L;
                L = L->next;
                a->next = L;
                *e = b->ele;
                free(b);
                printf("\ndelete successfully!\n");
                printf("\nThe deleted element is %d\n",*e);
                return;
            }
        }
    }else
    {
        printf("\nError!,out of range!\n");
    }
    return;
}

void ListTraverse(list L,void (*visit)(list L))     //遍历表，对表中的每个元素使用visit函数
{
    if(L==NULL)
    {
        printf("\nError,the list doesn't exist!\n");
        return;
    }
    if(ListLength(L)== 0)
    {
        return;
    }
    visit(L);
}