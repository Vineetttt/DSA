#include <stdio.h>
#include <stdlib.h>
struct Node{
 int data;
 struct Node *next;
}*Head;

int Delete(struct Node *p,int index){
 struct Node *q;
 int i,x;
 if(index <0 || index >Length(Head))
 return -1;
 if(index==1){
    while(p->next!=Head)p=p->next;
    x=Head->data;
    if(Head==p){
        free(Head);
        Head=NULL;
    }
    else{
        p->next=Head->next;
        free(Head);
        Head=p->next;
    }
 }
 else{
    for(i=0;i<index-2;i++)
    p=p->next;
    q=p->next;
    p->next=q->next;
    x=q->data;
    free(q);
 }
 return x;
}
int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}
void create(int A[],int n){
    int i;
    struct Node *t,*last;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
 }
}
void RDisplay(struct Node *h){
    static int flag=0;
    if(h!=Head || flag==0){
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
 }
 flag=0; 
}

int main(){
 int A[]={2,3,4,5,6};
 create(A,5);
 Delete(Head,5);
 Delete(Head,2);
 RDisplay(Head);
 return 0; 
 }