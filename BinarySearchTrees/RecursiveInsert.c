#include <stdio.h>
#include <stdlib.h>

// initializing the Node Structure 
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *RecursiveInsert(struct Node *ptr, int key )
{
        if(ptr==NULL){
            ptr = (struct Node *) malloc(sizeof(struct Node));
            ptr->data = key;
            ptr->lchild = ptr->rchild = NULL;
        }
        /*Insertion in left subtree*/
        else if(key < ptr->data) 
            ptr->lchild = RecursiveInsert(ptr->lchild, key);
        /*Insertion in right subtree */
        else if(key > ptr->data) 
            ptr->rchild = RecursiveInsert(ptr->rchild, key);
        /*If duplicates found*/
        else
            printf("Cannot have duplicates");
        return ptr;
}
void inorder(struct Node *ptr){
    if(ptr == NULL )
        return;
    inorder(ptr->lchild);
    printf("%d  ",ptr->data);
    inorder(ptr->rchild);
}
int main(){
    struct Node *root = NULL;
    root =  RecursiveInsert(root,10);
    root =  RecursiveInsert(root,5);
    root =  RecursiveInsert(root,20);
    root =  RecursiveInsert(root,8);
    root =  RecursiveInsert(root,30);
    inorder(root);
    printf("\n");
}