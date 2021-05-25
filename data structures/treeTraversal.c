#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* n;
    n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrderTraversal(struct Node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inOrderTraversal(struct Node* root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main(){
    struct Node* p = createNode(11);
    struct Node* p2 = createNode(12);
    struct Node* p3 = createNode(43);
    struct Node* p4 = createNode(22);
    struct Node* p5 = createNode(23);

    p->left = p2;
    p->right = p3;
    p2->left = p4;
    p2->right = p5;
    
    preOrderTraversal(p);    
    printf("\n");
    postOrderTraversal(p);
    printf("\n");
    inOrderTraversal(p);

    return 0;
}