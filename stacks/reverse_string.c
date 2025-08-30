/*reversing a string using stack*/
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
    return stack[top--];
}
int isEmpty(){
    return top==-1;
}
void reverse(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        push(str[i]);
    }
    char reversed[n+1];
    int i=0;
    while(!isEmpty()){
        reversed[i++]=pop();
    }
    reversed[i]='\0';
    printf("reversed string is: %s",reversed);
    
}
int main(){
    char str[100];
    printf("enter string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    reverse(str);
}