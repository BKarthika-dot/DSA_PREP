// Program to implement Prim's Algorithm in C
// This algorithm finds the Minimum Spanning Tree (MST) of a connected weighted graph,
// ensuring the minimum total edge weight while connecting all vertices.


#include<stdio.h>
#define max 10
int findMinKey(int key[],int mst[],int n){
    int min=9999;
    int idx=-1;
    for(int i=0;i<n;i++){
        if(key[i]<min && mst[i]==0){
            min=key[i];
            idx=i;
        }
    }
    return idx;
}
void prims(int graph[max][max],int n){
    int key[n],mst[n],parent[n];
    for(int i=0;i<n;i++){
        key[i]=9999;
        mst[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;i++){
        int u=findMinKey(key,mst,n);
        mst[u]=1;
        for(int v=0;v<n;v++){
            if(graph[u][v] && graph[u][v]<key[v] && mst[v]==0){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    printf("Edge\t\tWeight\n");
    for(int i=1;i<n;i++){
        printf("%d -> %d\t\t%d\n",i,parent[i],graph[i][parent[i]]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int graph[max][max];
    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){
            scanf("%d",&graph[u][v]);
        }
    }
    prims(graph,n);
}