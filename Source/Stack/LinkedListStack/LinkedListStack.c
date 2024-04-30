#include <stdio.h>
#include "LinkedListStack.h"

void SPush(Stack * pstack,Data data){
Node * newNode =(*Node)malloc(sizeof(Node));

newNode->data = data;
newNode->next = pstack->head;
pstack->head = newNode;
}

void StackInit(Stack * pstack){
pstack->head = null;
}

int SIsEmpty(Stack * pstack){
if(pstack->head = NULL){
return TRUE;
}
return FALSE;
}

Data Spop(Stack * pstack){
if(SIsEmpty){
exit(-1);
}
Data sData = pstack->head->data;
Node * sNode = pstack->head;
pstack->head = pstack->head->next;
free(sNode);
return sData;

}

Data SPeek(Stack * pstack){
if(SIsEmpty){
exit(-1);
}
return pstack->head;
}