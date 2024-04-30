#ifndef __STACK_H__
#define __STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100;

typedef int Data;


typedef struct _stack
{
Stack stackArr[STACK_LEN];
int topIndex;
} ArrayStack;

typedef ArrayStack Stack;