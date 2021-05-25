#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Case 1: Deleting the first element
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
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
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

// Case 4: Deleting the element with a given value
struct Node *deleteAtVal(struct Node *head, int val)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != val && q->next != NULL)
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
    head->prev = NULL;
    head->next = second;

    // Link second and third node
    second->data = 17;
    second->prev = head;
    second->next = third;

    // Link third and fourth node
    third->data = 27;
    third->prev = second;
    third->next = fourth;

    // terminate the list at the third element
    fourth->data = 37;
    fourth->prev = third;
    fourth->next = NULL;

    // Linked list before Insertion
    printf("Linked list before Insertion\n");
    linkedListTraversal(head);

    printf("Linked list after Insertion\n");
    head = deleteAtFirst(head); // Deletes first element
    // head = deleteAtIndex(head, 2); // Deletes element at a given index
    // head = deleteAtLast(head); // Deletes the last element
    // head = deleteAtVal(head, 17); // Deletes the element with a given value
    linkedListTraversal(head);
    return 0;
}