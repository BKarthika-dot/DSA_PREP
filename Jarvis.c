#include<stdio.h>
typedef struct{
    int x,y;
}Point;
Point p[100];
int n;

int cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
void jarvis(){
    int left=0;
    for(int i=1;i<n;i++){
        if(p[left].x>p[i].x)left=i;
    }
    int curr=left;
    do{
        printf("(%d,%d)\n",p[curr].x,p[curr].y);

        int next=(curr+1)%n;

        for(int i=0;i<n;i++){
            if(cross(p[curr],p[i],p[next])>0) next=i;
        }
        curr=next;
    }while(curr!=left);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    jarvis();
    return 0;
}