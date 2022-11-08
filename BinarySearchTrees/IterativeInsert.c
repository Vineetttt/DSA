#include <stdio.h>
#include <stdlib.h>

// initializing the Node Structure 
struct Node{
    struct Node *lchild;
    int data ;
    struct Node *rchild;
}*root = NULL;

void IterativeInsert(int key){
    struct Node *t = root;
    // r is the following pointer and p is used to create the new node 
    struct Node *r=NULL,*p;
    // is root is NULL then start by creating the very first node 
    if(root == NULL){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t != NULL){
        r = t;
        // if key is less than node data move to the left node 
        if(key < t->data) 
            t = t->lchild;
        // if key is greater than node data move to right node
        else if(key > t->data)
            t = t->rchild;
        // if key is already present do nothing 
        else 
            return;
    }
    // creating the new node
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    // linking the new node with the BST 
    if(key < r->data)
        r->lchild = p;
    else 
        r->rchild = p;
}

void InOrder(struct Node *p){
    if(p){
        InOrder(p->lchild);
        printf("%d ",p->data);
        InOrder(p->rchild);
    }
}

int main(){
    IterativeInsert(10);
    IterativeInsert(5);
    IterativeInsert(20);
    IterativeInsert(8);
    IterativeInsert(30);
    InOrder(root);
    printf("\n");
}