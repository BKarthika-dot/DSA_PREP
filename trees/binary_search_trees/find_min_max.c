#include<stdio.h>
#include<stdlib.h>
#define max 8

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* createNode(int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->right=newNode->left=NULL;
    return newNode;
}
Node* insert(Node* root,int val){
    if(root==NULL){
        return createNode(val);
    }

    if(root->data>val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
int findMax(Node* root){
    if(root==NULL){
        return -1;
    }
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}

int findMin(Node* root){
    if(root==NULL){
        return -1;
    }
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int main(){
    int val;
    Node* root=NULL;
    for(int i=0;i<max;i++){
        scanf("%d",&val);
        root=insert(root,val);
    }
    printf("Maximum: %d\n",findMax(root));
    printf("Minimum: %d\n",findMin(root));
}