#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack Overflow!\n");
        return;
    }
    newnode->data = x;
    newnode->next = top;
    top = newnode;
    printf("Pushed %d onto the stack.\n", x);
}

void display()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, value;

    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element to push onto the stack: ");
        scanf("%d", &value);
        push(value);
    }

    display();

    return 0;
}
