//O(nlogn) time complexity

#include<stdio.h>
#include<math.h>
#include<limits.h>
//find maximum subarray that crosses midpoint
int maxCrossingSum(int arr[],int low,int mid,int high){
    int leftMax=INT_MIN;
    int rightMax=INT_MIN;
    int sum1=0;
    int sum2=0;

    for(int i=mid;i>=low;i--){
        sum1+=arr[i];
        if(sum1>leftMax) leftMax=sum1;
    }

    for(int i=mid+1;i<=high;i++){
        sum2+=arr[i];
        if(sum2>rightMax) rightMax=sum2;
    }

    return leftMax+rightMax;
}
int maxSum(int arr[],int low,int high){

    if(low==high) return arr[low];

    int mid=floor((low+high)/2);
    int leftSum=maxSum(arr,low,mid);
    int rightSum=maxSum(arr,mid+1,high);
    int crossSum=maxCrossingSum(arr,low,mid,high);

    int max1=(leftSum>rightSum)?leftSum:rightSum;
    return (max1>crossSum)?max1:crossSum;

}
int main(){
    int arr[]={2, 3, -8, 7, -1, 2, 3};
    int length=sizeof(arr)/sizeof(arr[0]);
    int ans=maxSum(arr,0,length-1);
    printf("%d",ans);
}