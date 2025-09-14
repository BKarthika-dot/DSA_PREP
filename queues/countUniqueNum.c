#include<stdio.h>
#define max 100
int queue[max];
int front=-1;
int rear=-1;
int count=0;
int isEmpty(){
    return(front==-1&&rear==-1);
}
int isFull(){
    return rear==max-1;
}
void enqueue(int val){
    if(isEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=val;
}
int dequeue(){
    int x;
    if(isEmpty()){
        return -1;
    }
    else if(front==rear){
        x=queue[front];
        front=-1;
        rear=-1;
    }
    else{
        x=queue[front];
        front++;
    }
    return x;
}
int count_unique(){
    if(isEmpty()){
        return -1;
    }
    int n=rear-front+1;
    for(int i=0;i<n;i++){
        int duplicate=0;
        int curr=dequeue();
        for(int j=0;j<n-1;j++){
            int temp=dequeue();
            if(temp==curr){
                duplicate=1;
            }
            enqueue(temp);
        }
        if(duplicate==0){
            count++;
            enqueue(curr);
        }
    }
    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        enqueue(a[i]);
    }
    printf("%d",count_unique());
}