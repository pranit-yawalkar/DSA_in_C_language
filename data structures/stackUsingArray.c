#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};


int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *s, int i)
{
    int arrInd = s->top - i + 1;
    if (arrInd < 0)
    {
        printf("Invalid position for the stack\n");
        return -1;
    }
    else
    {
        return s->arr[arrInd];
    }
}

int stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int stackBottom(struct stack *s)
{
    return s->arr[0];
}
void stackTraversal(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("The stack is empty");
    }
    else{
        for (int i = 0; i <= ptr->top; i++)
        {
            printf("The element at %d is: %d\n", i, ptr->arr[i]);
        }
    }
}
int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before pushing, Full: %d\n", isFull(s));
    printf("Before pushing, Empty: %d\n", isEmpty(s));
    // Pushing elemnets to the stack
    push(s, 12);
    push(s, 13);
    push(s, 14);
    push(s, 15);
    push(s, 16);
    push(s, 17);
    push(s, 18);
    push(s, 19);
    push(s, 21);
    push(s, 22);
    push(s, 22);
    push(s, 22);
    push(s, 22);
    // push(s, 23); // Stack overflow
    printf("After pushing, Full: %d\n", isFull(s));
    printf("After pushing, Empty: %d\n", isEmpty(s));

    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));

    // Printing values from the stack
    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }

    printf("The top most element of this stack %d\n", stackTop(s));
    printf("The bottom most element of this stack %d\n", stackBottom(s));
    stackTraversal(s);
    return 0;
}