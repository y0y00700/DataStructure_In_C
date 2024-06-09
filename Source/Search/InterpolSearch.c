#include <stdio.h>
#include <stdlib.h>

// Binary Search Func Base;
int InterpolSearch(int[] arr, int left, int right, int target){
    int mid;
    // this escape paragraph error when target Number not exist 
    //if(left>right)
    //    return -1;
    // to Change (search range)
    if(arr[left]>target||arr[right]<target)
        return -1;
    // this exp change to 
    // mid = (left+right)/2;  
    // InterPol Search Exp
    mid = ((double)(target-arr[mid])/(arr[right]-arr[left])*(right-left))+left;
    if(target == arr[mid])
        return arr[mid];

    else if(target > arr[mid])
        return InterpolSearch(arr,mid+1,right);
    else 
        return InterpolSearch(arr,left,mid-1);
}

void main(void){
    
}