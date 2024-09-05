#include <stdio.h>

int main()
{
    int m, n;
    int i, j, k = 0;
    int count = 0;

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &m, &n);

    int s[m][n];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &s[i][j]);
            if (s[i][j] != 0)
                count++;
        }
    }

    int sparseMatrix[count][3];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[i][j] != 0)
            {
                sparseMatrix[k][0] = s[i][j];
                sparseMatrix[k][1] = i;
                sparseMatrix[k][2] = j;
                k++;
            }
        }
    }

    printf("\nSparse matrix representation (value, row, column):\n");
    for (i = 0; i < count; i++)
    {
        printf("%d %d %d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}
