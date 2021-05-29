#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//这是一个构建链表的程序

typedef char element;    //定义                
typedef struct listnode * list;

struct listnode
{
    element ele;
    float xishu;
    float mi;
    list next ;
};


int SetListnum(int num);
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
int compare(element i,element j);
void visit(list L);

void CreateList(list L);
void ShowList(list L);
list AddList(list l1,list l2,list l3);
list MinusList(list l1,list l2,list l3);

int main()
{
    list store[11];
    int current=0;
    int choice;    //用户指令
    int i,a,b,c;             //获取位置
    element e;

    while(1)
    {
        scanf("%d",&choice);
        switch (choice)
        {            
            case 0:
                break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            case 1:
                store[current]=InitList(store[current]);
                break;
            
            case 2:
                store[current]=DestroyList(store[current]);
                break;

            case 3:
                store[current] = ClearList(store[current]);
                break;
            
            case 4:
                printf("%d\n",IsEmpty(store[current]));
                break;
            
            case 5:
                printf("%d\n",ListLength(store[current]));
                break;
            
            case 6:
                scanf("%d",&i);
                e=GetItem(store[current],i,&e);
                break;
            
            case 7:
                scanf("%c",&e);
                while(e== ' '|| e == '\n')
                    scanf("%c",&e);
                LocateElem(store[current],e,compare);
                break;

            case 8:
                e = PriorElem(store[current],e,i);
                break;

            case 9:
                e = NextElem(store[current],e,i);
                break;

            case 10:
                scanf("%d",&i);
                scanf("%c",&e);
                while (e==' ' || e == '\n')
                    scanf("%c",&e);
                InsertList(store[current],i,e);
                break;

            case 11:
                scanf("%d",&i);
                DeleteList(store[current],i,&e);
                printf("%c\n",e);
                break;

            case 12:
                ListTraverse(store[current],visit);
                printf("\n");
                break;

            case 19:
                scanf("%d",&current);
                break;

            case 21:
                CreateList(store[current]);
                break;
            case 22:
                scanf("%d",&i);
                ShowList(store[i]);
                break;
            case 23:
                scanf("%d",&a);
                scanf("%d",&b);
                scanf("%d",&c);
                AddList(store[a],store[b],store[c]);
                break;
            case 24:
                scanf("%d",&a);
                scanf("%d",&b);
                scanf("%d",&c);
                MinusList(store[a],store[b],store[c]);
                break;                
            default:
                break;
        }
        if(choice == 0)
            break;
    }
    return 0;
}

int SetListnum(int num)
{
    return num;
}

list InitList(list L)   //初始化链表，用于构建一个空表
{
    L = (list)malloc(sizeof(struct listnode));
    if(L == NULL)
    {
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
        return NULL;
    }
    while(L->next!= NULL)
    {
        p = L->next;
        free(L);
        L = p;
    }
    free(L);
    return NULL;
}

