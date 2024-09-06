#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    printf("Popped %d from the stack.\n", temp->data);
    free(temp);
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

int main()
{
    int n, value, choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        // printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push onto the stack: ");
            scanf("%d", &value);
            push(value);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}