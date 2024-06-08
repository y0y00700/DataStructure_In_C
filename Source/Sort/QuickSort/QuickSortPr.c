#include <stdio.h>
#include <stdlib.h>



int Partition(int[] arr , int left,int right){
	int low = left+1;
	int high = right;
	int pivot = arr[left];
	while(left<=high){
		while (pivot>=arr[low]&&low<=right)
			low++;
		while (pivot<=arr[high]&&high>=(left+1))
			high--;
		Swap(arr,low,high);
	}	
	Swap(arr,left,high);
	return high;
}

void QuickSort(int[] arr,int left,int right){
	if(left<=right){
		int pv = Partition(left,right);
		QuickSort(arr,left,pv);
		QuickSort(arr,pv+1,right);
	}
}

void Swap (int[] arr,int a,int b){
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void main(void){
	//	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	int arr[3] = {3, 3, 3};

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
}