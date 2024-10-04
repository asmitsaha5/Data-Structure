#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(struct Node *stack[], int *top, struct Node *node)
{
    stack[++(*top)] = node;
}

struct Node *pop(struct Node *stack[], int *top)
{
    return stack[(*top)--];
}

struct Node *findIntersection(struct Node *head1, struct Node *head2)
{
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    struct Node *temp = head1;
    while (temp)
    {
        push(stack1, &top1, temp);
        temp = temp->next;
    }

    temp = head2;
    while (temp)
    {
        push(stack2, &top2, temp);
        temp = temp->next;
    }

    struct Node *intersection = NULL;
    while (top1 >= 0 && top2 >= 0)
    {
        if (stack1[top1] == stack2[top2])
        {
            intersection = pop(stack1, &top1);
            pop(stack2, &top2);
        }
        else
        {
            break;
        }
    }

    return intersection;
}

void printList(struct Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *newNode1 = newNode(50);
    struct Node *newNode2 = newNode(40);
    struct Node *newNode3 = newNode(30);
    struct Node *newNode4 = newNode(15);
    struct Node *newNode5 = newNode(10);

    newNode5->next = newNode4;
    newNode4->next = newNode3;
    newNode3->next = newNode2;
    newNode2->next = newNode1;

    struct Node *head1 = newNode5;

    struct Node *newNode6 = newNode(9);
    struct Node *newNode7 = newNode(6);
    struct Node *newNode8 = newNode(3);

    newNode8->next = newNode7;
    newNode7->next = newNode6;
    newNode6->next = newNode3;

    struct Node *head2 = newNode8;

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    struct Node *intersection = findIntersection(head1, head2);

    if (intersection)
    {
        printf("The intersection point is: %d\n", intersection->data);
    }
    else
    {
        printf("No intersection point found.\n");
    }

    return 0;
}
