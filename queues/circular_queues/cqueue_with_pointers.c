#include<stdio.h>
#define max 5
int isEmpty(int front,int rear){
    return(front==-1&&rear==-1);
}
int isFull(int front,int rear){
    return front==(rear+1)%max;
}
void enqueue(int val,int *front,int *rear,int cque[]){
    if(isFull(*front,*rear)){
        return ;
    }
    else if(isEmpty(*front,*rear)){
        *front=0;
    }
    *rear=(*rear+1)%max;
    cque[*rear]=val;
    printf("Enqueued: %d\n",val);
}
int dequeue(int *front,int *rear,int cque[]){
    int x;
    if(isEmpty(*front,*rear)){
        return -1;
    }
    else if(*front==*rear){
        x=cque[*front];
        *rear=-1;
        *front=-1;
    }
    else{
        x=cque[*front];
        (*front)=(*front+1)%max;
    }
    printf("Dequeued: %d",x);
    return x;

}
void display(int front,int rear,int cque[]){
    printf("queue contents: ");
    int i=front;
    while(1){
        printf("%d ",cque[i]);
        if(i==rear)break;
        i=(i+1)%max;
    }
    printf("\n");
}
int main(){

    int front=-1;
    int rear=-1;

    int cque[max];
    
    int choice,val;
    while(1){
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&val);
            enqueue(val,&front,&rear,cque);
            break;
            case 2:
            dequeue(&front,&rear,cque);
            break;
            case 3:
            display(front,rear,cque);
            break;
            case 4:
            return 0;
            default:
            printf("invalid\n");
            break;
        }
    }
    return 0;
}