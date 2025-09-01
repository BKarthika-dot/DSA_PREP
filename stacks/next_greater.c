/*Goal: For each element in an array, find the next element that is greater. Use a stack to hold
Example:
Input: [2, 1, 3] → Output: [3, 3, -1] */
#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
int isFull(){
    return top==MAX-1;
}
void push(int val){
    if(!isFull()){
        stack[++top]=val;
    }
}
int isEmpty(){
    return top==-1;
}
int peek(){
    return stack[top];
}
int pop(){
    if(!isEmpty()){
        return stack[top--];
    }
    return -1;
}
void greater(int a[],int n){
    int result[n];
    for(int i=0;i<n;i++){
        result[i]=-1;
    }
    
    for(int i=0;i<n;i++){
        while(!isEmpty()&&a[stack[top]]<=a[i]){
            int j=pop();
            result[j]=a[i];
        }
        push(i);
    }
    for(int i=0;i<n;i++){
        printf("%d ",result[i]);
    }
}
int main(){
    printf("enter size of array:\n");
    int n;
    scanf("%d",&n);
    printf("enter %d elements:\n",n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    greater(a,n);
}