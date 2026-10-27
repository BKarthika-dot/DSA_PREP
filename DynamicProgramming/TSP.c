//travelling salesman problem

//Complexity: Time (O(n^2 2^n)), space (O(n2^n)).

#include<stdio.h>
#define INF 999999

int n,cost[10][10],dp[10][1024];

int tsp(int i,int S){
    if(S==0) return cost[i][0];

    if(dp[i][S]!=-1) return dp[i][S];

    dp[i][S]=INF;

    for(int j=0;j<n;j++){
        if(S & (1<<j)){
            int temp=cost[i][j]+tsp(j,S^(1<<j));

            if(temp<dp[i][S]) dp[i][S]=temp;
        }
    }
    return dp[i][S];
}
int main(){
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            dp[i][j]=-1;
        }
    }

    printf("Minimum cost = %d",tsp(0,((1<<n)-1)^1));
    return 0;
}