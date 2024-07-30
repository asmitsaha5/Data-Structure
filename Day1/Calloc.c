#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
