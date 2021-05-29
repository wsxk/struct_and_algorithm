#include "t18.c"

int main()
{
    stack s;
    int a,b,c;

    s=makestack();
    for(a=0;a<10;a++)
        enqueue(a,s);
    while(!isempty(s))
    {
        printf("%d",outandpop(s));
    }
    makeempty(s);
    system("pause");
    return 0;
}