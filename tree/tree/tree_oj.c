#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct B_Tree *  Tree;
typedef char element;
struct B_Tree
{
    element data;
    Tree Parent;
    Tree left;
    Tree right;
};

Tree InitBiTree(Tree b);//初始化二叉树
Tree DestroyBiTree(Tree b);//销毁二叉树
void CreateBiTree(Tree b,element * string); //创建二叉树
void ClearBiTree(Tree b);  //清空二叉树
int BiTreeEmpty(Tree b);   //判断空二叉树
int BiTreeDepth(Tree b);
element Root(Tree b);
element Value(Tree b,Tree e);
void Assign(Tree b,Tree e,element value);
Tree Parent(Tree b,Tree e);
Tree LeftChild(Tree b,Tree e);
Tree RightChild(Tree b,Tree e);
Tree LeftSibling(Tree b,Tree e);
Tree RightSibling(Tree b,Tree e);
void InsertChild(Tree b,Tree e,char LR,Tree c);
void DeleteChild(Tree b,Tree e,char LR);
void PreOrderTraverse(Tree b,void (*visit)(Tree c));
void InOrderTraverse(Tree b,void (*visit)(Tree c));
void PostOrderTraverse(Tree b,void (*visit)(Tree c));
void LevelOrderTraverse(Tree b,void (*visit)(Tree c));
void visit(Tree c);
Tree CreateHTree(element * string);
void HTreeCode(Tree b,element * string ,char * code);
void HTreeDecode(Tree b,char * code,element * string);
int StringCheck(Tree b,element * string);
int CodeCheck(Tree b,char * code);

Tree LookCha(Tree b,element cha);//找函数路径

int main()
{
    int choice,number,Tnum,count,i;
    char LR;
    int flag = 0;
    element cha;
    element string[100];
    char code[500];
    Tree a[11];
    Tree e[11];
    element value[11];
    while (1)
    {
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                flag = 1;
                break;
            case 1:
                a[number]=InitBiTree(a[number]);
                break;
            case 2:
                a[number]=DestroyBiTree(a[number]);
                break;
            case 3:
                count = 0;
                while((string[count]=getchar())=='\n')
                    continue;
                count++;
                while((string[count]=getchar())!='\n')
                    count++;
                string[count]='\0';
                CreateBiTree(a[number],string);
                CreateBiTree(NULL,string);
                break;
            case 4:
                ClearBiTree(a[number]->left);
                ClearBiTree(a[number]->right);
                a[number]->left=NULL;
                a[number]->right=NULL;
                break;
            case 5:
                printf("%d\n",BiTreeEmpty(a[number]));
                break;
            case 6:
                printf("%d\n",BiTreeDepth(a[number]));
                break;
            case 7:
                value[number]=Root(a[number]);
                e[number] = a[number];
                printf("%c\n",value[number]);
                break;
            case 8:
                value[number]=Value(a[number],e[number]);
                printf("%c\n",value[number]);
                break;
            case 9:
                scanf("%c",&value[number]);
                Assign(a[number],e[number],value[number]);
                break;
            case 10:
                e[number] = Parent(a[number],e[number]);
                break;
            case 11:
                e[number] = LeftChild(a[number],e[number]);
                break;
            case 12:
                e[number] = RightChild(a[number],e[number]);
                break;
            case 13:
                e[number] = LeftSibling(a[number],e[number]);
                break;
            case 14:
                e[number] = RightSibling(a[number],e[number]);
                break;
            case 15:
                scanf("%c",&LR);
                scanf("%d",&Tnum);
                InsertChild(a[number],e[number],LR,a[Tnum]);
                a[Tnum]=NULL;
                break;   
            case 16:
                scanf("%c",&LR);
                DeleteChild(a[number],e[number],LR);
                break;
            case 17:
                PreOrderTraverse(a[number],visit);
                printf("\n");
                break;
            case 18:
                InOrderTraverse(a[number],visit);
                printf("\n");
                break;
            case 19:
                PostOrderTraverse(a[number],visit);
                printf("\n");
                break;
            case 20:
                LevelOrderTraverse(a[number],visit);
                printf("\n");
                break;
            case 29:
                scanf("%d",&number);
                break;
            case 31:
                count = 0;
                while((string[count]=getchar())=='\n')
                    continue;
                count++;
                while((string[count]=getchar())!='\n')
                    count++;
                string[count]='\0';
                a[number]=CreateHTree(string);
                break;
            case 32:
                count = 0;
                while((cha=getchar())=='\n')
                    continue;
                string[count++]=cha;
                while((cha=getchar())!='\n')
                    string[count++]=cha;
                string[count]='\0';
                HTreeCode(a[number],string,code);
                printf("%s\n",code);
                
                break;   
            case 33:
                count = 0;
                while((cha=getchar())=='\n')
                    continue;
                code[count++]=cha;
                while ((cha=getchar())!='\n')
                    code[count++]=cha;
                HTreeDecode(a[number],code,string);
                printf("%s\n",string);
                break;
            case 34:
                count = 0;
                while((cha=getchar())=='\n')
                    continue;
                string[count++]=cha;
                while((cha=getchar())!='\n')
                    string[count++]=cha;
                string[count]='\0';
                printf("%d\n",StringCheck(a[number],string));
                break;              
            case 35:
                count = 0;
                while((cha=getchar())=='\n')
                    continue;
                code[count++]=cha;
                while((cha=getchar())!='\n')
                    code[count++]=cha;
                code[count]='\0';
                printf("%d\n",CodeCheck(a[number],code));
                break;
        }
        if(flag==1)
            break;
    }
    return 0;
}

