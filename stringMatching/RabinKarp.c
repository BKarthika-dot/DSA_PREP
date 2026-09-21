#include<stdio.h>
#include<string.h>

#define d 256
#define q 101
void rabinKarp(char text[],char pattern[]){
    int n=strlen(text);
    int m=strlen(pattern);

    int p=0; //pattern hash;
    int t=0; //text window hash;
    int h=1;
    int j;

    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }

    for(int i=0;i<m;i++){
        p=(p*d+pattern[i])%q;
        t=(t*d+text[i])%q;
    }

    for(int i=0;i<=n-m;i++){
        if(p==t){
            for(j=0;j<m;j++){
                if(text[i+j]!=pattern[j]) break;
            }
            if(j==m){
                printf("Pattern found at index %d",i);
            }

        }

        //finding hash for the next window
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;

            if(t<0) t+=q;
        }
    }

}
int main(){
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    
    rabinKarp(text,pattern);
}