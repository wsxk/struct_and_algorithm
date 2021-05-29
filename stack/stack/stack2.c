#include "t8.c"

int main()
{
    char a;

    while((a=getchar())!=EOF)
        push(a);
    while((a=pop())!=EOF)
        printf("%c",a);
        
    system("pause");
    return 0;
}