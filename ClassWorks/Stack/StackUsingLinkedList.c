#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *top = NULL;
    int n, i, value;
    printf("Enter the number of elements to store : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &value);

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        newnode->data = value;
        newnode->next = top;
        top = newnode;
        printf("Pushed %d into the stack \n", value);
    }
    printf("All elements in the stack: \n");
    struct node *curr = top;
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    return 0;
}