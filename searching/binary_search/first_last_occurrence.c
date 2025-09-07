/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/
#include<stdio.h>
int first_occurrence(int n,int a[],int k){
    int start=0;
    int end=n;
    while(start<end){
        int mid=(start+end)/2;
        if(a[mid]<k){
            start= mid+1;
        }
        else{
            end=mid;
        }
    }
    if (start < n && a[start] == k) return start;
    return -1;
}
int last_occurrence(int n,int a[],int k){
    int start=0;
    int end=n;
    while(start<end){
        int mid=(start+end)/2;
        if(a[mid]>k){
            end= mid; 
        }
        else{
            start=mid+1;
        }
    }
    if (start-1 >= 0 && a[start-1] == k) return start-1;
    return -1;
}
int main(){
    printf("enter array size\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter elements of array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter target\n");
    int k;
    scanf("%d",&k);
    printf("Output: [%d,%d]",first_occurrence(n,a,k),last_occurrence(n,a,k));
}