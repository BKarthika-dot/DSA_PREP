#include<stdio.h>
#include<stdlib.h>
#define max 50
int front=0;
int rear=0;

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

Node* queue[50];

void enqueue(Node* node){
    if(rear==max){
        printf("queue is full");
        return;
    }
    queue[rear++]=node;
}
Node* dequeue(){
    Node* x;
    if(front==rear){
        printf("queue is empty");
        return NULL;
    }
    return queue[front++];

}
Node* insert(Node* root,int val){
    if(root==NULL){
        root=createNode(val);
        return root;
    }
    front=rear=0;
    enqueue(root);

    while(front<rear){
        Node* current=dequeue();
        if(current->left==NULL){
            current->left=createNode(val);
            return root;
        }
        else{
            enqueue(current->left);
        }

        if(current->right==NULL){
            current->right=createNode(val);
            return root;
        }
        else{
            enqueue(current->right);
        }
    }
    return root;
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    printf("inorder traversal:\n");
    inorder(root);
    return 0;
}