#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

char pop(struct stack *ptr)
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

char peek(struct stack *s, int i)
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

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}

char stackBottom(struct stack *s)
{
    return s->arr[0];
}

int precedence(char ch){
    if (ch == '*' || ch == '/') 
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

char *infixToPostfix(char *infix){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i = 0, j = 0;
    while (infix[i]!='\0'){
        if (!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    char *infix = "x-y/z-k*d";
    // printf("Enter the infix you want to convert: ");
    // scanf("%c", infix);
    printf("Postfix is %s", infixToPostfix(infix));
}