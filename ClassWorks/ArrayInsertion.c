#include <stdio.h>
int main()
{
    int n, pos, x;

    printf("Enter number of elements in the array : ");
    scanf("%d", &n);

    int a[n + 1];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element in position %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("The array elements are : ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter the position where to enter the value :");
    scanf("%d", &pos);

    for (int i = n; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }
    printf("Enter the value :");
    scanf("%d", &x);

    a[pos - 1] = x;

    printf("The new Array elements are : ");

    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}