#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
// Case 1: Deleting the first element
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    free(head);
    head = p->next;
    return head;
};

// Case 2: Deleting the element at a given index
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
};

// Case 3: Deleting the Last element
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);
    return head;
};

// Case 4: Deleting the element with a given value
struct Node *deleteAtVal(struct Node *head, int val)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != val && q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == val)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Value not found\n");
    }
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked lis in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

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
    fourth->next = head;

    // Circular linked list before insertion
    printf("Circular Linked List before Insertion\n");
    linkedListTraversal(head);

    // Circular linked list after insertion
    printf("Circular Linked List after Insertion\n");
    // head = deleteAtFirst(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteAtLast(head);
    head = deleteAtVal(head, 27);
    linkedListTraversal(head);
    return 0;
}