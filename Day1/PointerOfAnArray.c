#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    int arr[n];
    int *add = &arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("The array elements are :");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The Address of the Array is : %d", add);
}