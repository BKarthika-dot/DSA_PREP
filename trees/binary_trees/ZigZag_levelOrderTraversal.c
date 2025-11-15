#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 6

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* createNode(int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->left=newNode->right=NULL;
    return newNode;
}


Node* queue[max];
int stack[max];

int top=-1;
int front=-1;
int rear=-1;

void push(int val){
    stack[++top]=val;
}
int pop(){
    return stack[top--];
}
int stack_isEmpty(){
    return top==-1;
}

int queue_isEmpty(){
    return front==-1;
}
void enqueue(Node* node){
    if(rear==max-1){
        return;
    }
    if(front==-1)front=0;
    queue[++rear]=node;
}
Node* dequeue(){
    if(queue_isEmpty()){
        return NULL;
    }
    Node* temp=queue[front];

    if(front == rear)
        front = rear = -1;
    else
        front++;

    return temp;
}
void resetQueue(){
    front=rear=-1;
}

Node* insertLevelOrder(int arr[],Node* root,int i,int n){
    if(i<n){
        root=createNode(arr[i]);
        root->left=insertLevelOrder(arr,root->left,2*i+1,n);
        root->right=insertLevelOrder(arr,root->right,2*i+2,n);
    }
    return root;
}

void levelOrderTraversal(Node* root){
    enqueue(root);
    while(!queue_isEmpty()){
        Node* node=dequeue();
        printf("%d ",node->data);

        if(node->left!=NULL){
            enqueue(node->left);
        }
        if(node->right!=NULL){
            enqueue(node->right);
        }
    }
}
void zig_zag_levelOrder(Node* root){

    if(root==NULL)return;

    enqueue(root);
    bool flag=false;

    while(!queue_isEmpty()){
        int levelSize=rear-front+1;

        for(int i=0;i<levelSize;i++){
            Node* node=dequeue();

            if(flag){
                printf("%d ",node->data);
            }
            else{
                push(node->data);
            }

            if(node->left)enqueue(node->left);
            if(node->right)enqueue(node->right);
        }

        if(!flag){
            while(!stack_isEmpty()){
                printf("%d ",pop());
            }
        }

        flag=!flag;
    }
    
}
int main(){
    int a[max];
    for(int i=0;i<max;i++){
        scanf("%d",&a[i]);
    }
    Node* root=NULL;
    root=insertLevelOrder(a,root,0,max);

    printf("Level Order Traversal: \n");
    levelOrderTraversal(root);
    printf("\n");


    resetQueue();

    printf("Zig Zag Level Order: \n");
    zig_zag_levelOrder(root);

}