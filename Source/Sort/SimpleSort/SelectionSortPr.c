#include <stdio.h>

void SelectionSort(int arr[],int len){
	int i,j,maxIdx,tmp;
	
	for(i=0;i<len-1;i++){
		maxIdx = i;
		for(int j=i+1;j<len;j++){
			if(arr[j]<arr[maxIdx]){
				maxIdx = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = tmp;
	}
}

void main(void){
	int arr[4] = {3,4,1,2}
	
	SelectionSort(arr,sizeof(arr)/sizeof(int));
	
	for(int i=0; i<4;i++){
		printf(arr[i]);
	}
	printf("\n");
	
}