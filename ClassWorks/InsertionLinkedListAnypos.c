#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, pos;
    printf("Enter the number of elements to store: ");
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

    printf("Enter the position to insert the new element: ");
    scanf("%d", &pos);

    insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->data = 30;
    insertNode->next = NULL;

    if (pos == 0)
    {
        insertNode->next = head;
        head = insertNode;
    }
    else
    {
        temp = head;
        for (i = 0; i < pos - 1; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
        }
        insertNode->next = temp->next;
        temp->next = insertNode;
    }

    ptr = head;
    printf("Elements stored in the linked list after insertion: \n");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
