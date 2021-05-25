#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void linkedListTraversal(struct Node* ptr){
    while (ptr != NULL) 
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }   
}

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Allocate memory for nodes in the linked lis in Heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    // Link first and second node 
    head->data = 7;
    head->next = second;
    
    // Link second and third node 
    second->data = 17;
    second->next = third;
    
    // Link third and fourth node 
    third->data = 27;
    third->next = fourth;
    
    // terminate the list at the third element
    fourth->data = 37;
    fourth->next = NULL;

    linkedListTraversal(head);
    return 0;
}