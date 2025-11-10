/*This program implements Breadth-First Search (BFS) using an adjacency list representation of a graph.

It takes an adjacency matrix as input, builds the corresponding adjacency list, and then performs BFS starting from a given node.

The program prints both the BFS traversal order and a table showing each node’s parent and distance from the source.*/

#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//declaring an adjacency list
Node* adj[max];

//adding an edge to the adjacency list
void addEdge(int u,int v){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=v;
    newNode->next=adj[u];
    adj[u]=newNode;
}


void bfs(int start,int n){
    int visited[max]={0};
    int parent[n],dist[n],queue[n];
    
    int front=0,rear=0; //queue initialization

    for(int i=0;i<n;i++){
        parent[i]=-1;
        dist[i]=-1;
    }

    queue[rear++]=start; //enqueuing first element;
    visited[start]=1;
    dist[start]=0;

    printf("BFS Order\n");
    while(front<rear){
        int u=queue[front++];
        printf("%d ",u);

        for(Node* p=adj[u];p!=NULL;p=p->next){
            int v=p->data;
            if(!visited[v]){
                visited[v]=1;
                parent[v]=u;
                dist[v]=dist[u]+1;
                queue[rear++]=v;
            }
        }
    }
    printf("\n\nNode : Parent, Distance\n");
    for (int i = 0; i < n; i++) {
        printf("%2d :   %2d,    %2d\n", i, parent[i], dist[i]);
    }

}
int main(){
    int n;
    scanf("%d",&n);

    //taking input as adjacency matrix
    int graph[max][max];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    //building adjacency list
    for(int i=0;i<n;i++){
        adj[i]=NULL;
        for(int j=0;j<n;j++){
            if(graph[i][j]==1){
                addEdge(i,j);
            }
        }
    }

    int start; //starting vertex
    scanf("%d",&start);
    bfs(start,n);

}