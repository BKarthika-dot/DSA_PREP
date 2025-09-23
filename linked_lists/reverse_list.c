/*doing insertion front so input values are reversed
The new node’s next is linked to the current head.

Then we move the head pointer to this new node.

🔄 Time complexity: O(1) (always instant, no matter list length).*/

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

void insertAtFront(Node** head,int val){
    Node* newNode=createNode(val);
    newNode->next=*head;
    *head=newNode;
}
void print_list(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    int val;
    Node* head=NULL;
    for(int i=0;i<max;i++){
        scanf("%d",&val);
        insertAtFront(&head,val);
    }
    print_list(head);
    return 0;
}