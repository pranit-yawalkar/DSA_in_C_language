#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//isEmpty function

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

// isFull function

int isFull(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

// Push Operation

struct Node *push(struct Node *top, int data)
{
    if (isFull(top))
    {
        printf("Stack Overflow");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}

//Pop operation

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow");
    }
    else
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

// peek operation
int peek(int pos){
    struct Node *ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}

// stackTop operation
int stackTop(struct Node *top){
    return top->data;
}
// stackBottom operation
int stackBottom(struct Node *top){
    struct Node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}


int main()
{
    top = push(top, 45);
    top = push(top, 43);
    top = push(top, 24);
    top = push(top, 67);
    top = push(top, 65);
    top = push(top, 100);
    top = push(top, 23);

    linkedListTraversal(top);

    int element = pop(top);
    printf("Popped element is: %d\n", element);
    linkedListTraversal(top);
    printf("The element at position %d is %d\n", 4, peek(4));
    printf("The top most element of this stack %d\n", stackTop(top));
    printf("The bottom most element of this stack %d\n", stackBottom(top));
    return 0;
}
