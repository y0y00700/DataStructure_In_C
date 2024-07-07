#include <stdio.h>
#include "CircularQueue.h"

void BFShowGraphVertex(ALGraph * pg, int startV){
	Queue queue;
	int visitV = startV;
	int nextV;
	QueueInit(&queue);
	VisitVertex(pg,visitV);
	while(LFirst(&(pg->adjList[visitV]),&nextV)==TRUE)){
		if(VisitVertex(pg,nextV)==TRUE)
			Enqueue(&queue,&nextV);
			
		while(LNext(&(pg->adjList[visitV]),&nextV)==TRUE){
			if(VisitVertex(pg,nextV)==TRUE)
				Enqueue(&queue,&nextV);
		}
		
		if(QIsEmpty(&queue) == TRUE)
			break;
		else
			visitV = Dequeue(&queue);
			
		memset(pg->visitInfo,0,sizeof(int) * pg->numV);
	}
\
}