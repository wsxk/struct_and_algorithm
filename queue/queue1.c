#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct queue * queue;
typedef struct stack * stack;

struct queue{    //element lianbiao
    element X;
    queue next;
};
struct stack{
    queue head;
    queue tail;
};

void enqueue(element X,stack s);
void outqueue(stack s);
int isempty(stack s);
stack makestack(void);
void makeempty(stack s);
element pop(stack s);
element outandpop(stack s);
