#include "binary_heap2.c"

int main()
{
    priorityqueue s=NULL;
    int a,b,c;

    scanf("%d",&a);
    s=create(a);
    for(b=0;b<a;b++)
    {
        scanf("%d",&c);
        insert(c,s);
    }
    show(s);
    deletemin(s);
    show(s);
    free(s);
    
    system("pause");
    return 0;
}