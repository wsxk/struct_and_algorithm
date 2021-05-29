#include "t27.c"

//free the space
tree freetree(tree s)
{
    if(s!=NULL)
    {
        freetree(s->left);
        freetree(s->right);
        freetree(s);
    }
    return NULL;//free successfully return 0
}

//find data
tree find(tree s,element x)
{
    if(s==NULL)
        return NULL;
    else if(x<s->x)
        return find(s->left,x);
    else if(x>s->x)
        return find(s->right,x);
    else
        return s;
}

//find min
tree findmin(tree s)
{
    if(s==NULL)
        return NULL;
    while(s->left!=NULL)
        s=s->left;
    return s;
}

//find max
tree findmax(tree s)
{
    if(s==NULL)
        return NULL;
    while(s->right!=NULL)
        s=s->right;
    return s;
}

//insert the data
tree insert(tree s,element x)
{
    if(s==NULL)
    {
        s=(tree)malloc(sizeof(struct treenode));
        if(s==0)
            perror("out of space");
        else
        {
            s->left=NULL;
            s->right=NULL;
            s->x=x;
            return s;
        }
    }else
    {
        if(s->x<x)
            s->right=insert(s->right,x);
        else if(s->x>x)
        {
            s->left=insert(s->left,x);
        }
    }
    return s;
}

//delete data
tree delete(tree s,element x)
{
    if(s==NULL)
        perror("the data doesn't exist");
    else if(x<s->x)
    {
        s->left=delete(s->left,x);
    }else if(x>s->x)
    {
        s->right=delete(s->right,x);
    }else if(s->left&&s->right)
    {
        tree temp=findmin(s->right);
        s->x=temp->x;
        s->right=delete(s->right,s->x);
    }else
    {
        tree temp=s;
        if(s->left==NULL)
        {
            s=s->right;
            free(temp);
        }else if(s->right==NULL)
        {
            s=s->left;
            free(temp);
        }else
        {
            free(temp);
        }
    }
    return s;
}

//retrieve the data
void retrieve(tree s)
{
    if(s==NULL)
        return;
    else
    {
        printf("%d\n",s->x);
        retrieve(s->left);
        retrieve(s->right);
    }
    return ;
}