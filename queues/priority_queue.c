/*Coffee Shop has single coffee machine customers place order and barista prepares them one at a time.
VIP customers are allowed to have their orders prepares before others even if their orders are placed later*/

#include<stdio.h>
#include<string.h>

#define max 5
int isEmpty(int front,int rear){
    return front==-1&&rear==-1;
}
void enqueue(char name[100],int *front,int *rear,char queue[][100]){
    if(isEmpty(*front,*rear)){
        *front=*rear=0;
    }
    else{
        (*rear)++;
    }
    strcpy(queue[*rear],name);
}
void dequeue(int *front,int *rear,char queue[][100]){
    char name[100];
    if(isEmpty(*front,*rear)){
        return;
    }
    else{
        strcpy(name,queue[*front]);
        if(*front==*rear){
            *front=*rear=-1;
        }
        else{
            (*front)++;
        }
    }
    printf("%s ",name);
}
int main(){
    char customer[100];
    char isVIP[5];

    char reg_queue[max][100];
    char vip_queue[max][100];

    int reg_front=-1;
    int reg_rear=-1;
    int vip_front=-1;
    int vip_rear=-1;

    for(int i=0;i<max;i++){
        scanf("%s",customer);
        scanf("%s",isVIP);
        if(strcmp(isVIP,"yes")==0){
            enqueue(customer,&vip_front,&vip_rear,vip_queue);
        }
        else{
           enqueue(customer,&reg_front,&reg_rear,reg_queue); 
        }
    }
    while(!isEmpty(vip_front,vip_rear)){
       dequeue(&vip_front,&vip_rear,vip_queue); 
    }
    while(!isEmpty(reg_front,reg_rear)){
        dequeue(&reg_front,&reg_rear,reg_queue);
    }
}