#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct Node{
    int data;
    struct Node* next;      //pointer the next node
}Node;

Node* createNode(int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void insertAtEnd(Node** head,int val){
    Node* newNode=createNode(val);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void deleteAtEnd(Node** head){
    if(*head==NULL){
        printf("empty list");
        return;
    }
    Node* temp=*head;
    while(temp->next->next!=NULL){    //finding the second last node      10->20->30->40->NULL    so while loop will run till 30
        temp=temp->next;
    }
    free(temp->next);                //freeing the last value      frees the memory allocated for the next value so we remove 40   now we have 10->20->30->
    temp->next=NULL;                   //now the link from 30 isnt pointing to any value so we set it to null
}
void print_list(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n,val;
    scanf("%d",&n);

    Node* head=NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&val);
        insertAtEnd(&head,val);
    }
    deleteAtEnd(&head);
    print_list(head);
}