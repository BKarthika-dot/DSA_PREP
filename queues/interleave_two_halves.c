/*Interleave the First Half and Second Half of a Queue

Queue: 1 2 3 4 5 6 → Output: 1 4 2 5 3 6.

Needs you to split and merge carefully.*/
#include<stdio.h>
#define max 100

int isEmpty(int front,int rear){
    return(front==-1&&rear==-1);
}
void enqueue(int val,int *front,int *rear,int queue[]){
    if(isEmpty(*front,*rear)){
        *front=0;
        *rear=0;
    }
    else{
        (*rear)++;
    }
    queue[*rear]=val;
}
int dequeue(int *front,int *rear,int queue[]){
    int x;
    if(isEmpty(*front,*rear)){
        return -1;
    }
    else if(*front==*rear){
        x=queue[*front];
        *front=-1;
        *rear=-1;
    }
    else{
        x=queue[*front];
        (*front)++;
    }
    return x;
}
void display(int front,int rear,int queue[]){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
void interleave(int *front,int *rear,int *fh,int *rh,int queue[],int q_half[]){      //initially queue is 1 2 3 4 5 6 
    int n=*rear-*front+1;      
    for(int i=0;i<n/2;i++){
        int num=dequeue(front,rear,queue);      //queue 1: 4 5 6     
        enqueue(num,fh,rh,q_half);              //queue 2: 1 2 3
    }
    for(int i=0;i<n/2;i++){
        int num=dequeue(fh,rh,q_half);    //dequeue 1; enqueue(1);
        enqueue(num,front,rear,queue);
        int num1=dequeue(front,rear,queue);   //dequeue 4; enqueue(4)
        enqueue(num1,front,rear,queue);
    }
}
int main(){
    printf("enter size\n");
    int n;
    scanf("%d",&n);
    printf("enter elements\n");
    int a[n];

    int front=-1;
    int rear=-1;

    int fh=-1;
    int rh=-1;

    int queue[max];
    int q_half[max/2];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        enqueue(a[i],&front,&rear,queue);
    }
    interleave(&front,&rear,&fh,&rh,queue,q_half);
    printf("interleaved queue:\n");
    display(front,rear,queue);
}