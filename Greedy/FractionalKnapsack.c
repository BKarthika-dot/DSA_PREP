#include<stdio.h>
typedef struct{
    int wt,profit;
    float ratio;
}item;

int main(){
    int n,W;
    scanf("%d%d",&n,&W);

    item items[100], temp;
    float total=0;

    for(int i=0;i<n;i++){
        scanf("%d%d",&items[i].wt,&items[i].profit);

        items[i].ratio=(float)items[i].profit/items[i].wt;

    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(items[i].ratio<items[j].ratio){
                temp=items[i];
                items[i]=items[j];
                items[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(items[i].wt<=W){
            total+=items[i].profit;
            W-=items[i].wt;
        }
        else{
            total+=items[i].ratio*W;
            break;
        }
    }
    printf("Maximum Profit = %.2f\n",total);
}