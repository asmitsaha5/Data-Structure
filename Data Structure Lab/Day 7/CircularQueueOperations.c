#include <stdio.h>
#define n 5

int queue[n], front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % n == front)
    {
        printf("Queue overflow.Cannot enqueue.\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % n;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("Deleted %d\n", queue[front]);
        if ((front + 1) % n == (rear + 1) % n)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are: ");
        int i = front;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", queue[rear]);
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n menu \n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}