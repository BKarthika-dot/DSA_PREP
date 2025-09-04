/*Given a string str consisting of opening and closing parenthesis '(' and ')', the task is to find the length of the longest valid parenthesis substring.

Examples: 

Input: str = "((()"
Output: 2
Explanation: Longest Valid Parentheses Substring is "()".

Input: str = ")()())"
Output: 4
Explanation: Longest Valid Parentheses Substring is "()()".*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
int stack[MAX];
int top=-1;
int isEmpty(){
    return top==-1;
}
void push(int val){
    stack[++top]=val;
}
int pop(){
   return stack[top--]; 
}
int peek(){
    return stack[top];
}

bool isMatch(char open,char close){
    return(open=='('&&close==')'||open=='['&&close==']'||open=='{'&&close=='}');
}
bool open(char a){
    return(a=='('||a=='['||a=='{');
}
bool close(char a){
    return(a==')'||a==']'||a=='}');
}
int max=0;

int count_length(char str[]){
    int n=strlen(str);
    
    for(int i=0;i<n;i++){
        char c=str[i];
        if(open(c)){
            push(i);
        }
        else if(close(c)){
            if(!isEmpty()&&isMatch(str[stack[top]],c)){
                pop();
                int length=i-stack[top];

                if(length>max){
                    max=length;  
                }
            }
            else{
                push(i);
            }
        }
    } 
    return max;   
}
int main(){
    char str[100];
    printf("enter string\n");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    printf("longest valid string is %d",count_length(str));
}
