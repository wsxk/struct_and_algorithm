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
    if(record!=0)
        return stack[--record];
    else
    {
        return 'c';
    }
    
}

char output[max];
int sum=0;
void push1(char a);
void pop1(void);

void pop1(void)
{
    int i;
    for(i=0;i<sum;i++)
        printf("%c ",output[i]);
}
void push1(char a)
{
    if(sum==max-1)
    {
        printf("the output is full!\n");
        return ;
    }else
        output[sum++]=a;
}

