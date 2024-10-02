#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

void initStack(struct stack **s)
{
    *s = NULL;
}

int isEmpty(struct stack *s)
{
    return (s == NULL);
}

void push(struct stack **s, int x)
{
    struct stack *p = (struct stack *)malloc(sizeof(*p));
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    p->data = x;
    p->next = *s;
    *s = p;
}

int pop(struct stack **s)
{
    int x = (*s)->data;
    struct stack *temp = *s;
    (*s) = (*s)->next;
    free(temp);
    return x;
}

int top(struct stack *s)
{
    return s->data;
}

void sortedInsert(struct stack **s, int x)
{
    if (isEmpty(*s) || x > top(*s))
    {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}

void sortStack(struct stack **s)
{
    if (!isEmpty(*s))
    {
        int x = pop(s);
        sortStack(s);
        sortedInsert(s, x);
    }
}

void printStack(struct stack *s)
{
    while (s)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

int main(void)
{
    struct stack *top;
    int n, x;

    initStack(&top);

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(&top, x);
    }

    printf("Stack elements before sorting:\n");
    printStack(top);

    sortStack(&top);
    printf("\nStack elements after sorting:\n");
    printStack(top);

    return 0;
}
