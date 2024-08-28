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
    int n, pos;
    printf("Enter the number of elements to store: ");
    scanf("%d", &n);

    struct node *newnode, *temp, *head, *tail, *ptr, *insertnode;
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
    printf("Enter the position for insertion : ");
    scanf("%d", &pos);
    insertnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the Value for insertion :");
    scanf("%d", insertnode->data);
    if (pos == 1)
    {

        insertnode->next = head;
        insertnode->prev = NULL;
        head->prev = insertnode;
        head = insertnode;
    }
    else if (pos == n + 1)
    {
        insertnode->next = NULL;
        insertnode->prev = tail;
        tail->next = insertnode;
        tail = insertnode;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        insertnode->next = temp->next;
        insertnode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = insertnode;
        }
        temp->next = insertnode;
    }

    printf("Elements present in the Linked List after insertion (Forward Traversal): \n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}