#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
}

void insert(struct Node* root, int key){
    struct Node* prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data == key){
            printf("Cannot insert %d, already present", key);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct Node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(){
    struct Node* head = NULL;
    struct Node* p = createNode(50);
    struct Node* p1 = createNode(40);
    struct Node* p2 = createNode(60);
    struct Node* p3 = createNode(35);
    struct Node* p4 = createNode(45);
    struct Node* p5 = createNode(55);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;

    inOrder(p);
    insert(p, 46);
    insert(p, 22);
    inOrder(p);

    return 0;
}