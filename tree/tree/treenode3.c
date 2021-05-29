#include "t28.c"

int main()
{
    tree s=0;
    int a,b;

    for(a=0;a<20;a++)
    {
        scanf("%d",&b);
        if(s==0)
            s=insert(s,b);
        else
        {
            insert(s,b);
        }
        
    }
    delete(s,5);
    retrieve(s);
    system("pause");
    return 0;
}