/*Maya is working on a calculator that parses postfix expressions to create binary expression trees. Each operand is a lowercase letter, and each operator is one of +, -, *, /, or ^. 

Write a program to construct the corresponding binary expression tree from a given postfix expression and print its preorder traversal to evaluate the expression structure.

Input format :
The input consists of a single line containing a postfix expression string with no spaces.

The string consists of lowercase alphabets and the operators +, -, *, /, ^.

Output format :
The output prints a single line containing the preorder traversal of the constructed binary expression tree, with each character (operand or operator) separated by a space.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Node{
    char data;
    struct Node *left,*right;
}Node;

typedef struct Stack{
    Node* arr[100];
    int top;
}Stack;

Node* createNode(char val){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

void push(Stack* s,Node* node){
    s->arr[++(s->top)]=node;
}

Node* pop(Stack* s){
    return s->arr[(s->top)--];
}
Node* buildTree(char postfix[]){
    Stack s;
    s.top=-1;

    for(int i=0;postfix[i]!='\0';i++){
        char ch=postfix[i];
        Node* node=createNode(ch);

        if(isalpha(ch)){
            push(&s,node);
        }
        else{
            Node* right=pop(&s);
            Node* left=pop(&s);
            node->left=left;
            node->right=right;
            push(&s,node);
        }
    }
    return pop(&s);
}
void preOrder(Node* root){
    if(root){
        printf("%c ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main(){
    char postfix[100];
    scanf("%s",postfix);

    Node* root=buildTree(postfix);
    preOrder(root);
}
