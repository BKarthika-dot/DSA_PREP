/*Given a singly linked list with n values, the linked list needs to be modified such that the even numbers are displayed at the beginning, followed by the odd numbers in a reversed manner.
Example
Input:
5
12 15 13 14 16
Output: 
16 14 12 13 15*/

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
    return newNode;
}
void insertAtFront(Node **head,int val){
    Node* newNode=createNode(val);
    newNode->next=*head;
    *head=newNode;
}

void print_list(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n,val;
    scanf("%d",&n);
    Node* even_head=NULL;
    Node* odd_head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        if(val%2==0){
            insertAtFront(&even_head,val);
        }
        else{
            insertAtFront(&odd_head,val);
        }
    }
    Node* head=NULL;
    if(even_head==NULL){
        head=odd_head;
    }
    else{
        Node* temp=even_head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=odd_head;
        head=even_head;
    }
    print_list(head);
}
