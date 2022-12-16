#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;

int NodeHeight(struct Node *p){
    int leftHeight, rightHeight;
    leftHeight=p && p->lchild?p->lchild->height:0;
    rightHeight=p && p->rchild?p->rchild->height:0;

    return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
}

int BalanceFactor(struct Node *p){
    int leftHeight, rightHeight;
    leftHeight=p && p->lchild?p->lchild->height:0;
    rightHeight=p && p->rchild?p->rchild->height:0;

    return leftHeight-rightHeight;
}

struct Node * LLrotation(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
 
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
 
    if(root==p)
        root=pl;
 
    return pl;
}
struct Node * LRrotation(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
 
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
 
    plr->lchild=pl;
    plr->rchild=p;
 
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
 
    if(root==p)
        root=plr;
    return plr;
}
struct Node * RRrotation(struct Node *p){
    return NULL;
}
struct Node * RLrotation(struct Node *p){
   return NULL;
}

void InOrder(struct Node *p){
    if(p){
        InOrder(p->lchild);
        printf("%d ",p->data);
        InOrder(p->rchild);
    }
}

struct Node *RecursiveInsert(struct Node *ptr, int key )
{
        if(ptr==NULL){
            ptr = (struct Node *) malloc(sizeof(struct Node));
            ptr->data = key;
            ptr->height = 1;
            ptr->lchild = ptr->rchild = NULL;
        }
        /*Insertion in left subtree*/
        else if(key < ptr->data) 
            ptr->lchild = RecursiveInsert(ptr->lchild, key);
        /*Insertion in right subtree */
        else if(key > ptr->data) 
            ptr->rchild = RecursiveInsert(ptr->rchild, key);
        /*Updating the height after every insertion*/    
        ptr->height = NodeHeight(ptr);

        /*If the balance factor of the tree is disturbed then resolve it using rotations*/
        if(BalanceFactor(ptr)== 2 && BalanceFactor(ptr->lchild)== 1)
            return LLrotation(ptr);
        else if(BalanceFactor(ptr)== 2 && BalanceFactor(ptr->lchild)== -1)
            return LRrotation(ptr);
        else if(BalanceFactor(ptr)== -2 && BalanceFactor(ptr->lchild)== -1)
            return RRrotation(ptr);
        else if(BalanceFactor(ptr)== -2 && BalanceFactor(ptr->lchild)== 1)
            return RLrotation(ptr);

        return ptr;
}

int main(){
    root = RecursiveInsert(root,10);
    RecursiveInsert(root,5);
    RecursiveInsert(root,2);

    InOrder(root);
    return 0;
}