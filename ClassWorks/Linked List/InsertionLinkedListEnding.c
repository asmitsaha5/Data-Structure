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
    printf("Enter the elements to store: ");
    scanf("%d", &n);

    struct node *newnode, *temp, *head, *ptr, *insertNode;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("No memory");
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
            return 0;
        }
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }

    ptr = head;
    printf("Elements stored in the linked list: ");
    for (i = 0; i < n; i++)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }

    insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->data = 30;
    insertNode->next = NULL;
    temp->next = insertNode;

    ptr = head;
    printf("Elements stored in the new linked list: ");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
