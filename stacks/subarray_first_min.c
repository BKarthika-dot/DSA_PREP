/*Count of Subarrays whose first element is the minimum
Input: arr = {1, 2, 1}
Output: 5
Explanation: All subarray are: {1}, {1, 2}, {1, 2, 1}, {2}, {2, 1}, {1}
From above subarray the following meets the condition: {1}, {1, 2}, {1, 2, 1}, {2}, {1}


Input: arr[] = {1, 3, 5, 2}
Output: 8
Explanation: We have the following subarrays which meet the condition:
{1}, {1, 3}, {1, 3, 5}, {1, 3, 5, 2}, {3}, {3, 5}, {5}, {2}*/
#include<stdio.h>
#define MAX 100
int top=-1;
int stack[MAX];

void push(int a){
    stack[++top]=a;
}
int pop(){
    return stack[top--];
}
int isEmpty(){
    return top==-1;
}

void count_sub(int a[],int n){
    int next_smaller[n];
    for(int i=0;i<n;i++){
        next_smaller[i]=n;
    }
    
    for(int i=0;i<n;i++){
        while(!isEmpty()&&a[stack[top]]>a[i]){
            int j=pop();
            next_smaller[j]=i;
        }
        push(i);  
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(next_smaller[i]-i);
    }
    printf("count of required sub arrays is %d ",sum);
}
int main(){
    printf("enter array size\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    count_sub(a,n);
}