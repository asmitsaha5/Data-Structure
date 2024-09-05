#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter the number of rows :");
    scanf("%d", &n);
    printf("Enter the number of columns :");
    scanf("%d", &m);
    int a1[n][m];
    int a2[n][m];
    int ar[n][m];
    printf("Enter array 1 elements :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }
    printf("Enter array 2 elements :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a2[i][j]);
        }
    }
    printf("Resultant Matrix :");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ar[i][j] = a1[i][j] + a2[i][j];
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