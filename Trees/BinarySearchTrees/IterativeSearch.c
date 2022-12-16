#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root = NULL;

struct Node *IterativeSearch(int key){
    struct Node *t=root;
    while(t!=NULL){
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL; 
}