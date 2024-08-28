#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{
    int n;
    printf("Enter the number of elements to store: ");
    scanf("%d", &n);

    struct node *newnode, *temp, *head, *tail, *ptr;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("No memory allocated.\n");
        return 0;
    }

    printf("Enter element 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    head->prev = NULL;
    tail = head;

    for (i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed.\n");
            return 0;
        }

        printf("Enter element %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }

    printf("Elements present in the Linked List (Forward Traversal): \n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    printf("Elements present in the Linked List (Reverse Traversal): \n");
    temp = tail;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");

    return 0;
}
