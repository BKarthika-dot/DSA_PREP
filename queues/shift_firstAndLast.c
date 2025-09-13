/*array [1,2,3,4,5] should become [5,2,3,4,1]*/

#include<stdio.h>
#define size 25
int queue[size];
int front=-1;
int rear=-1;

int isEmpty(){
    return(front==-1&&rear==-1);
}
int isFull(){
    return rear==size-1;
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
void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}

void shift(){
    if(isEmpty()||front==rear){
        return;
    }
    int first=dequeue();
    int count=rear-front;   //front=1,rear=4 so count=3
    for(int i=0;i<count;i++){
        int temp=dequeue();
        enqueue(temp);
    }
    //now queue is 5 2 3 4
    enqueue(first);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        enqueue(a[i]);
    }
    
    shift();
    display();
}