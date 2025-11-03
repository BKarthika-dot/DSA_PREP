/*Arjun is developing a program to analyze binary trees built from arrays. He wants to:



Construct a binary tree from an array using level order insertion (array index i has left child at 2*i+1 and right child at 2*i+2).
Perform an in-order traversal of the tree and store the result in an array.
For each node in the original input order, print its in-order predecessor and successor based on the in-order traversal.
If the predecessor or successor does not exist, print 0 in its place.


Help Arjun to implement the task.*/

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

Node* levelOrderInsertion(Node* root,int arr[],int i,int n){
    if(i<n){
        root=createNode(arr[i]);
        root->left=levelOrderInsertion(root->left,arr,2*i+1,n);
        root->right=levelOrderInsertion(root->right,arr,2*i+2,n);
    }
    return root;
}
void inOrder(Node* root,int inOrder_array[],int* index){
    
    if(root){
        inOrder(root->left,inOrder_array,index);
        inOrder_array[(*index)++]=root->data;
        inOrder(root->right,inOrder_array,index);
    }
}
int main(){
    int arr[max];
    Node* root=NULL;
    for(int i=0;i<max;i++){
        scanf("%d",&arr[i]);
    }
    root=levelOrderInsertion(root,arr,0,max);
    
    int inOrder_array[max];
    int index=0;
    inOrder(root,inOrder_array,&index);

    for(int i=0;i<max;i++){
        int pred=0;
        int succ=0;
        for(int j=0;j<max;j++){
            if(arr[i]==inOrder_array[j]){
                if(j>0){
                    pred=inOrder_array[j-1];
                }
                if(j<max-1){
                    succ=inOrder_array[j+1];
                }
                break;
            }
        }
        printf("%d : %d,%d\n",arr[i],pred,succ);
    }
}