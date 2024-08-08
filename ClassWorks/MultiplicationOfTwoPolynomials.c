#include <stdio.h>
int main()
{
    int n;

    printf("Enter the maximum degree : ");
    scanf("%d", &n);

    int a[n];
    int b[n];

    for (int i = 0; i <= n; i++)
    {
        printf("Enter the coefficient for x^%d in the polynomial 1 : ", i);
        scanf("%d", &a[i]);
    }

    for (int j = 0; j <= n; j++)
    {
        printf("Enter the coefficient for x^%d in the polynomial 2 : ", j);
        scanf("%d", &b[j]);
    }

    int result[n + n];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            result[i + j] = a[i] * b[j];
        }
    }
    for (int i = 0; i <= n + n; i++)
    {
        printf("%d", result[i]);
        printf("x^%d + ", i);
    }
    printf("0");
}