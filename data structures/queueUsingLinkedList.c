#include<stdio.h>
#include<stdlib.h>

// Global pointers 
// Either we can use global variables or we can return f in enqueue function
struct Node* f = NULL;
struct Node* r = NULL;

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(){
    if (f == NULL)
        return 1;
    return 0;
}

int isFull(struct Node* n){
    if (n == NULL)  
        return 1;
    return 0;
}

void enqueue(int val){
    struct Node* n = (struct Node *)malloc(sizeof(struct Node));;
    if (isFull(n))
        printf("Queue is full\n");
    else{
        n->data = val;
        n->next = NULL;
        if (f == NULL)
            f = r = n;
        else{
            r->next = n;
            r = n;
        }
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(){
    int val = -1;
    struct Node* ptr = f;
    if (isEmpty(f))
        printf("Queue is Empty\n");
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}


int main(){
    enqueue(5);
    enqueue(25);
    enqueue(55);
    enqueue(56);
    enqueue(23);
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}