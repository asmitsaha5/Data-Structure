#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *tpop = NULL;

int main()
{
    int n, x;
    printf("Enter the number of elements to store: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element to push: ");
        scanf("%d", &x);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Stack Overflow!\n");
            return 0;
        }
        newnode->data = x;
        newnode->next = top;
        top = newnode;
        printf("Pushed %d onto the stack.\n", x);
    }
    if (top == NULL)
    {
        printf("Stack Underflow! No elements to pop.\n");
        return 0;
    }
    struct node *ptemp = top;
    printf("Popped %d from the stack.\n", ptemp->data);
    top = top->next;
    free(ptemp);

    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return 0;
    }
    struct node *temp = top;
    printf("Stack elements:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}
