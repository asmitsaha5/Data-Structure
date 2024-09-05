#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
int main()
{
    int n;
    printf("Enter the number of element to store :");
    scanf("%d", &n);
    struct Node *head, *tail, *temp, *ptr, *del;
    head = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &head->data);
    head->next = NULL;
    head->prev = NULL;
    tail = head;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        if (newnode == NULL)
        {
            return 0;
        }
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
        tail = temp;
    }

    ptr = head;
    printf("Elements present in the Linked List :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element of node %d : %d \n", i + 1, ptr->data);
        ptr = ptr->next;
    }
    int pos;
    printf("Enter the position to delete :");
    scanf("%d", &pos);
    temp = tail;
    for (int i = n; i > pos + 1; i--)
    {
        printf("%d", temp->data);
        temp = temp->prev;
    }
    del = temp->prev;
    temp->prev = temp->prev->prev;
    temp->prev->next = temp;
    free(del);
    ptr = head;
    printf("Elements of the Linked List after deletion at %d :\n", pos);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
