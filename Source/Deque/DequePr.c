#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq){
	pdeq->head = NULL;
	pdeq->tail = NULL;
}
int DQIsEmpty(Deque * pdeq){
	if(pdeq->head == pdeq->tail){
		return TRUE;
	}
	return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->head;
	// 첫번째일때
	if(DQIsEmpty) {
		pdeq->tail = newNode;
	}else{
		pdeq->head->prev = newNode;
	}
	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = pdeq->tail;
	// 첫번째일때
	if(DQIsEmpty) {
		pdeq->head = newNode;
	}else{
		pdeq->tail->next = newNode;
	}	
	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq){
	if(DQIsEmpty){
		printf("Deque is Empty!");
		exit(-1);
	}
	Node * delNode = pdeq->head;
	Data delData = pdeq->head->data;
	pdeq->head - pdeq->head->next;
	free(delNode);
	if(pdeq->head==NULL){ // 삭제후 비었을때 (구현중 누락 코드)
		pdeq->tail = NULL;
	}else{
		pdeq->head->prev = NULL;
	}
	return delData;
}
Data DQRemoveLast(Deque * pdeq){
	if(DQIsEmpty){
		printf("Deque is Empty!");
		exit(-1);
	}
	Node * delNode = pdeq->tail;
	Data delData = pdeq->tail->data;
	pdeq->head - pdeq->tail->prev;
	free(delNode);
		if(pdeq->tail==NULL){ // 삭제후 비었을때 (구현중 누락 코드)
		pdeq->head = NULL;
	}else{
		pdeq->tail->next = NULL;
	}
	return delData;
}

Data DQGetFirst(Deque * pdeq){
	if(DQIsEmpty){
		printf("Deque is Empty!");
		exit(-1);
	}
	return pdeq->head;
}
Data DQGetLast(Deque * pdeq){
	if(DQIsEmpty){
		printf("Deque is Empty!");
		exit(-1);
	}
	return pdeq->tail;
}
