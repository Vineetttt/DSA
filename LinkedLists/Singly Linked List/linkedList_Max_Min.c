#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node * next;
}*first = NULL;

int Max(struct node *p){
 int max=INT_MIN;
 while(p){
    if((p->data)>max)
    max=p->data;
    p=p->next;
    }
 return max;
}

int Min(struct node *p){
 int min=INT_MAX;
 while(p){
    if((p->data)<min)
    min=p->data;
    p=p->next;
    }
 return min;
}

void createLL(int A[] ,int n){
    int i;
    struct node *newNode,*last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next =NULL;
    last=first;
    for(i=1;i<n;i++){
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = A[i];
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}


void displayLL(struct node * ptr){
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    int A[] = {1,-20,34,65,-23,87,100,0};
    createLL(A,8);
    displayLL(first);
    int ansMax = Max(first);
    printf("\nThe maximum element is: %d",ansMax);
    int ansMin = Min(first);
    printf("\nThe minimum element is: %d",ansMin);
}