list ClearList(list L) //清空链表，只留表头,成为空表
{
    if(L == NULL)
    {
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
    return p;
}

int IsEmpty(list L) //判断是否空链表
{
    if(L == NULL)
        return 1;
    if(L->next==NULL)
       return 1;
    else
        return 0;
}

int ListLength(list L)   //判断链表的长度
{
    if(L == NULL)
    {
        return 0;
    }
    int length  = 0;
    while(L->next != NULL)
    {
        length++;
        L = L->next;
    }
    return length;
}

element GetItem(list L,int i,element * e) //获取链表中第i个元素的值
{
    if(L == NULL)
    {
        printf("NoElem\n");
        return *e;
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
        printf("%c\n",L->ele);
        return L->ele;
    }else 
    {
        printf("NoElem\n");
        return *e;
    }
}

element LocateElem(list L,element e,int (*compare)(element i,element j)) //查找元素,符合要求则返回位置
{
    int i = 0;
    if(L ==NULL)
    {
        printf("NoElem\n");
        return e;
    }
    while(L->next != NULL)
    {
        i++;
        L = L->next;
        if(compare(L->ele,e)==1)
        {
            printf("%d\n",i);
            return i;
        }
    }
    printf("NoElem\n");
    return e;
}

element PriorElem(list L,element cur_e,element pre_e)//返回cur_e的前驱元素，用pre_e返回
{
    list pre;
    if(L ==NULL)
    {
        printf("NoElem\n");
        return cur_e;
    }
    L = L->next;
    if(L->next == NULL)
    {
        printf("NoElem\n");
        return cur_e;
    }
    if(L->ele==cur_e)
    {
        printf("NoElem\n");
        return cur_e;
    }
    while(L->next!=NULL)
    {
        pre = L;
        L = L->next;
        if(L->ele == cur_e)
        {
            pre_e = pre->ele;
            printf("%c\n",pre_e);
            return pre_e;
        }
    }
    printf("NoElem\n");
    return cur_e;
}

element NextElem(list L,element cur_e,element next_e)//返回cur_e的后继元素，放入next_e中
{
    list next;
    if(L ==NULL)
    {
        printf("NoElem\n");
        return cur_e;
    }
    L = L->next;
    while(L!=NULL)
    {
        if(L->ele == cur_e)
        {
            next = L->next;
            if(next == NULL)
            {
                printf("NoElem\n");
                return cur_e;
            }
            next_e = next->ele;
            printf("%c\n",next_e);
            return next_e;
        }
        L = L->next;
    }
    printf("NoElem\n");
    return 0;
}

void InsertList(list L,int i,element e)//在链表的第i个位置插入元素e
{
    int position = 0;
    list p=L;
    while(L!=NULL)
    {
        position++;
        if(L->next==NULL)
        {
            list a = (list)malloc(sizeof(struct listnode));
            a->ele = e;
            p = L->next;
            L->next = a;
            a->next = p;
            return ;            
        }
        if(position==i)
        {
            list a =(list)malloc(sizeof(struct listnode));
            a->ele = e;
            p = L->next;
            L->next = a;
            a->next = p;
            return ;
        }
        L = L->next;
    }   
}

void DeleteList(list L,int i,element *e)          //删除链表中的第i个元素
{
    int count = 0;
    list a,b;
    if(L ==NULL)
    {
        printf("NoElem\n");
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
                return;
            }
        }
    }else
    {
        printf("NoElem\n");
    }
    return;
}

void ListTraverse(list L,void (*visit)(list L))     //遍历表，对表中的每个元素使用visit函数
{
    if(L==NULL)
    {
        return;
    }
    if(ListLength(L)== 0)
    {
        return;
    }
    visit(L);
}

int compare(element i,element j)
{
    return (i == j);
}


void visit(list L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%c",L->ele);
        L=L->next;
    }
}

void CreateList(list L)
{
    int n,i=0;
    int flag = 0;
    float c,d;
    list p ;
    list mark = L;
    list next = mark;
    scanf("%d",&n);

    while(i<n)
    {
        scanf("%f",&c);
        scanf("%f",&d);
        next = L->next;
        while (next!=NULL)
        {
            if(next->mi==d)
            {
                next->xishu += c;
                flag = 1;
                break;
            }
            next = next->next;
        }
        if(flag == 1)
        {
            flag = 0;
        }else
        {
            p = L->next;
            mark = L;
            while((p!=NULL))
            {
                if(p->mi>d)
                {
                    mark = p;
                    p=p->next;
                }else
                {
                    break;
                }
            }
            mark->next=(list)malloc(sizeof(struct listnode));
            mark = mark->next;
            mark->mi = d;
            mark->xishu=c;
            mark->next=p; 
        }  
        i++;
    }
}


