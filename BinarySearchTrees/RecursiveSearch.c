#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data ;
    struct Node *rchild;
}*root = NULL;

struct Node *RecursiveSearch(struct Node *ptr, int key){
    if(ptr==NULL){
        printf("key not found\n");
        return NULL;
    }
    else if(key < ptr->data)/*search in left subtree*/
        return search(ptr->lchild, key);
    else if(key > ptr->data)/*search in right subtree*/
        return search(ptr->rchild, key);
    else /*skey found*/
        return ptr;
}

/*int main(){
    struct Node *ptr;
    ptr = RecursiveSearch(root,34);
    if(ptr!=NULL)
        printf("\nKey found\n");
    return 0;
}*/