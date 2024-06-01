#include <stdio.h>

void InsertionSortPr(int arr,int len){
	int i,j,tmp,insData;
	
	for(i=1;i<n;i++){
		insData = arr[i]; 
		for(j=i-1;j>=0;j--){
			if(arr[j]>insData){
				arr[j+1] = arr[j];
			}else	break; 
		}
		arr[j+1] = insData;
	}	
	
}
void main(void){
	int arr[4] = {4,2,3,1};
	InsertionSortPr(arr,sizeof(arr)/sizeof(int));
	
	for(int i=0;i<4;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}