Tree LookCha(Tree b,element cha)
{
    int count = BiTreeDepth(b);
    int i = 0,sum=1;
    for(i=0;i<count;i++)
        sum *= 2;
    Tree queue[sum];
    for(i=0;i<sum;i++)
        queue[i]=NULL;  

    i = 1;
    count = 0;
    queue[0]= b;
    while(count<sum&&queue[count]!=NULL)    
    {
        if(queue[count]->data==cha)
            return queue[count];
        if(queue[count]->left!=NULL)
            queue[i++]=queue[count]->left;
        if(queue[count]->right!=NULL)
            queue[i++]=queue[count]->right;
        count++;
    }
}

Tree InitBiTree(Tree b)
{
    b = (Tree)malloc(sizeof(struct B_Tree));
    b->left= NULL;
    b->right=NULL;
    b->Parent=NULL;
    b->data = '^';
    return b;
}

Tree DestroyBiTree(Tree b)
{
    if(b==NULL)
        return b;
    else
    {
        DestroyBiTree(b->left);
        DestroyBiTree(b->right);
        free(b);
    }   
    return NULL;
}

void CreateBiTree(Tree b,element * string)
{
    static int i = 0;
    if(b==NULL)
    {
        i=0;
        return;
    }
    if(string[i]=='\0')
        return;
    if(string[i]=='^')
    {
        b->data = string[i++];
        b->left = NULL;
        b->right = NULL;
        return ;
    }
    b->data = string[i++];

    b->left=(Tree)malloc(sizeof(struct B_Tree));
    (b->left)->Parent=b;
    CreateBiTree(b->left,string);

    b->right=(Tree)malloc(sizeof(struct B_Tree));
    (b->right)->Parent=b;
    CreateBiTree(b->right,string);
    return ;
}

void ClearBiTree(Tree b)
{
    ClearBiTree(b->left);
    ClearBiTree(b->right);
    free(b);
}

int BiTreeEmpty(Tree b)
{
    return b->data=='^';
}

int BiTreeDepth(Tree b)
{
    if(b==NULL)
        return 0;
    if(b->data=='^')
        return 0;
    int left = BiTreeDepth(b->left)+1;
    int right = BiTreeDepth(b->right)+1;
    return left>right? left:right;
}

element Root(Tree b)
{
    return b->data;
}

element Value(Tree b,Tree e)
{
    return e->data;
}

void Assign(Tree b,Tree e,element value)
{
    e->data =value;
}

Tree Parent(Tree b,Tree e)
{
    if(e->Parent==NULL)
    {
        printf("^\n");
        return NULL;
    }
    printf("%c\n",e->Parent->data);
    return e->Parent;
}

Tree LeftChild(Tree b,Tree e)
{
    if(e->left!=NULL)
    {
        if(e->left->data!='^')
        {
            printf("%c\n",e->left->data);
            return e->left;
        }
    }
    printf("^\n");
    return e;
}

Tree RightChild(Tree b,Tree e)
{
    if(e->right!=NULL)
    {
        if(e->right->data!='^')
        {
            printf("%c\n",e->right->data);
            return e->right;
        }
    }
    printf("^\n");
    return e;    
}

