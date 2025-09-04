/*Tower of Hanoi*/
#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
int moves=0;

void push(int disk){
    stack[top++]=disk;
}
void moveDisk(int n,char source,char dest,char aux){
    if(n==1){
        printf("Moved disk %d: %c to %c\n",n,source,dest);
        moves++;
        return;
    }
    moveDisk(n-1,source,aux,dest);
    printf("Moved disk %d: %c to %c\n",n,source,dest);
    moves++;
    moveDisk(n-1,aux,dest,source);
}
int main(){
    printf("enter no of disks:\n");
    int n;
    scanf("%d",&n);

    char source='A';//source peg
    char dest='C';//destination peg
    char aux='B';//auxillary peg(helper peg)
    moveDisk(n,source,dest,aux);
    printf("total number of moves done is:%d\n",moves);


}
