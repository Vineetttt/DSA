#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void Insert(struct Node *p,int index,int x){
   struct Node *t;
   int i;
   if(index < 0 || index > length(first))
   return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
   if(index == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev =t;
        first = t;
   }
   else{
        for(i=0;i<index-1;i++)
            p=p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next) p->next->prev = t;
        p->next = t;
   }
}

int length(struct Node *p){
    int count = 0;
    while(p){
        count++;
        p= p->next;
    }
    return count;
}

void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
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

int main(){
    int a[] = {40};
    create(a,0);
    Insert(first,0,10);
    Insert(first,1,20);
    Insert(first,2,30);
    Display(first);
}