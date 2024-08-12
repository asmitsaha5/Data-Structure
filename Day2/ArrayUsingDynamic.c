#include <stdio.h>
#include <stdlib.h>
int isprime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void sum(int n, int *arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (isprime(arr[i]))
        {
            sum += arr[i];
        }
    }
    printf("Sum of Prime Numbers :%d", sum);
}
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int *));
    printf("Enter the array elements :");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    sum(10, arr);
}