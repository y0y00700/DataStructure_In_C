#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int Data;

typedef struct _node{
Data data;
struct _node * next;
}Node;

typedef struct _listStrack{
Node *head;
};

void SPush(Stack * pstack,Data data);

void StackInit(Stack * pstack);

int SIsEmpty(Stack * pstack);

Data Spop(Stack *pstack);

Data SPeek(Stack * pstack);

#endif