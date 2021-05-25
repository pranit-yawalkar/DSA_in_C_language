#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int*arr;
};

int isEmpty(struct queue* q){
    if (q->r == q->f)
        return 1;
    return 0;
}

int isFull(struct queue* q){
    if ((q->r+1)%q->size == q->f)
        return 1;
    return 0;
}

void enqueue(struct queue* q, int val){
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue*q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 5;
    q.f = q.f = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));

    // Enqueue elements
    enqueue(&q, 23);
    enqueue(&q, 25);
    enqueue(&q, 267);
    enqueue(&q, 21);

    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    if(isEmpty(&q))
        printf("Queue is Empty\n");
    if(isFull(&q))
        printf("Queue is Full\n");
    return 0;
}