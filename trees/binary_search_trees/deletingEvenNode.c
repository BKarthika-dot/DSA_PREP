/*deleting even nodes from the binary tree*/

#include<stdio.h>
#include<stdlib.h>
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

void postOrder(Node* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
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
    if(val<root->data){
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteNode(root->right,val);
    }
    else{
        //when node is found and node has only one child
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }

        //when node has 2 children replace with inorder successor
        Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
Node* deleteEven(Node* root){
    if(root==NULL)return NULL;
    root->left=deleteEven(root->left);
    root->right=deleteEven(root->right);

    if(root->data%2==0){
        root=deleteNode(root,root->data);
    }
    return root;
}

int main(){
    int n;
    scanf("%d",&n);
    int val;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        root=insert(root,val);
    }
    root=deleteEven(root);
    postOrder(root);
}