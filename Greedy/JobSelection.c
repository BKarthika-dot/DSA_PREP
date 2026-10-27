#include<stdio.h>
typedef struct{
    int id,deadline,profit;
}Job;

int main(){
    Job job[100],temp;
    int n,max=0,total=0;
    int slot[100]={0};

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        job[i].id=i+1;
        scanf("%d%d",&job[i].deadline,&job[i].profit);
        if(job[i].deadline>max) max=job[i].deadline;
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(job[i].profit<job[j].profit){
                temp=job[i];
                job[i]=job[j];
                job[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=job[i].deadline;j>=1;j--){
            if(slot[j]==0){
                slot[j]=job[i].id;
                total+=job[i].profit;
                break;
            }
        }
    }
    printf("Selected:\n");
    for(int i=1;i<=max;i++){
        if(slot[i]!=0)printf("J%d ", slot[i]);
    }
    printf("\n");
    printf("Maximum profit= %d\n",total);
}