/*Given string str, we need to print the reverse of individual words.
Input: Hello World
Output: olleH dlroW
Explanation: Each word in "Hello World" is reversed individually, preserving the original order, resulting in "olleH dlroW".

Input: Geeks for Geeks
Output: skeeG rof skeeG*/
#include<stdio.h>
#include<string.h>
#define MAX 100
int top=-1;
char stack[MAX][100];
void push(char str[]){
    strcpy(stack[++top],str);
}
char* pop(){
    return stack[top--];
}
void reverse(char str[]){
    int n=strlen(str);
    for(int i=0;i<n/2;i++){
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
}
void rev_each(char str[]){
    char *token=strtok(str," ");
    char *b[100];
    while(token!=NULL){
        push(token);
        token=strtok(NULL," ");
    }
    int final_top=top; //storing top value because top changes after popping

    for(int i=0;i<=final_top;i++){
        char* a=pop();
        reverse(a);
        b[i]=a;
    }
    for(int j=final_top;j>=0;j--){
        printf("%s ",b[j]);
    }

}
int main(){
    printf("enter string\n");
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    rev_each(str);
}