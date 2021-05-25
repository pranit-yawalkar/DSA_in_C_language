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

// Case 1
struct Node *insertionAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// Case 2:
struct Node *insertionAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
struct Node *insertionAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    do
    {
        p = p->next;
    } while (p->next != head);

    p->next = ptr;
    ptr->next = head;
    return head;
}

// Case 4
struct Node *insertionAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}
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
    // head = insertionAtFirst(head, 45);
    // head = insertionAtIndex(head, 45, 3);
    // head = insertionAtEnd(head, 45);
    head = insertionAfterNode(head, third, 45);
    linkedListTraversal(head);
    return 0;
}
