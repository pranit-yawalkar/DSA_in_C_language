#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* n = (struct Node* )malloc(sizeof(struct Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int recursive_search(struct Node* root, int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    else if(key < root->data){
        return recursive_search(root->left, key);
    }
    else{
        return recursive_search(root->right, key);
    }
}

int iterative_search(struct Node* root, int key){
    while(root!=NULL){
        if(root->data == key){
            return 1;
        }
        else if(root->data<key){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return 0;
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

    printf("%d\n", recursive_search(p, 12));
    printf("%d\n", iterative_search(p, 55));

    return 0;
}