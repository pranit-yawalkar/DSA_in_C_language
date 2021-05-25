#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue* q){
    if(q->f == q->r)
        return 1;
    return 0;
}

int isFull(struct queue* q){
    if(q->r == q->size-1)
        return 1;
    return 0;
}

void printQueue(struct queue* q){
    printf("Printing Queue: ");
    for (int i = q->f+1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void enqueueR(struct queue*q, int val){
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

void enqueueL(struct queue* q, int val){
    if (q->f == -1)
        printf("Not possible to enqueue from left\n");
    else{
        q->arr[q->f] = val;
        q->f--;
        printf("Enqueued element: %d\n", val);
    }
    
}

int dequeueF(struct queue* q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("No element to dequeue from queue\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int dequeueR(struct queue* q){
    int val = -1;
    if (isEmpty(q))
        printf("No element to dequeue from queue\n");
    else{
        val = q->arr[q->r];
        q->r--;
    }
    return val;
}

int main(){
    struct queue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));

    // Enqueue operation
    enqueueR(&q, 12);
    enqueueR(&q, 112);
    printQueue(&q);
    // Dequeue operation
    printf("Element dequeued: %d\n", dequeueF(&q));
    printf("Element dequeued: %d\n", dequeueF(&q));
    printQueue(&q);

    enqueueR(&q, 12); 
    enqueueR(&q, 112);

    enqueueL(&q, 5);
    enqueueL(&q, 50);
    printQueue(&q);

    printf("Element dequeued: %d\n", dequeueR(&q));
    printf("Element dequeued: %d\n", dequeueR(&q));
    printQueue(&q);

    printf("Element dequeued: %d\n", dequeueF(&q));
    printf("Element dequeued: %d\n", dequeueF(&q));
    printQueue(&q);

    if (isEmpty(&q))
        printf("Queue is Empty\n");
    else if (isFull(&q))
        printf("Queue is full\n");
    
    return 0;
}