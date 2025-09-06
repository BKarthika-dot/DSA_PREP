/*finding a given number in a sorted array using binary search*/
#include<stdio.h>
int sort(int a[],int n,int k){
    int start=0;
    int end=n-1;
    while(start<end){
        int mid=(start+end)/2;
        if(a[mid]==k){
            return mid;
        }
        else if(a[mid]<k){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
int main(){
    printf("enter array size:\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter number to be found\n");
    int k;
    scanf("%d",&k);
    if(sort(a,n,k)==-1){
        printf("%d was not in array",k);
    }
    else{
        printf("%d was found at the index %d",k,sort(a,n,k));
    }
}