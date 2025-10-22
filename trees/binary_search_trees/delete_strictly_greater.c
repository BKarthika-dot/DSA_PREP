/*
Write a C program to:

Build a Binary Search Tree (BST) by inserting n integers.

Then delete all nodes whose values are strictly greater than the root node’s value.

Finally, print the inorder traversal of the remaining tree.*/
#include<stdio.h>
#include<stdlib.h>
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
        root=createNode(val);
    }
    else if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
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
Node* findMin(Node* root){
    while(root&&root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* deleteNode(Node* root,int val){
    if(root==NULL)return root;
    else if(val<root->data){
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteNode(root->right,val);
    }
    //found the node
    else{
        //only has right child
        if(root->left==NULL){
            Node* node=root->right;
            free(root);
            return node;
        }
        //only has left child
        else if(root->right==NULL){
            Node* node=root->left;
            free(root);
            return node;
        }
        //has 2 children
        else{
            Node* node=findMin(root->right);
            root->data=node->data;
            root->right=deleteNode(root->right,node->data);
        }
    }
    return root;
}
Node* deleteGreaterThanRoot(Node* root,int val){
    if(root==NULL)return NULL;

    root->left=deleteGreaterThanRoot(root->left,val);
    root->right=deleteGreaterThanRoot(root->right,val);

    if(root->data>val){
        root=deleteNode(root,root->data);
    }
    return root;
}
int main(){
    int n;
    scanf("%d",&n);
    Node *root=NULL;
    int val;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        root=insert(root,val);
    }
    root=deleteGreaterThanRoot(root,root->data);
    inOrder(root);
}