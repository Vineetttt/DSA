#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;

// Reversal Using Auxillary Array 
void reverseA(struct Node *p){
    struct Node *q=p;
    int *A,i=0;
    // dynamically declaring the array size
    A = (int *)malloc(sizeof(int)*countNodes(p));
    while(q != NULL){
        // copying the linked list data into the array
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    // travese backwards from the array and change the data in linked list 
    while(q != NULL){
        q->data = A[i];
        q= q->next;
        i--;
    }
}

// Reversal Using three pointer approach
void reverseB(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
 {
 r=q;
 q=p;
 p=p->next;
 q->next=r;
 }
 first=q;
}

// Reversal using recursion 

void reverseC(struct Node *q,struct Node *p){
    if(p){
        reverseC(p,p->next);
        p->next = q;
    }
    else{
        first = q;
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
   Insert(first,1,20);
   Insert(first,2,30);
   Insert(first,3,40);
   Insert(first,4,50);
   printf("Original Linked List:");
   Display(first);
   reverseA(first);
   printf("\nAfter Reversing Using Auxillary Array:");
   Display(first);
   reverseB(first);
   printf("\nAfter Reversing Using Three Pointers:");
   Display(first);
   reverseC(NULL,first);
   printf("\nAfter Reversing Using Recursion:");
   Display(first);
 return 0; 
}