#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node *root=NULL;

void Treecreate(){
 struct Node *p,*t;
 int x;
 struct Queue q;
 create(&q,100);
 
 printf("Enter root value:");
 scanf("%d",&x);
 root=(struct Node *)malloc(sizeof(struct Node));
 root->data=x;
 root->lchild=root->rchild=NULL;
 enqueue(&q,root);
 
 while(!isEmpty(q)){
    p=dequeue(&q);
    printf("if left child not present enter -1 \n");
    printf("enter left child of %d: ",p->data);
    scanf("%d",&x);
    if(x!=-1){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->lchild=t;
        enqueue(&q,t);
    }
    printf("if right child not present enter -1 \n");
    printf("enter right child of %d:",p->data);
    scanf("%d",&x);
    if(x!=-1){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->rchild=t;
        enqueue(&q,t);
    }
  }
}
void Preorder(struct Node *p){
 if(p){
    printf("%d ",p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
  }
}

int main(){
 Treecreate();
 Preorder(root);
 return 0; 
}