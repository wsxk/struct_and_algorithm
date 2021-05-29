#include "AVLtree.c"

//makeempty the avltree
AVLtree makeempty(AVLtree T)
{
    if(T!=NULL)
    {
        makeempty(T->left);
        makeempty(T->right);
        free(T);
    }

    return NULL;
}
//find 
position find(element x,AVLtree T)
{
    if(T==NULL)
    {
        printf("Not find the element!\n");
        return NULL;
    }else if(T->x==x)
        return T;
    else if(T->x<x)
        return find(x,T->right);
    else
        return find(x,T->left);
}

//find min
position findmin(AVLtree T)
{
    if(T==NULL)
    {
        printf("the tree is empty!\n");
        return NULL;
    }else
    {
        while(T->left!=NULL)
            T=T->left;
        return T;
    }
}

//find max
position findmax(AVLtree T)
{
    if(T==NULL)
    {
        printf("the tree is empty\n");
        return NULL;
    }else
    {
        while(T->right!=NULL)
            T=T->right;
        return T;
    }
}

//zhongdian INsert
position insert(element x,AVLtree T)
{
    if(T==NULL)
    {
        T=(AVLtree)malloc(sizeof(struct AVLnode));
        if(T==NULL)
        {
            printf("out of space!\n");
            return NULL;
        }else
        {
            T->x=x;
            T->left=T->right=NULL;
            T->height=0;
        }
    }else if(x>T->x)
    {
        T->right=insert(x,T->right);
        if(height(T->right)-height(T->left)==2)
        {
            if(T->right->x<x)
                T=singright(T);
            else
                T=doubleright(T);
        }
    }else if(x<T->x)
    {
        T->left=insert(x,T->left);
        if(height(T->left)-height(T->right)==2)
        {
            if(T->left->x>x)
            {
                T=singleft(T);
            }else 
            {
                T=doubleleft(T);
            }
        }
    }
    T->height=max(height(T->left),height(T->right))+1;
    return T;
}

int max(int x,int y)//find the max
{
    if(x>y)
        return x;
    else
    {
        return y;
    }
}

int height(AVLtree T)//define the height
{
    if(T==NULL)
        return -1;
    else
    {
        return T->height;
    }
}

position singleft(AVLtree T)
{
    position temp=T->left;
    T->left=temp->right;
    temp->right=T;
    T->height=max(height(T->left),height(T->right))+1;
    temp->height=max(height(temp->left),height(temp->right))+1;

    return temp;
}
position singright(AVLtree T)
{
    position tmep=T->right;
    T->right=tmep->left;
    tmep->left=T;
    T->height=max(height(T->left),height(T->right))+1;
    tmep->height=max(height(tmep->left),height(tmep->right))+1;

    return tmep;
}
position doubleleft(AVLtree T)
{
    T->left=singright(T->left);
    return singleft(T);
}

position doubleright(AVLtree T)
{
    T->right=singleft(T->right);
    return singright(T);
}

//delete
AVLtree delete(element x,AVLtree T)
{
    position temp=NULL;
    if(T==NULL)
    {
        printf("the element doesn't exist \n");
        return NULL;
    }else if(x<T->x)
    {
        T->left=delete(x,T->left);
        
    }else if(x>T->x)
    {
        T->right=delete(x,T->right);
    }else
    {
        if(T->left&&T->right)
        {
            temp=findmin(T->right);
            T->x=temp->x;
            T->right=delete(temp->x,T->right);
        }else if(T->left==NULL&&T->right!=NULL)
        {
            temp=T;
            T=T->right;
            free(temp);
        }else if(T->right==NULL&&T->left!=NULL)
        {
            temp=T;
            T=T->left;
            free(temp);
        }else
        {
            free(T);
            T=0;
        }
    }
    if(T!=0)
        T->height=max(height(T->left),height(T->right))+1;
    return T;
}

void show(AVLtree t)
{
    if(t!=NULL)
    {
        show(t->left);
        show(t->right);
        printf("%d\n",t->x);
    }
    return ;
}