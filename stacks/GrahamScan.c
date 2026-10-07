//Graham Scan - geometric algorithm 
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define MAX 100

//coordinate definition
typedef struct {
    char name;
    int x;
    int y;
    double angle;
}coordinate;

//stack definition
coordinate stack[MAX];
int top=-1;
void push(coordinate val){
    if(top!=MAX-1){
        stack[++top]=val;
    }
}
coordinate pop(){
    if(top!=-1){
        return stack[top--];
    }
}
int isEmpty(){
    return top==-1;
}


bool orientationValue(coordinate c1,coordinate c2,coordinate c3){
    double val=(c2.y-c1.y)*(c3.x-c2.x)-(c2.x-c1.x)*(c3.y-c2.y);

    if(val>0) return true; //clockwise - pop
    else return false; //anticlockwise - push
}

int main(){

    printf("Enter number of points: ");
    int n; //number of points
    scanf("%d",&n);

    coordinate points[n];

    for(int i=0;i<n;i++){
        printf("Enter point (name x y): ");
        scanf(" %c %d %d",&points[i].name,&points[i].x,&points[i].y);
    }

    //find the pivot point (lowest y coordinate);
    coordinate min=points[0];
    for(int i=1;i<n;i++){
        if(min.y>points[i].y ||(min.y==points[i].y && min.x>points[i].x)){
            min=points[i];
        }
    }


    //finding pivot angle for each point
    for(int i=0;i<n;i++){
        points[i].angle=atan2((points[i].y-min.y),(points[i].x-min.x));
    }

    //sort based on pivot angle
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(points[j].angle>points[j+1].angle){
                coordinate temp=points[j];
                points[j]=points[j+1];
                points[j+1]=temp;
            }
        }
    }

    push(points[0]);
    push(points[1]);
    push(points[2]);


    for(int i=3;i<n;i++){
        coordinate newPoint=points[i];

        while(top>=1 && orientationValue(stack[top-1],stack[top],newPoint)){
            pop();
        }

        push(newPoint);
    }

    printf("\nConvex Hull: ");
    
    while(!isEmpty()){
        coordinate curr=pop();
        printf("%c ",curr.name);
    }
    return 0;
}