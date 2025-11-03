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
    newNode->left=newNode->right=NULL;
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
Node* findMin(Node* root){
    if(root==NULL)return NULL;
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* findNode(Node* root, int x);     // forward declare both
Node* deleteNode(Node* root);


Node* findNode(Node* root,int x){
    if(root==NULL)return NULL;

    if(root->data>x){
        root->left=findNode(root->left,x);
    }
    else if(root->data<x){
        root->right=findNode(root->right,x);
    }
    else{
        root=deleteNode(root);
    }
    return root;
}
Node* deleteNode(Node* root){
    if(root->left==NULL){
        Node* node=root->right;
        free(root);
        return node;
    }
    else if(root->right==NULL){
        Node* node=root->left;
        free(root);
        return node;
    }
    else{
        Node* node=findMin(root->right);
        root->data=node->data;
        root->right=findNode(root->right,node->data);
    }
    return root;
    
}

void inOrder(Node* root){
    if(root){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int main(){
    int val;
    Node* root=NULL;
    for(int i=0;i<max;i++){
        scanf("%d",&val);
        root=insert(root,val);
    }
    int x;
    scanf("%d",&x);
    root=findNode(root,x);
    inOrder(root);
}