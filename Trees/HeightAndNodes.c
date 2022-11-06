#include <stdio.h>
#include <stdlib.h>

struct Node{
 struct Node *lchild;
 int data;
 struct Node *rchild;
};

struct Node *root = NULL;

int countNodes(struct Node *root){
    if(root){
        return countNodes(root->lchild)+countNodes(root->rchild)+ 1;
    }
    return 0;
}

int height(struct Node *root){
    int x = 0 , y = 0;
    if(root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if(x>y) return x+1;
    else return y+1;
}
