# include <stdio.h>
# include "Stack.h"
void StackInit(Stack * pstack){
pstack->topIndex = NULL; // 틀림 -> -1 로 변경 필요 
};

int SIsEmpty(Stack * pstack){
if(pstack->topIndex == -1){
return TRUE;
}
return FALSE;
};

void SPush(Stack * pstack,Data data){
(pstack->topIndex)++;
pstack->stackArr[topIndex] = data;
return;
}

Data Spop(Stack *pstack){
if(SIsEmpty(pstack)){
return NULL; // 틀림 -> exit(-1); 
}
int tmpIdx = pstack->topIndex;
(pstack->topIndex)--;
return pstack->stackArr[tmpIdx];
};

Data SPeek(Stack * pstack){
if(SIsEmpty(pstack)){
return NULL; // 틀림 -> exit(-1); 
}
return pstack->stackArr[pstack->topIndex];
};