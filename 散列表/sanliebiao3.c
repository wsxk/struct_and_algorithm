#include "sanliebiao2.c"

int main()
{
    hashtable s=createtable(9);
    int i=0,a,b;

    for(i=0;i<9;i++)
    {
        scanf("%d",&a);
        insert(a,s);
    }
    show(s);
    find(a,s);
    delete(a,s);
    show(s);
    release(s);

    system("pause");
    return 0;
}