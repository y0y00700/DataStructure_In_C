#include "SimpleHeap.h"

/** Help Function **/
int HIsEmpty(Heap * ph){
	if(ph->numOfData == 0) return TRUE;
	else return FALSE;
	
}
int GetParentIdx(int idx){
	return idx/2;
}

int GetLChildIdx(int idx){
	return idx*2;
}

int GetRChildIdx(int idx){
	return GetLChildIdx(idx)+1;
}

/* 
	if not have child : return 0;
	have a child : return high priority child node
*/
int GetHiPriChildIdx(Heap * ph, int idx){
	// 현재 힙의 데이터 개수보다 반환받은 자식 노드의 크기가 큰경우 자식 노드가 없는것
	if(GetLChildIdx(idx)>ph->numOfData) return 0;
	else if (GetLChildIdx(idx) == ph->numOfData) return GetLChildIdx(idx); // 동일한 경우엔 왼쪽 자식만 존재하므로 바로 반환
	else{ // else both child node Exist
		if(ph.heapArr[GetLChildIdx(idx)].pr > ph.heapArr[GetRChildIdx(idx)].pr){
			return GetRChildIdx(idx);
		}else{
			return GetLChildIdx(idx)
		}
	}
}

/*** Heap Operation ****/
void HeapInit(Heap * ph){
	ph->numOfData = 0;
}
// Heap Insert Operation
void HInsert(Heap * ph, HData data, Priority pr){
	int idx = ph->numOfData;
	HeapElem nElem = {pr,data};
	
	// find proper idx
	while(idx != 1){
		
		if(pr<(ph->heapArr[GetParentIdx(idx)].pr)){
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			
			idx = GetParentIdx(idx);
		}else break;
	}
	
	ph->heapArr[idx] = nElem;
	ph->numOfData += 1;
}

// Heap Delete Operation
HData HDelete(Heap * ph){
	HData rData = (ph.heapArr[1]).data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];
	
	int parentIdx = 1; 
	int childIdx;
	
	// find proper idx
	while(childIdx = GetHiPriChildIdx(ph,parentIdx)){
		
		if(lastElem.pr <= ph->heapArr[childIdx].pr) break;
		
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;	
	}
	ph->heapArr[parentIdx] = lastElem;
		
	return rData;
}