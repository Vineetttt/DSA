#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node * next;
}*first = NULL;

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

void SortedInsert(struct node *p,int x)
{
 struct node *t,*q=NULL;
 
 t=(struct Node*)malloc(sizeof(struct node));
 t->data=x;
 t->next=NULL;
 
 if(first==NULL)
 first=t;
 else
 {
 while(p && p->data<x)
 {
 q=p;
 p=p->next;
 }
 if(p==first)
 {
 t->next=first;
 first=t;
 }
 else
 {
 t->next=q->next;
 q->next=t;
 }
 }
 
}

void displayLL(struct node * ptr){
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    int A[] = {10,20,30,40,50};
    createLL(A,5);
    printf("Original Linked List: \n");
    displayLL(first);
    printf("\nLinked List after insertion: \n");
    SortedInsert(first,45);
    SortedInsert(first,0);
    SortedInsert(first,60);
    displayLL(first);
}