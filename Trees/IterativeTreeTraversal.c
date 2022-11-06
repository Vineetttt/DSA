#include "Stack.h"

struct Node
{
 struct Node *lchild;
 int data;
 struct Node *rchild;
};

void IPreorder(struct Node *p){
 struct Stack stk;
 Stackcreate(&stk,100);
 
 while(p || !isEmptyStack(stk)){
    if(p){
        printf("%d ",p->data);
        push(&stk,p);
        p=p->lchild;
    }
    else{
        p=pop(&stk);
        p=p->rchild;
    }
  }
}

void IInorder(struct Node *p){
 struct Stack stk;
 Stackcreate(&stk,100);
 
 while(p || !isEmptyStack(stk)){
    if(p){
        push(&stk,p);
        p=p->lchild;
    }
    else{
        p=pop(&stk);
        printf("%d ",p->data);
        p=p->rchild;
    }
  }
}