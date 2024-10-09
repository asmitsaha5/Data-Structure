#include <stdio.h>
#include <stdlib.h>

#define N 30

int *arr;
int *top;
int stackSize;
int M;
          
void initializeTops()
{
    for (int i = 0; i < M; i++)
    {
        top[i] = i * stackSize - 1;
    }
}

void push(int sn, int value)
{
    if (sn >= M)
    {
        printf("Invalid stack number\n");
        return;
    }
    if (top[sn] >= (sn + 1) * stackSize - 1)
    {
        printf("Stack Overflow for Stack %d\n", sn);
    }
    else
    {
        top[sn]++;
        arr[top[sn]] = value;
        printf("Pushed %d in Stack %d\n", value, sn);
    }
}

int pop(int sn)
{
    if (sn >= M)
    {
        printf("Invalid stack number\n");
        return -1;
    }
    if (top[sn] < sn * stackSize)
    {
        printf("Stack Underflow for Stack %d\n", sn);
        return -1;
    }
    else
    {
        int value = arr[top[sn]];
        top[sn]--;
        return value;
    }
}

int main()
{
    printf("Enter the number of stacks (max %d): ", N);
    scanf("%d", &M);

    if (M > N || M <= 0)
    {
        printf("Invalid number of stacks. Exiting.\n");
        return -1;
    }

    stackSize = N / M;
    arr = (int *)malloc(N * sizeof(int));
    top = (int *)malloc(M * sizeof(int));

    initializeTops();

    int choice, sn, value;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter stack number (0 to %d): ", M - 1);
            scanf("%d", &sn);
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(sn, value);
            break;

        case 2:
            printf("Enter stack number (0 to %d): ", M - 1);
            scanf("%d", &sn);
            value = pop(sn);
            if (value != -1)
            {
                printf("Popped %d from Stack %d\n", value, sn);
            }
            break;

        case 3:
            printf("Exiting.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 3);

    free(arr);
    free(top);

    return 0;
}
