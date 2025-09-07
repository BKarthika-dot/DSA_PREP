/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1 */

#include<stdio.h>
int search(int n,int a[],int k){
    int start=0;
    int end=n;
    while(start<end){
        int mid=(start+end)/2;
        if(a[mid]<k){
            return mid+1;
        }
        else{
            end=mid; 
        }
    }
}
int main(){
    printf("enter size of array\n");
    int n;
    scanf("%d",&n);

    int a[n];
    printf("enter elements of array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter element to be searched\n");
    int k;
    scanf("%d",&k);

    printf("output: %d",search(n,a,k));
}