Tree LeftSibling(Tree b,Tree e)
{
    e=e->Parent;
    if(e->left!=NULL)
    {
        if(e->left->data!='^')
        {
            printf("%c\n",e->left->data);
            return e->left;
        }
    }
    printf("^\n");
    return e; 
}

Tree RightSibling(Tree b,Tree e)
{
    e=e->Parent;
    if(e->right!=NULL)
    {
        if(e->right->data!='^')
        {
            printf("%c\n",e->right->data);
            return e->right;
        }
    }
    printf("^\n");
    return e; 
}

void InsertChild(Tree b,Tree e,char LR,Tree c)
{
    if(LR == 'L')
    {
        c->right = e->left;
        e->left = c;
    }else if(LR== 'R')
    {
        c->right = e->right;
        e->right = c;
    }
}

void DeleteChild(Tree b,Tree e,char LR)
{
    if(LR == 'L')
    {
        b->left = DestroyBiTree(b->left);
    }else if(LR== 'R')
    {
        b->right = DestroyBiTree(b->right);
    }
}

void visit(Tree c)
{
    printf("%c",c->data);
}

void PreOrderTraverse(Tree b,void (*visit)(Tree c))
{
    if(b==NULL)
        return;
    if(b->data=='^')
    {
        return;
    }
    visit(b);
    PreOrderTraverse(b->left,visit);
    PreOrderTraverse(b->right,visit);
    return;    
}

void InOrderTraverse(Tree b,void (*visit)(Tree c))
{
    if(b==NULL)
        return;
    if(b->data=='^')
    {
        return;
    }
    InOrderTraverse(b->left,visit);
    visit(b);
    InOrderTraverse(b->right,visit);
    return;     
}

void PostOrderTraverse(Tree b,void (*visit)(Tree c))
{
    if(b==NULL)
        return;
    if(b->data=='^')
    {
        return;
    }
    PostOrderTraverse(b->left,visit);
    PostOrderTraverse(b->right,visit);
    visit(b);
    return;    
}

void LevelOrderTraverse(Tree b,void (*visit)(Tree c))
{
    int count = BiTreeDepth(b);
    int i = 0,sum=1;
    for(i=0;i<count;i++)
        sum *= 2;
    Tree queue[sum];
    for(i=0;i<sum;i++)
        queue[i]=NULL;

    i = 1;
    count = 0;
    queue[0]= b;
    while(count<sum&&queue[count]!=NULL)
    {
        if(queue[count]->data!='^')
        {
            visit(queue[count]);
            if(queue[count]->left!=NULL)
                queue[i++]=queue[count]->left;
            if(queue[count]->right!=NULL)
                queue[i++]=queue[count]->right;
        }
        count++;
    }
}

Tree CreateHTree(element * string)
{
    Tree H ;
    H = InitBiTree(H);
    CreateBiTree(H,string);
    return H;
}
void HTreeCode(Tree b,element * string ,char * code)
{
    int counti =strlen(string);
    int countc=0;
    int count;
    int i=0;
    int j;
    char current[15];
    Tree path,k;

    for(i = 0;i<counti;i++)
    {
        path = LookCha(b,string[i]);
        count = 0;
        while(path!=NULL&&path->Parent!=NULL)//根节点的父亲节点为空指针
        {
            k=path->Parent;
            if(k->left->data==path->data)
                current[count++]='0';
            else
                current[count++]='1';
            path = path->Parent;
        }
        current[count]='\0';
        for(count=count-1;count>=0;count--)
            code[countc++]=current[count];
    }
}

void HTreeDecode(Tree b,char * code,element * string)
{
    Tree c=b;
    int count = 0;
    int i=0;
    while(code[count]!='\0')
    {    
        while(c!=NULL)
        {
            if(code[count]=='0')
                c=c->left;
            else
                c=c->right;
            if(c->left->data=='^'&&c->right->data=='^')
            {
                string[i++]=c->data;
                break;
            }
            count++;
        }
        count++;
        c=b;
    }
    string[i]='\0';
}
int StringCheck(Tree b,element * string)
{
    char code[500];
    element re_string[100];
    HTreeCode(b,string,code);
    HTreeDecode(b,code,re_string);
    if(strcmp(string,re_string)==0)
        return 1;
    else 
        return 0;
}
int CodeCheck(Tree b,char * code)
{
    char re_code[500];
    element string[100];
    HTreeDecode(b,code,string);
    HTreeCode(b,string,re_code);
    if(strcmp(code,re_code)==0)
        return 1;
    else 
        return 0;
}
