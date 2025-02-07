#include <stdio.h>

typedef struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
} Tree;

void createNode(Tree* t){
    t = (Tree*)malloc(sizeof(struct Tree));
    if(!t){
        printf("Memory error\n");
        return NULL;
    }
    t->data = NULL;
    t->left = t->right = NULL;

}

Tree* setLeft(int data){
    Tree* node;
    createNode(&node);
    node->data = data;
    return node;
    
}

Tree* setRight(int data){
    Tree* node;
    createNode(&node);
    node->data = data;
    return node;
}

void insertNumberToTree(Tree * t,int data){
    if(t->data != NULL){
        if(data < t->data)
            insertNumberToTree(t->left, data);
        else if(data > t->data)
            insertNumberToTree(t->right, data);
    }
}
void insertListToTree(List list, Tree* t){
    while(List != NULL){
        insertNumberToTree(t, list->data);
        list = list->next;
    }
}

void preOrderBin(Tree * t){
    printf("%d ", t->data);
    preOrderBin(t->left);
    preOrderBin(t->right);
}

void inOrderBin(Tree * t){
    inOrderBin(t->left);
    printf("%d ", t->data);
    inOrderBin(t->right);
}

void postOrderBin(Tree * t){
    postOrderBin(t->left);
    postOrderBin(t->right);
    printf("%d ", t->data);
}




int main(){

    return 0;
}