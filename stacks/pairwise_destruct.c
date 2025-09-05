/*Given an array of n strings arr[]. The task is to determine the number of words remaining after pairwise destruction.
If two consecutive words in the array are identical, they cancel each other out.
This process continues until no more eliminations are possible.

Input: arr[] = ["gfg", "for", "geeks", "geeks", "for"]
Output: 1
Explanation: After the first iteration, we'll have: [gfg, for, for]. 
Then after the second iteration, we'll have: [gfg]. 
No more eliminations are possible. Hence, the result is 1.*/

#include<stdio.h>
#include<string.h>
#define MAX 100
int top=-1;
char stack[MAX][100];
void push(char str[]){
    strcpy(stack[++top],str);
}
void pop(){
    top--;
}
int isEmpty(){
    return top==-1;
}
int destruct(int n,char str[][100]){
    int count=0;
    for(int i=0;i<n;i++){
        if(!isEmpty()&&strcmp(stack[top],str[i])==0){
            pop();
        }
        else{
            push(str[i]);
        }
    }
    return top+1;
}
int main(){
    printf("enter no of strings\n");
    int n;
    scanf("%d",&n);
    getchar();
    printf("enter the strings\n");
    char str[n][100];
    for(int i=0;i<n;i++){
        fgets(str[i],sizeof(str[i]),stdin);
        str[i][strcspn(str[i],"\n")]='\0';
    }
    printf("final stack count is %d",destruct(n,str));
}