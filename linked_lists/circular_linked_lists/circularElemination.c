/*Josephus Problem – Circular Linked List (C Implementation)

This repository contains a clean and minimal C implementation of the Josephus elimination algorithm using a circular singly linked list.
Each employee is represented as a node, and elimination occurs in fixed steps (count = 3 by default). The process continues until only one employee remains — the winner.

Key features:

Circular linked list implementation

Dynamic node creation

Step-wise elimination logic

Automatic memory deallocation

Simple, scalable structure for experimenting with Josephus variations*/
    
    
    #include<stdio.h>
    #include<stdlib.h>
    #define count 3

    typedef struct Node{
        int employee_id;
        struct Node* next;
    }Node;

    Node* createNode(int val){
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->employee_id=val;
        newNode->next=NULL;
        return newNode;
    }
    void insertAtEnd(Node** head,int val){
        Node* newNode=createNode(val);

        if(*head==NULL){
            *head=newNode;
            newNode->next=newNode;
            return;
        }

        Node* temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=*head;
    }

    void eliminate(Node** head){
        Node* curr=*head;
        Node* prev=NULL;

        while(curr->next!=curr){
            for(int i=0;i<count-1;i++){
                prev=curr;
                curr=curr->next;
            }
            printf("Employee %d has been eliminated\n",curr->employee_id);
            prev->next=curr->next;
            if(curr==*head){
                *head=prev->next;
            }
            free(curr);
            curr=prev->next;
        }
        int winner = curr->employee_id;
        printf("Employee %d is the winner\n",curr->employee_id);
        free(curr);
        *head=NULL;
    }
    int main(){
        int n;
        scanf("%d",&n);

        Node* head=NULL;

        for(int i=0;i<n;i++){
            insertAtEnd(&head,i); 
        }

        eliminate(&head);
    }