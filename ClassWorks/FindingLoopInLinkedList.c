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

    struct node *newnode, *temp, *head, *fast, *slow;
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
    temp->next = head;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            printf("Loop present!");
            return 0;
        }
    }
    printf("No loop found !");
}
