#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

struct Node *createBST(int pre[],int n){
    struct Stack stk;
    struct Node *t,*p;
    int i=0;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;

    while(i<n){
        if(pre[i] < p->data){
            t= (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(&stk,p);
            p = t;
        }
        else{
            if(pre[i] > p->data && pre[i]<peek(&stk)->data){
                t= (struct Node *)malloc(sizeof(struct Node));
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;   
            }
            else{
                p = pop(&stk);
            }
        }
    }
}