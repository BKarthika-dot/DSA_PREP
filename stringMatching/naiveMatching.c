#include<string.h>
#include<stdio.h>
int main(){
    char text[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";

    int n=strlen(text);
    int m=strlen(pattern);

    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]) break;
        }
        if(j==m){
            printf("Pattern found at %d\n",i);
        }
    }
    return 0;
}