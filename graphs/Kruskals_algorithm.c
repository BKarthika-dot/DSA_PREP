// Program to implement Kruskal's Algorithm in C
// This algorithm finds the Minimum Spanning Tree (MST) of a connected weighted graph
// using a greedy approach and the union-find (disjoint set) data structure.


#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
    int src,dest,weight;
}edge;
int compare(const void* a,const void* b){
    edge* a1=(edge*)a;
    edge* b1=(edge*)b;
    return a1->weight-b1->weight;
}
int findParent(int parent[],int i){
    if(parent[i]!=i){
        parent[i]=findParent(parent,parent[i]);
    }
    return parent[i];
}
void joinSets(int parent[],int x,int y){
    int xset=findParent(parent,x);
    int yset=findParent(parent,y);
    parent[yset]=xset;
}
void kruskal(edge edges[],int no_of_edges,int no_of_vertices){
    edge* result=(edge*)malloc((no_of_vertices-1)*sizeof(edge));
    int* parent=(int*)malloc(no_of_vertices*sizeof(int));
    qsort(edges,no_of_edges,sizeof(edges[0]),compare);

    for(int i=0;i<no_of_vertices;i++){
        parent[i]=i;
    }

    int count_edges=0;
    int i=0;
    int minCost=0;

    while(i<no_of_edges && count_edges<no_of_vertices-1){
        edge next_edge=edges[i++];
        int x=findParent(parent,next_edge.src);
        int y=findParent(parent,next_edge.dest);

        if(x!=y){
            result[count_edges++]=next_edge;
            joinSets(parent,x,y);
            minCost+=next_edge.weight;
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for(int i=0;i<count_edges;i++){
        printf("%d -- %d == %d\n",result[i].src,result[i].dest,result[i].weight);
    }
    printf("Minimum Cost Spanning Tree: %d",minCost);
}
int main(){
    int no_of_vertices;
    int no_of_edges;
    scanf("%d%d",&no_of_vertices,&no_of_edges);
    edge edges[no_of_edges];
    for(int i=0;i<no_of_edges;i++){
        scanf("%d %d %d",&edges[i].src,&edges[i].dest,&edges[i].weight);
    }
    kruskal(edges,no_of_edges,no_of_vertices);
}