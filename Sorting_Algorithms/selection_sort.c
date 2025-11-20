/*A simple C program that implements the Selection Sort algorithm to sort an array of 10 integers in ascending order.
Time Complexity: O(n²) • Space Complexity: O(1)*/

#include<stdio.h>
#define max 10
void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int minIdx=i;

        for(int j=i+1;j<n;j++){
            if(a[j]<a[minIdx]){
                minIdx=j;
            }
        }

        int temp=a[i];
        a[i]=a[minIdx];
        a[minIdx]=temp;
    }
}
int main(){
    int a[max];
    for(int i=0;i<max;i++){
        scanf("%d",&a[i]);
    }
    selection_sort(a,max);

    for(int i=0;i<max;i++){
        printf("%d ",a[i]);
    }
}