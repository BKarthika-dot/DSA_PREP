#include<stdio.h>
#include<stdlib.h>
#define max 7

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
Node* insertLevelOrder(int arr[],Node* root,int i,int n){
    if(i<n){
        root=createNode(arr[i]);
        root->left=insertLevelOrder(arr,root->left,2*i+1,n);
        root->right=insertLevelOrder(arr,root->right,2*i+2,n);
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

    int arr[max];
    Node* root=NULL;

    for(int i=0;i<max;i++){
        scanf("%d",&arr[i]);
    }
    root=insertLevelOrder(arr,root,0,max);
    inOrder(root);
}