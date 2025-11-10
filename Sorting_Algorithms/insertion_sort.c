#include<stdio.h>
/*Insertion Sort is a simple, comparison-based sorting algorithm.

It builds the sorted array one element at a time by picking the next element and inserting it at the correct position in the already sorted part of the array.

Best Case: O(n) — when the array is already sorted

Average Case: O(n²)

Worst Case: O(n²) — when the array is sorted in reverse order

Space Complexity: O(1) — sorts in place*/

void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;

        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    insertionsort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}