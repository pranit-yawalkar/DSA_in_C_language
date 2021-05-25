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
} 

void enqueue(struct queue*q, int val){
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

int dequeue(struct queue* q){
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

int main(){
    struct queue q;
    q.size = 2;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));

    // Enqueue operation
    enqueue(&q, 12);
    enqueue(&q, 112);

    // Dequeue operation
    printf("Element dequeued: %d\n", dequeue(&q));
    printf("Element dequeued: %d\n", dequeue(&q));

    enqueue(&q, 12);  // We are not able to enqueue an element in queue here even though our queue is empty to overcome this we use circular queue
    enqueue(&q, 112);

    if (isEmpty(&q))
        printf("Queue is Empty\n");
    else if (isFull(&q))
        printf("Queue is full\n");
    return 0;
}