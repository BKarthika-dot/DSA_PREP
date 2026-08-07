#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//longest common subsequence in 2 strings
//time complexity: O(m.n) space complexity: O(m.n)

int main(){
    char str1[] ="strongest";
    char str2[]="strobe";

    int m=strlen(str1);
    int n=strlen(str2);

    int c[m+1][n+1];
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(int j=0;j<=n;j++){
        c[0][j]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                c[i][j]=c[i-1][j-1]+1;   //if match diagonal+1
            }else{
                c[i][j]=(c[i-1][j]>c[i][j-1])?c[i-1][j]:c[i][j-1];  //else it's the max value among top element and left element
            }
        }
    }
    printf("%d",c[m][n]) ; //length of lcs

    //tracebacking to find lcs
    int x=m;
    int y=n;
    char lcs[c[m][n]+1];
    lcs[c[m][n]]= '\0';
    int index=c[m][n]-1;

    while(x>0 && y>0){
        if(str1[x-1]==str2[y-1]){
            lcs[index]=str1[x-1];
            index--;
            x--;
            y--;
        }
        else if(c[x-1][y]>=c[x][y-1]){
            x--;
        }
        else{
            y--;
        }
    }
    printf("\n");
    printf("%s",lcs);

}