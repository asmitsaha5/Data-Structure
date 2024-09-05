#include <stdio.h>
int main()
{
    int m, n, p;
    printf("Enter the number of rows in a1 :");
    scanf("%d", &m);
    printf("Enter the number of columns in a1 :");
    scanf("%d", &p);
    printf("Enter the number of rows in a2 :");
    scanf("%d", &p);
    printf("Enter the number of columns in a2 :");
    scanf("%d", &n);
    int a1[m][p];
    int a2[p][n];
    int ar[m][n];
    printf("Enter array 1 elements :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }
    printf("Enter array 2 elements :\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a2[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int result = 0;
            for (int k = 0; k < p; k++)
            {
                result = result + (a1[i][k] * a2[k][j]);
            }
            ar[i][j] = result;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d  ", ar[i][j]);
        }
        printf("\n");
    }
}