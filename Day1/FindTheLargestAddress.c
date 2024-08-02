#include <stdio.h>
#include <stdlib.h>

int *MaxAdd(int *arr, int n)
{
    int *add = arr;
    for (int i = 1; i < n; i++)
    {
        if (*(arr + i) > *add)
        {
            add = arr + i;
        }
    }
    return add;
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *add = MaxAdd(arr, n);

    {
        printf("The maximum element is %d\n", *add);
        printf("The address of the maximum element is %p\n", add);
    }
    return 0;
}
