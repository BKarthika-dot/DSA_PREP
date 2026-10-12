#include<stdio.h>
#define N 100
#define INF 999999

int main(){

    int n,d[N][N];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&d[i][j]);

            if(i!=j && d[i][j]==-1){
                d[i][j]=INF;
            }
        }
    }

    //Three loops in the order k, i, j. Ask: Can going through k make the path from i to j shorter?
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]!=INF && d[k][j]!=INF && d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]==INF) printf("-1 ");
            else printf("%d ",d[i][j]);
        }
        printf("\n");
    }

    return 0;
}