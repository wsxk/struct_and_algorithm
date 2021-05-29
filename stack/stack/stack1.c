#include <stdio.h>
#include <stdlib.h>

#define max 1001
char stack[max];//zhan
int record=0;

//caozuo
void push(char a);
char pop(void);

void push(char a)
{
    if(record==(max-1))
    {
        printf("the stack is full\n");
        return;
    }
    stack[record++]=a;
}
char pop(void)
{
    while(record!=1)
        printf("%c",stack[--record]);
}
