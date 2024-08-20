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
    printf("Elements present in the Linked List : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    int count = 0, even = 0, odd = 0;
    temp = head;
    while (temp != NULL)
    {
        count++;
        if (count % 2 == 0)
        {
            even++;
        }
        else if (count % 2 == 1)

        {
            odd++;
        }
        temp = temp->next;
    }
    printf("The number of odd string :%d \n", odd);
    printf("The number of even string :%d \n", even);
}