/*Write a function insertAfterValue(Node** head, int target, int val) that:

Finds the first node whose data is equal to target.

Creates a new node with val.

Inserts the new node after the target node.

If target is not found, print "Value not found".*/
#include<stdio.h>
#include<stdlib.h>
#define max 5
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
void insert_after(Node** head,int target,int insert_val){
    Node* temp=*head;
    Node* newNode=createNode(insert_val);          //head → [10 | *] → [20 | *] → [30 | *] → NULL
                                                    //insert_after(&head, 20, 99);

    int index=0;
    if(*head==NULL){
        free(newNode);
        return;
    }
    
    while(temp!=NULL && temp->data!=target){
        temp=temp->next;
        index++;
    }
    if(temp==NULL){
        printf("target not in list\n");
        return;
    }

    /*head → [10 | *] → [20 | *] → [30 | *] → NULL
                                 |
                                 v
                                [99 | *]  (newNode->next → 30)*/

    newNode->next=temp->next;
    temp->next=newNode;             //head → [10 | *] → [20 | *] → [99 | *] → [30 | *] → NULL


}
int main(){
    int val;
    Node* head=NULL;
    for(int i=0;i<max;i++){
        scanf("%d",&val);
        insertAtEnd(&head,val);
    }
    int target;
    scanf("%d",&target);
    int insert_val;
    scanf("%d",&insert_val);

    insert_after(&head,target,insert_val);
    print_list(head);
}