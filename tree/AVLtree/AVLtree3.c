#include "AVLtree2.c"

int main()
{
    AVLtree head=NULL;
    AVLtree temp=NULL;
    int a,b;

    for(a=0;a<15;a++)
    {
        scanf("%d",&b);
        head=insert(b,head);
    }
    show(head);
    temp=find(6,head);
    printf("%d\n",temp->x);
    head=delete(7,head);
    show(head);
    
    head=makeempty(head);
    system("pause");
    return 0;
}