#include <stdio.h>
#include <stdlib.h>

void MergeSort(int[] arr,int left,int right){
	if(left<right){
		int mid = (left+right)/2;
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);
		MergeTwoArea(arr,left,mid,right);
	}
}

void MergeTwoArea(int[] arr,int left,int mid,int right){
	int i;
	int rIdx = mid+1;
	int lIdx = left;
	int mIdx = left;
	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	
	while(lIdx<=mid&&rIdx<=right){
		if(arr[lIdx]>arr[rIdx]) sortArr[mIdx] = arr[lIdx++];
		else sortArr[mIdx] = arr[rIdx++];
		mIdx+=1;
	}
	if(lIdx<=mid){
		for(i=lIdx;i<=mid;i++,mIdx++)
			sortArr[mIdx] = arr[i];
	}else{
		for(i=rIdx;i<=right;i++,mIdx++){
			sortArr[rIdx] = arr[i];
		}
	}
	
	for(i=left;i<(right+1);i++)
		arr[i] = sortArr[i];
		
	free(sortArr);
}


int main(void)
{
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	int i;

	// 배열 arr의 전체 영역 정렬 
	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}