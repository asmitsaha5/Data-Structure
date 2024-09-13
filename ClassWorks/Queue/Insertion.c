#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int n)
{
    if (rear == MAX - 1)
    {
        printf("Overflow! Queue is full.\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = n;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow! Queue is empty.\n");
        return -1;
    }
    else
    {
        int element = queue[front];
        front++;
        return element;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int n, choice, element;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            element = dequeue();
            if (element != -1)
            {
                printf("Dequeued element: %d\n", element);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}