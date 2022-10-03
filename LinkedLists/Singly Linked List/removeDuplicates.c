#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;

void removeDuplicates(struct Node *p){
    struct Node *q = p->next;
    while(q != NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q=p->next;
        }
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;
    if(index < 0 || index > countNodes(p))
    return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
 
    if(index == 0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
int countNodes(struct Node *p){
    int count = 0;
    while(p){
        count++;
        p= p->next;
    }
    return count;
}
int main(){
   Insert(first,0,10);
   Insert(first,1,10);
   Insert(first,2,20);
   Insert(first,3,20);
   Insert(first,4,20);
   Insert(first,5,30);
   Insert(first,6,40);
   Insert(first,7,40);
   Insert(first,8,50);
   printf("Original Linked List:");
   Display(first);
   removeDuplicates(first);
   printf("\nAfter Removing Duplicates:");
   Display(first);
 return 0; 
}