void ShowList(list L)
{
    int flag=1;
    int mark = 0;
    list p = L->next;
    L = L->next;
    if(L->xishu!= 0.0 && L->xishu != -0.0)
    {
        if(L->xishu!=1.0)
        {
            if(L->xishu!=-1.0)
                printf("%g",L->xishu);
            else
                printf("-");  
                     
        }
        if(L->mi==0.0)
            ;
        else
        {
            if(L->mi==1.0)
                printf("x");
            else
            {
                printf("x^%g",L->mi);
            }
        } 
        mark = 1;  
    }    
    L=L->next;
    while(L!=NULL)
    {
        if(L->xishu!= 0.0&&L->xishu!=-0.0)
        {
            if(L->xishu!=1.0)
            {
                if(L->xishu==-1.0)
                    printf("-");
                else
                {
                    if(L->xishu > 0.0)
                        if(mark==1)
                            printf("+");
                    printf("%g",L->xishu);                    
                }
            }else
            {
                if(mark==1)
                    printf("+");
            }
             
            if(L->mi==0.0)
                ;
            else
            {
                if(L->mi==1.0)
                    printf("x");
                else
                {
                    printf("x^%g",L->mi);
                }
            } 
            mark = 1;  
        }
        L=L->next;    
    }
    while(p!=NULL)
    {
        if(p->xishu !=0.0)
        {
            flag = 0;
            break;
        }
        p=p->next;
    }
    if(flag==1)
        printf("0");
    printf("\n");
}


list AddList(list l1,list l2,list l3)
{
    l1 =l1->next;
    l2 =l2->next;
    list L = l3;
    while(l1!=NULL && l2!=NULL)
    {
        l3->next = (list)malloc(sizeof(struct listnode));
        l3 = l3->next;
        l3->next = NULL;
        if(l1->mi>l2->mi)
        {
            l3->mi = l1->mi;
            l3->xishu = l1->xishu;
            l1= l1->next;
            continue;
        }else if (l1->mi==l2->mi)
        {
            l3->mi= l2->mi;
            l3->xishu = l1->xishu + l2->xishu;
            l1=l1->next;
            l2 = l2->next;
            continue;
        }else
        {
            l3->mi = l2->mi;
            l3->xishu = l2->xishu;
            l2 = l2->next;
            continue;
        }  
    }
    if(l1 == NULL)
    {
        while(l2!=NULL)
        {
            l3->next = (list)malloc(sizeof(struct listnode));
            l3 = l3->next;
            l3->next = NULL;
            l3->mi = l2->mi;
            l3->xishu = l2->xishu;
            l2 = l2->next;
        }
    }else
    {
        while(l1!=NULL)
        {
            l3->next = (list)malloc(sizeof(struct listnode));
            l3 = l3->next;
            l3->next = NULL;
            l3->mi = l1->mi;
            l3->xishu = l1->xishu;
            l1 = l1->next;
        }        
    }
    
    return L;
}

list MinusList(list l1,list l2,list l3)
{
    l1=l1->next;
    l2=l2->next;
    list L = l3;
    while (l1!=NULL && l2!=NULL)
    {
        l3->next = (list)malloc(sizeof(struct listnode));
        l3=l3->next;
        l3->next=NULL;
        if(l1->mi > l2->mi)
        {
            l3->mi = l1->mi;
            l3->xishu = l1->xishu;
            l1=l1->next;
            continue;
        }else if (l1->mi == l2->mi)
        {
            l3->mi = l1->mi ;
            l3->xishu = l1->xishu -l2->xishu;
            l1=l1->next;
            l2=l2->next;
            continue;
        }else
        {
            l3->mi = l2->mi;
            l3->xishu = -l2->xishu;
            l2=l2->next;
            continue;
        }
    }
    if(l1==NULL)
    {
        while (l2!=NULL)
        {
            l3->next = (list)malloc(sizeof(struct listnode));
            l3=l3->next;
            l3->next=NULL;
            l3->mi =l2->mi;
            l3->xishu = -l2->xishu;
            l2=l2->next;
        }
    }else
    {
        while (l1!=NULL)
        {
            l3->next = (list)malloc(sizeof(struct listnode));
            l3=l3->next;
            l3->next=NULL;
            l3->mi = l1->mi;
            l3->xishu = l1->xishu;
            l1=l1->next;
        }
    }
    return L; 
}