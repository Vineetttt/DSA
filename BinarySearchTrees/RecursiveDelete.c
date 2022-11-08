#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

int Height(struct Node *p){
    int x, y;
    if(p == NULL) return 0;
    x= Height(p->lchild);
    y= Height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node *InOrderPredecessor(struct Node *p){
    while(p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct Node *InOrderSuccessor(struct Node *p){
    while(p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct Node *RecursiveDelete(struct Node *p,int key){
    struct Node *q;
    if(p == NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild = RecursiveDelete(p->lchild,key);
    else if(key > p->data)
        p->rchild = RecursiveDelete(p->rchild,key);
    else{
        /* Once we find the key to be deleted, we find the Height of the left and the right Subtree 
        and depending on the height we decide the node which will take place of the node to be deleted */
        if(Height(p->lchild) > Height(p->rchild)){
            q = InOrderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = RecursiveDelete(p->lchild,q->data);
        }
        else{
            q = InOrderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = RecursiveDelete(p->rchild,q->data);
        }
    }
    return p;
}