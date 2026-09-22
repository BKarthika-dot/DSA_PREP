// 0/1 Knapsack problem using backtracking

#include<stdio.h>
int maxProfit=0;
int currentProfit=0;
int currentWeight=0;
int maxWeight=50;

int chosen[20];
int bestChosen[20];

typedef struct{
    int weight;
    int profit;
}Item;

void knapsack(int start,int n,int currentWeight,int currentProfit, Item items[]){

    //base case
    if(start==n){
        if(currentProfit>maxProfit){
            maxProfit=currentProfit;

            for(int i=0;i<n;i++){
                bestChosen[i]=chosen[i];
            }
        }
        return;
    }

    //don't pick up
    chosen[start]=0;
    knapsack(start+1,n,currentWeight,currentProfit,items);

    //pick the item
    if(currentWeight+items[start].weight<=maxWeight){
        chosen[start]=1;
        knapsack(start+1,n,currentWeight+items[start].weight,currentProfit+items[start].profit,items);

        //backtrack
        chosen[start]=0;
    }


}
int main(){
    int n;
    printf("Enter number of items: \n");
    scanf("%d",&n);

    Item items[n];

    for(int i=0;i<n;i++){
        printf("Enter weight of item %d: \n",i+1);
        scanf("%d",&items[i].weight);

        printf("Enter profit of item %d: \n",i+1);
        scanf("%d",&items[i].profit);
    }

    knapsack(0,n,currentWeight,currentProfit,items);
    printf("Maximum Profit: %d \n",maxProfit);

    printf("Chosen Items: \n");
    for(int i=0;i<n;i++){
        if(bestChosen[i]==1){
            printf("Item %d\n",i+1);
        }
    }
    return 0;
    
}