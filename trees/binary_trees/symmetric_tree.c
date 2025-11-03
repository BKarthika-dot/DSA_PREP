#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 7

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* createNode(int val){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

Node* levelOrder(Node* root,int arr[],int i,int n){
    if(i<n){
        root=createNode(arr[i]);
        root->left=levelOrder(root->left,arr,2*i+1,n);
        root->right=levelOrder(root->right,arr,2*i+2,n);
    }
    return root;
}
bool isMirror(Node* n1,Node* n2){
    if(n1==NULL && n2==NULL)return true;
    if(n1==NULL || n2==NULL)return false;

    if(n1->data==n2->data && isMirror(n1->left,n2->right) && isMirror(n1->right,n2->left)){
        return true;  
    }
    return false;
}
bool isSymmetric(Node* root){
    if(root==NULL)return true;

    return isMirror(root->right,root->left);
}
int main(){
    int arr[max];
    for(int i=0;i<max;i++){
        scanf("%d",&arr[i]);
    }
    Node* root=NULL;

    root=levelOrder(root,arr,0,max);

    if(isSymmetric(root)){
        printf("tree is symmetric");
    }
    else{
        printf("tree is not symmetric");
    }
}