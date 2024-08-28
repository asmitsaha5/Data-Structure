#include <stdio.h>
int main()
{
    int n, pos;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element  : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to be deleted (from 1 - %d) : ", n);
    scanf("%d", &pos);

    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("The resultant array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}