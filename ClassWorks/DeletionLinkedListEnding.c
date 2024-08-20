#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n;
    printf("Enter the number of elements to store: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("The number of elements should be greater than 0.\n");
        return 0;
    }

    struct node *newnode, *temp, *head, *ptr;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;

    for (i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return 0;
        }
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }

    ptr = head;
    printf("Elements present in the list:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);
    }

    ptr = head;
    printf("The new linked list after deleting the last node is:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}