#include "betterstack2.c"

int main()
{
    int a,b,c;
    stack s;

    scanf("%d",&a);
    s=createstack(a);
    for(b=0;b<a/2;b++)
    {
        push1(b,s);
    }
    for(b=a/2;b<a;b++)
    {
        push2(b,s);
    }
    while(!isempty1(s))
    {
        c=topandpop1(s);
        printf("%d ",c);
    }
    while(!isempty2(s))
    {
        c=topandpop2(s);
        printf("%d ",c);
    }
    disposestack(s);

    system("pause");
    return 0;
}
