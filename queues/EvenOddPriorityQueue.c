/*A C program implementing two separate queues—one for odd-indexed inputs (high priority) and one for even-indexed inputs (low priority).

The program uses a simple array-based FIFO queue with front and rear pointers to correctly serve items in the order they were inserted.*/


#include<stdio.h>
#define max 10
int oddQueue[max];   //high priority odd queue
int evenQueue[max]; //low priority even queue

void enqueue(int queue[],int val,int *front,int *rear){
    if(*front==-1 && *rear==-1){
        *front=*rear=0;
    }
    else{
        (*rear)++;
    }
    queue[*rear] = val;
}
int dequeue(int queue[],int *front,int *rear){
    if(*front==-1&&*rear==-1){
        return -1;
    }
    int num=queue[*front];
    if(*front==*rear){
        *front=*rear=-1;
    }
    else{
        (*front)++;
    }
    return num;
}

int main(){
    int oddFront=-1;
    int oddRear=-1;
    int evenFront=-1;
    int evenRear=-1;

    int val;
    for(int i=0;i<max;i++){
        scanf("%d",&val);
        if(i%2==0){
            enqueue(evenQueue,val,&evenFront,&evenRear);
        }
        else{
            enqueue(oddQueue,val,&oddFront,&oddRear);
        }
    }

    printf("Serving High Priority (Odd Entries):\n");
    while(oddFront!=-1 ){
        int num=dequeue(oddQueue,&oddFront,&oddRear);
        printf("%d ",num);
    }
    printf("\nCompleted High Priority Queue\n");


    printf("\nServing Low Priority (Even Entries):\n");
    while(evenFront!=-1 ){
        int num=dequeue(evenQueue,&evenFront,&evenRear);
        printf("%d ",num);
    }
    printf("\nCompleted Low Priority Queue\n");
}