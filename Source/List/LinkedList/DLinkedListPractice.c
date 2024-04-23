#include <stdio.h>
#include "DLinkedList.h"

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

// head에 더미노드를 생성해줌(데이터 빈 값)
// 현재 데이터의 개수도 0으로 초기화 
void ListInit(List * plist){
	plist->head = (*Node)malloc(sizeof(Node)); 
	plist->head->next = null;
	plist->comp = null;
	int numOfData = 0;
}

// head에 신규노드를 추가함
// comp 가 null인 경우, FInsert
// comp 가 return 을 돌려준다면 , SInsert 로 추가
void LInsert(List * plist, LData data){
	if(plist->comp==null)
		FInsert(plist,data);
	else
		SInsert(plist,data);	
}

void FInsert(List * plist, LData data){
	Node * newNode = (*Node)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next; // 더미노드가 가리키던 데이터를 가리키게 한다.
	plist->head->next = newNode; // 더미노드의 next 를 
	(plist->numOfData)++; // 데이터 증가newNode를 가리키게한다.
}


int LFirst(List * plist, LData * pdata){
	
}
int LNext(List * plist, LData * pdata){
	
}

LData LRemove(List * plist){
	
}
int LCount(List * plist){
	
}

// 구현 못함 ㅠ
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));