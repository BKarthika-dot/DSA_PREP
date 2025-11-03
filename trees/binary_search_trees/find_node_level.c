/*Aiden, a software engineer, is working on an algorithm to determine the level of a specific node within a Binary Search Tree (BST). He wants to implement a function that will find and return the level of a given node in a BST. 

Note: The level of the root node is considered to be 0.

Example

Input:
7
20 10 30 5 15 25 35
25

Output:
2

Explanation:
The BST of the nodes is Root node 20 is at level 0. Nodes 10 and 30 are at level 1. Node 25 is at level 2.
Therefore, the level of node 25 is 2.*/

#include<stdio.h>
#include<stdlib.h>
#define max 7

typedef struct Node{
    int data;
    struct Node* right,*left;
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


int findLevel(Node* root,int val,int level){
    if(root==NULL)return -1; //never found

    if(root->data==val)return level;

    if(root->data>val){
        return findLevel(root->left,val,level+1);
    }
    else{
        return findLevel(root->right,val,level+1);
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

    printf("Level of %d is: %d",x,findLevel(root,x,0));
}