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
void print_list(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void deleteValue(Node** head,int val){
    Node* temp=*head;
    Node* prev=NULL;     //starting a new linked list prev
    int index=0;
    if(*head==NULL){
        return;
    }
    if(temp!=NULL && temp->data==val){
        *head=temp->next;
        free(temp);
        printf("Node with value %d deleted from index %d\n",val,index);
        return;
    }
    while(temp!=NULL && temp->data!=val){
        prev=temp;
        temp=temp->next;
        index++;
    }
    if(temp==NULL){
        printf("value not in linked list\n");
        return;
    }

    prev->next=temp->next;
    free(temp);
}
int main(){
    int val;

    Node* head=NULL;

    for(int i=0;i<max;i++){
        scanf("%d",&val);
        insertAtEnd(&head,val);
    }
    int n;
    scanf("%d",&n);
    deleteValue(&head,n);
    print_list(head);
}