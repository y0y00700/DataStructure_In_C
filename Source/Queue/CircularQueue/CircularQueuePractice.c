#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"


void QueueInit(Queue * pq){ // front , rear intializing
	pq->front = 0;
	pq->rear = 0;
	
}
int QIsEmpty(Queue * pq){
	if(pq->front == pq->rear) // f와 r의 위치가 동일한 경우 큐는 비어있는 상태
		return TRUE;
	else 
		return FALSE;
}

// help Function 
// 원형큐 기반으로, 만약 max-1 idx 위치인 경우 idx 를 초기화하며, 아닌 경우 다음 위치를 리턴
int NextPosIdx(int pos){
	if(pos == QUE_LEN-1)
		return 0;
	else 
		return pos+1;
}

void Enqueue(Queue * pq, Data data){
	if(NextPosIdx(pq->rear)==pq->front){// rear 의 다음 인덱스 위치가 front 와 같은 경우 종료 
		exit(-1);
	}	
	
	pq->rear = NextPosIdx(qp->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq){
	if(QIsEmpty){ // 비어있는 상태에선, 지울 데이터가 존재하지 않는다.
		exit(-1); 
	}
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
	
}
Data QPeek(Queue * pq){
	if(QIsEmpty){
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];
}
