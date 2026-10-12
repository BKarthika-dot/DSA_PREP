#include<stdio.h>
#define N 100
#define INF 999999

int main(){

    int n,m,u[N],v[N],w[N],d[N];

    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    }

    int s;
    scanf("%d",&s);

    for(int i=0;i<n;i++){
        d[i]=INF;
    }

    d[s]=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[u[j]]!=INF && d[u[j]]+w[j]<d[v[j]]){
                d[v[j]]=d[u[j]]+w[j];
            }
        }
    }

    for(int j=0;j<m;j++){
        if(d[u[j]]!=INF && d[u[j]]+w[j]<d[v[j]]){
            printf("Negative cycle\n");
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d : %d\n",i,d[i]==INF?-1:d[i]);
    }
    return 0;
}