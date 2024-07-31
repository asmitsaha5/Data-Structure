#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int values[n];

    int *arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for element %d: ", i);
        scanf("%d", &values[i]);
        arr[i] = &values[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("Value at arr[%d]: %d\n", i, *arr[i]);
        printf("Address stored in arr[%d]: %p\n", i, arr[i]);
    }

    return 0;
}