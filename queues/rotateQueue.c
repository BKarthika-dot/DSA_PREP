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
void rotate_k(int k){
    int n=rear-front+1;
    int count=k%n;   //left rotation by k;    for right rotation do count=n-count;
    for(int i=0;i<count;i++){
        int temp=dequeue();
        enqueue(temp);
    }
}
int main(){
    printf("enter size\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        enqueue(a[i]);   
    }
    printf("enter k value\n");
    int k;
    scanf("%d",&k);
    rotate_k(k);
    display();
}