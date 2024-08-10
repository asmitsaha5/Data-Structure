#include <stdio.h>
#include <stdlib.h>
int sum(int n, int arr[n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 1 == 0 && arr[i] % arr[i] == 0)
        {
            sum = sum + arr[i];
        }
    }
}

int main()
{
    int *arr = (int *)malloc(10 * (sizeof(int)));

    printf("Enter the array elements : ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    sum(10, arr);
}