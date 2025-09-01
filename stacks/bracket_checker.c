/*Equality Checker for brackets. 
Write a program to check whether the brackets in a string are balanced using stacks.  
Example:  
- Input: `"{[()]}"` → Output: `Balanced`  
- Input: `"{[(])}"` → Output: `Not Balanced`  */
#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char val){
    if(top!=MAX-1){
        stack[++top]=val;
    }
}
char pop(){
    if(top!=-1){
        return stack[top--];
    }
}
char peek(){
    return stack[top];
}
int isFull(){
    return top==MAX;
}
int isEmpty(){
    return top==-1;
}
bool open(char val){
    return(val=='('||val=='['||val=='{');
}
bool close(char val){
    return(val==')'||val==']'||val=='}');
}
bool isMatch(char open,char close){
    return((open=='('&&close==')')||(open=='['&&close==']')||(open=='{'&&close=='}'));
}
bool balanced(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        if(open(str[i])){
            push(str[i]);
        }
        else if(close(str[i])){
            if(isEmpty()){
                return false;
            }
            if(!isMatch(pop(),str[i])){
                return false;
            }
        }
    }
    return isEmpty();
}
int main(){
    char str[100];
    printf("enter string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';

    if(balanced(str)){
        printf("brackets are balanced");
    }
    else{
        printf("not balanced");
    }
}
