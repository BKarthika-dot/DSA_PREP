/*Generate Binary Numbers from 1 to N using a Queue

Input: N=5 → Output: 1, 10, 11, 100, 101

Trick: Start with "1" in queue, for each item dequeued, append 0 and 1 to the end and enqueue.*/
#include<stdio.h>
#include<string.h>

#define max 100
char queue[max][max];
int front=-1;
int rear=-1;
int isEmpty(){
    return (front==-1&&rear==-1);
}
void enqueue(char str[]){
    if(isEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear++;
    }
    strcpy(queue[rear], str);
}
char* dequeue(){
    if(isEmpty()){
        return NULL;
    }
    return queue[front++];
}
void generate(int n){
    enqueue("1");
    for(int i=0;i<n;i++){
        char *item=dequeue();

        printf("%s ",item);

        char temp[max];
        strcpy(temp,item);
        strcat(temp,"0");
        enqueue(temp);

        strcpy(temp,item);
        strcat(temp,"1");
        enqueue(temp);
    }
    
}
int main(){
    int n;
    scanf("%d",&n);
    generate(n);
}