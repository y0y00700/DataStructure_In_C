#include <stdio.h>

void TowerOfHanoi(int tray,char start,char by ,char dest){
	if(tray==1){
		printf("Move %c To %c \n",start,dest);
	}else{
		TowerOfHanoi(tray-1,start,dest,by);
		printf("Move %c To %c \n",start,dest);
		TowerOfHanoi(tray-1,by,start,dest);
	}
}

int main(void){

	int tray;
	printf("Input tray quantity: ");
	scanf("%d",&tray);
	TowerOfHanoi(tray,'A','B','C');
	
	return 0;
}