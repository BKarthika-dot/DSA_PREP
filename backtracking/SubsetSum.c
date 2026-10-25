//Given a set of n positive integers and a target sum find every subset whose sum adds exactly to target
#include<stdio.h>
int a[100];
int x[100];  //records which elements we have selected for the subset
int n,target;

void subsetSum(int index,int sum){

    //base case
    if(sum==target){
        printf("{ ");
        for(int i=0;i<index;i++){
            if(x[i]==1){
                printf("%d ",a[i]);
            }
        }
        printf("}\n");
        return;
    }

    if(index==n || sum>target) return;

    //make choice
    x[index]=1;
    subsetSum(index+1,sum+a[index]);

    //remove choice
    x[index]=0;
    subsetSum(index+1,sum);
}
int main(){
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d:\n", target);
    subsetSum(0, 0);

    return 0;
}
