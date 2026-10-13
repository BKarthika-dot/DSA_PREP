#include<stdio.h>
#define N 100

int cap[N][N],parent[N],q[N],n;

int bfs(int s,int t){

    int seen[N]={0},front=0,rear=0;

    q[rear++]=s; //add source to queue
    seen[s]=1; // set source as visited
    parent[s]=-1;

    while(front<rear){
        int u=q[front++];

        for(int v=0;v<n;v++){
            if(!seen[v] && cap[u][v]>0){
                parent[v]=u;
                seen[v]=1;

                if(v==t) return 1;

                q[rear++]=v;
            }
        }
    }
    return 0;
}

int main(){

    int m,s,t,u,v,c,flow=0;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&c);
        cap[u][v]+=c;
    }

    scanf("%d%d",&s,&t);


    while(bfs(s,t)){

        int add=999999;

        for(v=t;v!=s;v=parent[v]){
            if(cap[parent[v]][v]<add) add=cap[parent[v]][v];
        }

        for(v=t; v!=s;v=parent[v]){
            u=parent[v];
            cap[u][v]-=add;
            cap[v][u]+=add;
        }

        flow+=add;
    }

    printf("Maximum flow = %d\n",flow);
}