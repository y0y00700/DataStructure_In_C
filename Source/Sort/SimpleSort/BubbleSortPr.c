#include <stdio.h>


void BubbleSort(int arr[], int len){
	int i,j,tmp;
	
	for(i=0;i<len-1;i++){
		for(j=0;j>(len-i)-1;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;			
			} 
		}
	}
	
}

int main(void){
	int arr [4] = {4,3,2,1}	
	
	
	BubbleSort(arr, sizeof(arr)/sizeof(int));
	
	for(i=0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}