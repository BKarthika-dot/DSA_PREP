#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void computeLPS(char pattern[],int lps[]){
    int m=strlen(pattern);
    lps[0]=0;

    int i=1;
    int len=0; //length of lps
    while(i<m){
        if(pattern[len]==pattern[i]){
            len++;
            lps[i]=len;
            i++;
        }
        else if(len!=0){
            len=lps[len-1];
        }
        else{
            lps[i]=0;
            i++;
        }
    }
}
void kmp(char text[],char pattern[]){
    int n=strlen(text);
    int m=strlen(pattern);

    int i=0; //text index
    int j=0; //patern index

    int lps[m];
    computeLPS(pattern,lps);

    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            printf("Pattern found at index %d\n",i-j);
            j=lps[j-1];
        }
        else if(i<n && text[i]!=pattern[j]){
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
}
int main(){
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    kmp(text, pattern);
}