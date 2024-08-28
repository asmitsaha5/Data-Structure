#include <stdio.h>
int main()
{
    int n;

    printf("Enter the highest degree :");
    scanf("%d", &n);

    int A[n];
    int B[n];

    for (int i = 0; i <= n; i++)
    {
        printf("Enter the coefficient for x^%d in the polynomial 1 : ", i);
        scanf("%d", &A[i]);
    }

    for (int j = 0; j <= n; j++)
    {
        printf("Enter the coefficient for x^%d in the polynomial 2 : ", j);
        scanf("%d", &B[j]);
    }
    int result[n];

    for (int i = 0; i <= n; i++)
    {
        result[i] = A[i] + B[i];
    }

    printf("The sum of the two polynomials is : \n");
    for (int i = n; i >= 0; i--)
    {
        printf("%d", result[i]);
        printf("x^%d + ", i);
    }
    printf("0");
}