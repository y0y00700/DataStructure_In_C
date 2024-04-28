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

void SInsert(List *plist,Ldata data){
	Node * newNode = (*Node)malloc(sizeof(Node));
	Node * pred = plist->head->next;
	newNode->data = data;
	// 새 노드가 들어갈 위치를 찾는다.	
	while(pred->next !=NULL && comp(data,pred->data)){
		pred = pred->next;
	}
	
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
}

// head �� next��  null �� �ƴѰ��  FALSE
// before (�����뵵) ���� dummy ��带 ����Ű���� �Ѵ�.
// head�� ���� dummy �� ����Ű�� �����Ƿ� cur�� next ��ġ�� �̵���Ų��. 
// cur�� ��ȯ *pdata = plist->cur->data �� ��, TRUE ��ȯ 
 
int LFirst(List * plist, LData * pdata){
	if(plist->head->next == NULL){
		return FALSE;
	}
	plist->before = plist->head;
	plist->cur = plist->head->next;
		
		*padata = plist->cur->data;
	return TRUE;
	
}

// cur ���� cur �� next �� �ִ����� �Ǻ��Ѵ�.
// �����ϴ� ��� TRUE ��ȯ �� pdata �� �����͸� �Է��ؾ��Ѵ�. 
// before �� ���� cur ��ġ�� �����Ѵ�. 
// cur �� cur->next; �� �̵� ��Ų��. 
// *pdata �� cur�� next ���� ��ȯ�ؾ��Ѵ�. 
int LNext(List * plist, LData * pdata){
	if(plist->cur->next == NULL){
		return FALSE;
	}	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	
	return TRUE;
}



//  before->next = cur->next;
//  cur =  cur->next; 
// cur �޸𸮸� ���� Free 
// ������ ������ ��ȯ
// �����Ͱ��� -1 
LData LRemove(List * plist){
//	List * tmp = plist->cur;
//	plist->before->next = plist->cur->next;
//	plist-> cur = plist->cur->next;
//	free(tmp);
	List * tmp = plist->cur;
	LData tdata = tmp->data;
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(tmp);
	(plist->numOfData)--;
	
	return tdata;
}


int LCount(List * plist){
	
}

// 구현 못함 ㅠ
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));
