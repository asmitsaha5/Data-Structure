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
    printf("Enter the elements to store :");
    scanf("%d", &n);

    struct node *newnode, *temp, *head, *ptr;
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
        newnode = NULL;
    }
    ptr = head;
    printf("Elements present in the Linked List : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}