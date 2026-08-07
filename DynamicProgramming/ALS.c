//assembly line scheduling
//time complexity: O(n) space complexity: O(n)

#include<stdio.h>
int main(){
    //both assembly lines
    int a[2][6]={{7,9,3,4,8,4},{8,5,6,4,5,7}};


    //both transfer times
    int t[2][6]={{2,3,1,3,4},{2,1,2,2,1}};
    
    int e1=2,e2=4; //entry time
    int x1=3,x2=4; //exit time

    int f[2][6]; //fastest time
    int chosen[2][6]; //chosen line

    f[0][0]=a[0][0]+e1;
    f[1][0]=a[1][0]+e2;

    for(int j=1;j<6;j++){
        if (f[0][j-1] + a[0][j] < f[1][j-1] + t[1][j-1] + a[0][j]) {
            f[0][j] = f[0][j-1] + a[0][j];
            chosen[0][j] = 0;
        }else {
            f[0][j] = f[1][j-1] + t[1][j-1] + a[0][j];
            chosen[0][j] = 1; 
        }

        if (f[1][j-1] + a[1][j] < f[0][j-1] + t[0][j-1] + a[1][j]) {
            f[1][j] = f[1][j-1] + a[1][j];
            chosen[1][j] = 1;
        } else {
            f[1][j] = f[0][j-1] + t[0][j-1] + a[1][j];
            chosen[1][j] = 0; 
        }

        
    }
    int fastest_time,fastest_line;

    if(f[0][5]+x1<f[1][5]+x2){
        fastest_time=f[0][5]+x1;
        fastest_line=1;
    }
    else{
        fastest_time=f[1][5]+x2;
        fastest_line=2;
    }
    printf("Time taken: %d Line Chosen: %d",fastest_time,fastest_line);
}