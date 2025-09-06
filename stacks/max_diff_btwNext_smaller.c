/*Given an array of integers, the task is to find the maximum absolute difference between the nearest left and the right smaller element of every element in the array. 

Input: arr[] = [2, 1, 8]
Output: 1
Explanation: Left smaller  ls[] = [0, 0, 1], Right smaller rs[] = [1, 0, 0]
Maximum Diff of abs(ls[i] - rs[i]) = 1 

Input: arr[] = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: Left smaller  ls[] = [0, 2, 4, 4, 4, 7, 2], Right smaller  rs[] = [0, 3, 7, 3, 3, 3, 0]
Maximum Diff of abs(ls[i] - rs[i]) = 7 - 3 = 4 */

#include<stdio.h>
#define MAX 100
#include<math.h>
int top=-1;
int stack[MAX];

void push(int val){
    stack[++top]=val;
}
int pop(){
    return stack[top--];
}
int isEmpty(){
    return top==-1;
}
int peek(){
    return stack[top];
}
void find_diff(int a[],int n){
    int ns[n];//array for storing next smallest element
    for(int i=0;i<n;i++){
        ns[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!isEmpty()&&a[stack[top]]>a[i]){
            int j=pop();
            ns[j]=a[i];
        }
        push(i);
    }

    int bs[n];//array for storing the smallest element before the given element
    for(int i=0;i<n;i++){
        bs[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!isEmpty()&&a[stack[top]]<a[i]){
            int j=pop();
            bs[i]=a[j];
        }
        push(i);
    }
    int diff[n];
    for(int i=0;i<n;i++){
        diff[i]=abs(bs[i]-ns[i]);
    }
    int max=diff[0];
    for(int i=1;i<n;i++){
        if(max<diff[i]){
            max=diff[i];
        }
    }
    printf("required maximum difference btw the nearest left and right smallest elements is %d ",max);
}
 int main(){
    printf("enter array size:\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    find_diff(a,n);
 }