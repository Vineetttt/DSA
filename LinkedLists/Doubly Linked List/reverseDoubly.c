#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first =NULL;

void reverse(struct Node *p){
    struct Node *temp;
    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next == NULL)
            first = p;
    }
}

void create(int a[],int n){
    struct Node *t,*last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->prev = first->next = NULL;
    last = first;

    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next=t;
        last = t;
    }
}

void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int length(struct Node *p){
    int len = 0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
int main(){
    int A[] = {10,20,30,40,50};
    create(A,5);
    reverse(first);
    Display(first);
}