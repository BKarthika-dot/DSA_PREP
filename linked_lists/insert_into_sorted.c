/*ask:

You are given a sorted singly linked list in ascending order.

You are given a new integer value.

Insert the new value in the correct position so that the list remains sorted.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* createNode(int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
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
void print_list(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void insertNew(Node** head,int val){
    Node* temp=*head;
    Node* newNode=createNode(val);
    if(*head==NULL||val<(*head)->data){
        newNode->next=*head;
        *head=newNode;
        return;
    }
    while(temp->next!=NULL && temp->next->data <= newNode->data){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
int main(){
    int a []={7,8,9,10,11};
    int n;
    scanf("%d",&n);
    Node* head=NULL;
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++){
        insertAtEnd(&head,a[i]);
    }
    insertNew(&head,n);
    print_list(head);
}