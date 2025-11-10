// Counting Sort Algorithm
// This program implements the Counting Sort algorithm — a non-comparison-based sorting technique
// that counts the occurrences of each element and uses prefix sums to determine the final positions.
// It is efficient for sorting integers when the range of input values (k) is not significantly larger than n.
//
// Time Complexity:
// - Best Case: O(n + k)
// - Average Case: O(n + k)
// - Worst Case: O(n + k)
// Space Complexity: O(n + k)


#include<stdio.h>
void sort(int a[],int n){
    int max=a[0];  //finding maximum array element
    for(int i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    int count[max+1]; //initialize array with size as (max array element)+1;

    for(int i=0;i<max+1;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=1;i<max+1;i++){
        count[i]=count[i]+count[i-1];
    }
    int result[n];
    for(int i=n-1;i>=0;i--){
        int pos=count[a[i]]-1;
        result[pos]=a[i];
        count[a[i]]--;
    }
    for(int i=n-1;i>=0;i--){
        printf("%d ",result[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
}