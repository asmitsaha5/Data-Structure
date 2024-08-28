#include <stdio.h>
int main()
{
    int n;
    int m;
    int count = 0;

    printf("Enter The Value of n : ");
    scanf("%d", &n);
    printf("Enter The Value of m : ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count++;
        }
    }
    printf("%d", count);
}