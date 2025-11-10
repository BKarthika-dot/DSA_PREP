/*

This program implements the Quick Sort algorithm using recursion.

It partitions the array around a pivot element, placing smaller elements to its left and larger elements to its right, and then recursively sorts both subarrays.
⏱ Time Complexity
Case	        Time Complexity	         Explanation
Best Case	    O(n log n)	             Pivot divides the array into two nearly equal halves in every step.
Average Case	O(n log n)	             On average, partitions are reasonably balanced.
Worst Case	    O(n²)	                 Happens when the pivot is always the smallest or largest element, leading to unbalanced partitions.*/

#include<stdio.h>
int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(arr[start]<=pivot && start<=ub){
            start++;
        }
        while(arr[end]>pivot && end>=lb){
            end--;
        }
        if(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    int temp1=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp1;

    return end;
}
void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lower_bound=0;
    int upper_bound=n-1;
    quicksort(arr,lower_bound,upper_bound);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}