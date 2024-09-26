#include <stdio.h>
#define SIZE 5

int main()
{
    int queue[SIZE];
    int front = -1, rear = -1;
    int n, value;

    printf("Enter the number of operations you want to perform: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char operation;

        printf("\nEnter 'e' to enqueue or 'd' to dequeue: ");
        scanf(" %c", &operation);

        if (operation == 'e')
        {

            if (rear == SIZE - 1)
            {
                printf("Queue Overflow. Cannot enqueue.\n");
            }
            else
            {
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (front == -1)
                    front = 0;
                rear++;
                queue[rear] = value;
                printf("Inserted %d\n", value);
            }
        }
        else if (operation == 'd')
        {

            if (front == -1 || front > rear)
            {
                printf("Queue Underflow. Cannot dequeue.\n");
            }
            else
            {
                printf("Deleted %d\n", queue[front]);
                front++;
                if (front > rear)
                {
                    front = rear = -1;
                }
            }
        }
        else
        {
            printf("Invalid operation. Please enter 'e' for enqueue or 'd' for dequeue.\n");
        }
    }

    return 0;
}
