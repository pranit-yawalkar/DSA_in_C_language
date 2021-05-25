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
}

void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int  isBST(struct Node* root){
    static struct Node* prev = NULL;
    if(root==NULL){
        return 1;        
    }
    if(!isBST(root->left)){
        return 0;
    }
    if(prev!=NULL && root->data < prev->data){
        return 0;
    }
    prev = root;
    return isBST(root->right);
}

int main(){
    // struct Node* p = createNode(12);
    // struct Node* p1 = createNode(14);
    // struct Node* p2 = createNode(9);
    // struct Node* p3 = createNode(6);
    // struct Node* p4 = createNode(10);
    // struct Node* p5 = createNode(13);

    // A BST
    struct Node* p = createNode(9);
    struct Node* p1 = createNode(4);
    struct Node* p2 = createNode(10);
    struct Node* p3 = createNode(2);
    struct Node* p4 = createNode(6);
    struct Node* p5 = createNode(5);
    struct Node* p6 = createNode(7);
    struct Node* p7 = createNode(12);
    struct Node* p8 = createNode(11);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p4->left = p5;
    p4->right = p6;
    p2->right = p7;
    p7->left = p8;

    inOrder(p);
    printf("\n");
    printf("%d", isBST(p));
    return 0;
}