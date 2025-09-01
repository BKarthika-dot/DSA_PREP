/*Goal: Use a stack to evaluate something like "23*5+".

Example:
Input: "23*5+" → Output: 11*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];

int top=-1;

int isFull(){
    return top==MAX-1;
}
int isEmpty(){
    return top==-1;
}
void push(char val){
    if(!isFull()){
        stack[++top]=val;
    }
}
char pop(){
    if(!isEmpty()){
        return stack[top--];
    }
    return '\0';
}
char peek(){
    return stack[top];
}
int switching(int a,int b,char symbol){
    switch(symbol){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '^':
            return a^b;
        default:
            return -1;
    }
}
int postfix(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        if(isdigit(str[i])){
            char dc=str[i];
            int d= dc-'0';
            push(d);
        }
        else{
            int b=pop();
            int a=pop();
            int c=switching(a,b,str[i]);
            push(c);
        }
    }
    return peek();
}
int main(){
    char str[100];
    printf("enter string:\n");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
   
    printf("answer is : %d",postfix(str));
}