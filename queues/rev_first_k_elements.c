#include<stdio.h>
#define max 100
int queue[max];
int front=-1;
int rear=-1;
int isEmpty(){
    return (front==-1&&rear==-1);
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
    if(front==rear){
        x=queue[front];
        front=-1;
        rear=-1;
    }
    else if(isEmpty()){
        return -1;
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
void rev_k(){
    if(isEmpty()){
        return;
    }
    int val=dequeue();
    rev_k();
    enqueue(val);
}
int main(){
    printf("enter size\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter k value\n");
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        enqueue(a[i]);
    }
    rev_k();
    for(int i=k;i<n;i++){
        enqueue(a[i]);
    }
    display();
}