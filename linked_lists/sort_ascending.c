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

void sort(Node** head){
    if(*head==NULL||(*head)->next==NULL){
        return;
    }
    Node* sorted=NULL;                //declaring a new sorted list

    while(*head){           //loop until list isnt empty  let's take [2 1 3 4 ]

        Node* temp=*head;     //temp=2
        *head=(*head)->next;      //detatching the node at the front  list is [1 3 4]
        temp->next=NULL;       //isolate temp

        if(sorted==NULL||temp->data <= sorted->data){
            temp->next=sorted;   //if temp is less than the value or sorted is empty in sorted insert temp at the front 
                                //temp->next is NULL
            sorted=temp;        //sorted=2
        }

        //after a while we have sorted as [1 2]   and head as [3 4]    so now our temp=3

        else{
            Node* temp2=sorted;    //temp=1

            while(temp2->next!=NULL && temp2->next->data < temp->data){      //temp2->next->data is 2 and temp->data is 3   so this condition is true
                temp2=temp2->next;
            }
            temp->next=temp2->next;     //initially temp->next is 4 and temp2->next is null   so now we have temp->next=null
            temp2->next=temp;       //2--->3     so now we have [1 2 3] in sorted 
        }
    }
    *head=sorted;
}


void print_list(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    Node* head=NULL;
    int val;
    for(int i=0;i<max;i++){
        scanf("%d",&val);
        insertAtEnd(&head,val);
    }
    sort(&head);
    print_list(head);
}