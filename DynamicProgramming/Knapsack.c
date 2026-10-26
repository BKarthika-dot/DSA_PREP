//0/1 knapsack using dynamic programming
#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    int n,W;
    scanf("%d%d",&n,&W);
    int wt[100],profit[100],dp[101][101];

    for(int i=1;i<=n;i++){
        scanf("%d%d",&wt[i],&profit[i]);
    }
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0||w==0) dp[i][w]=0;

            else if(wt[i]<=w){
                dp[i][w]=max(profit[i]+dp[i-1][w-wt[i]],dp[i-1][w]);
            }
            else dp[i][w]=dp[i-1][w];
        }
    }
    printf("Maximum profit is %d ",dp[n][W]);
    return 0;
}