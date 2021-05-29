#include "t21.c"

int main()
{
    queue s;
    int a,b,c,d;
    
    b=11;
    s=makequeue(b);
    for(a=0;a<b;a++)
    {
        enqueue(a+3,s);
    }
    while(s->sum!=0)
    { 
        printf("%d ",popandout(s));
    }
    freequeue(s);
    printf("\n");
    
    system("pause");
    return 0;
}