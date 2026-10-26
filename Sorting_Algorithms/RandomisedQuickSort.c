#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,high);
    return i+1;
}
int randomPartition(int arr[],int low,int high){
    int r=low+rand()%(high-low+1);
    swap(arr,r,high);
    return partition(arr,low,high);
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int p=randomPartition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
int main(){
    int arr[]={1,4,3,9,8,6,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    srand(time(NULL));
    quickSort(arr,0,n-1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}