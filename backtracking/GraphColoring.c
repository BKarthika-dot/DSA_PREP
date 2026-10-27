#include<stdio.h>
int n,m;
int graph[10][10],color[10];

int safe(int v,int c){

    for(int i=0;i<n;i++){
        if(graph[v][i] && color[i]==c) return 0;
    }
    return 1;
}

int solve(int v){
    //base case
    if(v==n) return 1;

    for(int c=1;c<=m;c++){
        //constraint
        if(safe(v,c)){
            //make choice;
            color[v]=c;

            //backtrack
            if(solve(v+1)) return 1;
            color[v]=0;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    if(solve(0)){
        for(int i=0;i<n;i++){
            printf("Vertex %d --> Color %d\n",i,color[i]);
        }
    }
    else printf("No solution\n");
    return 0;
}