#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *createNode(int d, int p)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

void enqueue(struct Node **head, int d, int p)
{
    struct Node *newNode = createNode(d, p);

    if (*head == NULL || (*head)->priority < p)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {

        struct Node *temp = *head;
        while (temp->next != NULL && temp->next->priority >= p)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted element %d with priority %d.\n", d, p);
}

int dequeue(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Priority queue is empty!\n");
        return -1;
    }

    struct Node *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);

    return data;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Priority queue is empty!\n");
        return;
    }

    printf("Priority Queue: ");
    while (head != NULL)
    {
        printf("[Data: %d, Priority: %d] -> ", head->data, head->priority);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *pq = NULL;
    int choice, data, priority;

    do
    {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            printf("Enter the priority of the data: ");
            scanf("%d", &priority);
            enqueue(&pq, data, priority);
            break;

        case 2:

            data = dequeue(&pq);
            if (data != -1)
            {
                printf("Dequeued element: %d\n", data);
            }
            break;

        case 3:

            display(pq);
            break;

        case 4:

            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
