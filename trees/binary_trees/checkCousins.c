#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 8

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

int front=0;
int rear=0;

Node* queue[max];
void enqueue(Node* node){
    if(rear==max){
        printf("queue is full");
        return;
    }
    queue[rear++]=node;
}
Node* dequeue(){
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
int findDepth(Node* root,int val){
    if(root==NULL)return -1;

    if(root->data==val)return 0;

    int left=findDepth(root->left,val);
    if(left!=-1)return left+1;

    int right=findDepth(root->right,val);
    if(right!=-1)return right+1;

    return -1;
}
Node* findDaddy(Node* root,int val){
    if(root==NULL||root->data==val)return NULL;

    if((root->left&&root->left->data==val)||(root->right&&root->right->data==val))return root;

    Node *left=findDaddy(root->left,val);
    if(left) return left;

    return findDaddy(root->right,val);
}
bool isCousins(Node* root,int x,int y){
    if(findDaddy(root,x)!=findDaddy(root,y)&&findDepth(root,x)==findDepth(root,y))return true;

    return false;
}
int main(){
    int val;
    Node* root=NULL;
    for(int i=0;i<max;i++){
        scanf("%d",&val);
        root=insert(root,val);
    }
    int x,y;
    scanf("%d%d",&x,&y);
    if(isCousins(root,x,y)){
        printf("they are cousins");
    }
    else{
        printf("not cousins");
    }
}

