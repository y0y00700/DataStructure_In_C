#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

//typedef struct _node
//{
//	Data data;
//	struct _node * next;
//} Node;
//
//typedef struct _lQueue
//{
//	Node * front;
//	Node * rear;
//} LQueue;


void QueueInit(Queue * pq){
	pq->front = 0;
	pq->rear = 0;
}
int QIsEmpty(Queue * pq){
	if(pq->front == pq->rear) return TRUE;
	
	return FALSE;
}

void Enqueue(Queue * pq, Data data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data; 
	// 예외처리 추가 구문 if 문 누락함..  
	if(QIsEmpty(pq)) {
		pq->front = newNode; // front 도 newNode 가리킴 
		pq->rear = newNode;  // rear newNode 가리킴 
	}else{
	pq-rear->next = newNode;
	pq-rear = newNode;
}	
}
Data Dequeue(Queue * pq){
	if(QIsEmpty(pq)) {
		printf("Queue is Empty!");
		exit(-1);
	}
	Node * delQue = (Node*)malloc(sizeof(Node));
	delQue = pq->front;
	Data delDt = delQue->data;
	pq->front = pq->front->next;
	free(delQue);
	return delDt;
}
Data QPeek(Queue * pq){
	if(QIsEmpty(pq)){
	 printf("Queue is Empty"); 
	 exit(-1);
	}
	return pq->front->data;
}
