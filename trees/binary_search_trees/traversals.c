/*inorder,preorder,postorder traversals*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* createNode(int val){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->left=newNode->right=NULL;
    return newNode;
}
Node* insert(Node** root,int val){
    if(*root==NULL){
        *root=createNode(val);
    }
    else if(val<(*root)->data){
        (*root)->left=insert(&((*root)->left),val);
    }
    else{
        (*root)->right=insert(&((*root)->right),val);
    }
    return *root;
}
void inOrder(Node *root){
    if(root){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void preOrder(Node *root){
    if(root){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    Node* root=NULL;
    int val;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        insert(&root,val);
    }
    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");
}