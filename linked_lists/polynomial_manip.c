#include<stdio.h>
#include<stdlib.h>
typedef struct Poly{
    int coeff;
    int power;
    struct Poly* next;
}Poly;
Poly* createPoly(int coeff,int power){
    Poly* newPoly=(Poly*)malloc(sizeof(Poly));
    newPoly->coeff=coeff;
    newPoly->power=power;
    newPoly->next=NULL;
    return newPoly;
}
void insertAtEnd(Poly** head,int coeff,int power){
    Poly* newPoly=createPoly(coeff,power);
    if(*head==NULL){
        *head=newPoly;
        return;
    }
    Poly* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newPoly;
}
void display(Poly* head){
    Poly* temp=head;
    while(temp->next!=NULL){
        printf("%dx^%d+",temp->coeff,temp->power);
        temp=temp->next;
    }
    printf("%dx^%d\n",temp->coeff,temp->power);
}
void simplify(Poly** head){
    Poly *ptr1,*ptr2,*prev;
    ptr1=*head;
    while(ptr1!=NULL&&ptr1->next!=NULL){
        prev=ptr1;
        ptr2=ptr1->next;
        while(ptr2!=NULL){
            if(ptr2->power==ptr1->power){
                ptr1->coeff+=ptr2->coeff;
                prev->next=ptr2->next;
                free(ptr2);
                ptr2=prev->next;
            }else{
                prev=ptr2;
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
int main(){
    Poly* head=NULL;
    insertAtEnd(&head,5,3);
    insertAtEnd(&head,3,2);
    insertAtEnd(&head,6,2);
    printf("initial:\n");
    display(head);
    simplify(&head);
    printf("simplified:\n");
    display(head);
}