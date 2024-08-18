#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next; // creating a stucture to store element values and address of the next node
};
int main()
{
    int n;
    printf("Enter the elements to store :"); // getting user input of how many elements to store
    scanf("%d", &n);

    struct node *newnode, *temp, *head, *ptr;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node)); // First element of the list
    if (head == NULL)
    {
        printf("No memory"); // if the head value is 0
        return 0;
    }
    scanf("%d", &head->data); // getting head data by user input
    head->next = NULL;
    temp = head;
    for (i = 1; i < n; i++) // for loop to iterate through all user input
    {
        newnode = (struct node *)malloc(sizeof(struct node)); // new node for a new node
        if (newnode == NULL)
        {
            return 0; // if the value of new node is 0
        }
        scanf("%d", &newnode->data); //
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
        printf("Address of the node %d : %d \n", i + 1, ptr);
        ptr = ptr->next;
    }
}