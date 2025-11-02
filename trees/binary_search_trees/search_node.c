#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 5

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* createNode(int val){
    Node *newNode=(Node*)malloc(sizeof(Node));
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
bool search_element(Node* root,int x){
    if(root==NULL)return false;

    if(x>root->data){
        return search_element(root->right,x);
    }
    else if(x<root->data){
        return search_element(root->left,x);
    }
    else{
        return true;
    }
    return false;
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
    if(search_element(root,x)){
        printf("element found");
    }
    else{
        printf("element not found");
    }
}