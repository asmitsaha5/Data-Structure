#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *intersectionnode(struct Node *head1, struct Node *head2)
{
    struct Node *temp;
    while (head2 != NULL)
    {
        temp = head1;
        while (temp != NULL)
        {
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node *createNode(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int main()
{
    struct Node *head1 = createNode(10);
    head1->next = createNode(15);
    head1->next->next = createNode(30);

    struct Node *head2 = createNode(3);
    head2->next = createNode(6);
    head2->next->next = createNode(9);
    head2->next->next->next = head1->next;

    struct Node *intersectionPoint = intersectionnode(head1, head2);

    if (intersectionPoint == NULL)
        printf("No Intersection Point\n");
    else
        printf("Intersection Point: %d\n", intersectionPoint->data);

    return 0;
}
