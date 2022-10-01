#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;

int Delete(struct Node *p,int index){
    struct Node *q;
    int x=-1,i;
    // if the index value is invalid return -1
    if(index < 1 || index > countNodes(p))
    return -1;
    // special case if index == 1 
    if(index == 1){
        q = first;
        x = first->data;
        first = first->next;
        // de-allocate the memory
        free(q);
        return x;
    }
    else{
        // make the first pointer on the index and another to the index before
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
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
    Insert(first,0,1);
    Insert(first,1,10);
    Insert(first,2,22);
    Insert(first,3,30);
    Display(first);  // 1 10 22 30
    Delete(first,1);
    Delete(first,2);
    Insert(first,1,20);
    printf("\n");
    Display(first); // 10 20 30
 return 0; 
}