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

// headì— ë”ë¯¸ë…¸ë“œë¥¼ ìƒì„±í•´ì¤Œ(ë°ì´í„° ë¹ˆ ê°’)
// í˜„ìž¬ ë°ì´í„°ì˜ ê°œìˆ˜ë„ 0ìœ¼ë¡œ ì´ˆê¸°í™” 
void ListInit(List * plist){
	plist->head = (*Node)malloc(sizeof(Node)); 
	plist->head->next = null;
	plist->comp = null;
	int numOfData = 0;
}

// headì— ì‹ ê·œë…¸ë“œë¥¼ ì¶”ê°€í•¨
// comp ê°€ nullì¸ ê²½ìš°, FInsert
// comp ê°€ return ì„ ëŒë ¤ì¤€ë‹¤ë©´ , SInsert ë¡œ ì¶”ê°€
void LInsert(List * plist, LData data){
	if(plist->comp==null)
		FInsert(plist,data);
	else
		SInsert(plist,data);	
}

void FInsert(List * plist, LData data){
	Node * newNode = (*Node)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next; // ë”ë¯¸ë…¸ë“œê°€ ê°€ë¦¬í‚¤ë˜ ë°ì´í„°ë¥¼ ê°€ë¦¬í‚¤ê²Œ í•œë‹¤.
	plist->head->next = newNode; // ë”ë¯¸ë…¸ë“œì˜ next ë¥¼ 
	(plist->numOfData)++; // ë°ì´í„° ì¦ê°€newNodeë¥¼ ê°€ë¦¬í‚¤ê²Œí•œë‹¤.
}

// head ¿¡ next°¡  null ÀÌ ¾Æ´Ñ°æ¿ì  FALSE
// before (»èÁ¦¿ëµµ) ¿¡´Â dummy ³ëµå¸¦ °¡¸®Å°µµ·Ï ÇÑ´Ù.
// head´Â ÇöÀç dummy ¸¦ °¡¸®Å°°í ÀÖÀ¸¹Ç·Î cur¸¦ next À§Ä¡·Î ÀÌµ¿½ÃÅ²´Ù. 
// cur¸¦ ¹ÝÈ¯ *pdata = plist->cur->data ÇÑ ÈÄ, TRUE ¹ÝÈ¯ 
 
int LFirst(List * plist, LData * pdata){
	if(plist->head->next == NULL){
		return FALSE;
	}
	plist->before = plist->head;
	plist->cur = plist->head->next;
		
		*padata = plist->cur->data;
	return TRUE;
	
}

// cur ±âÁØ cur ÀÇ next °¡ ÀÖ´ÂÁö¸¦ ÆÇº°ÇÑ´Ù.
// Á¸ÀçÇÏ´Â °æ¿ì TRUE ¹ÝÈ¯ ¹× pdata ¿¡ µ¥ÀÌÅÍ¸¦ ÀÔ·ÂÇØ¾ßÇÑ´Ù. 
// before ´Â ÇöÀç cur À§Ä¡·Î º¯°æÇÑ´Ù. 
// cur ´Â cur->next; ·Î ÀÌµ¿ ½ÃÅ²´Ù. 
// *pdata ¿¡ curÀÇ next °ªÀ» ¹ÝÈ¯ÇØ¾ßÇÑ´Ù. 
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
// cur ¸Þ¸ð¸®¸¦ ÇØÁ¦ Free 
// »èÁ¦ÇÒ µ¥ÀÌÅÍ ¹ÝÈ¯
// µ¥ÀÌÅÍ°³¼ö -1 
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

// êµ¬í˜„ ëª»í•¨ ã… 
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));
