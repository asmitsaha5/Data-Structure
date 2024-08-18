#include <stdio.h>

struct SparseMatrix
{
    int row;
    int col;
    int value;
};

int main()
{
    int rows, cols, i, j, element, nonZero = 0;
    struct SparseMatrix sparse[100];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &element);
            if (element != 0)
            {
                sparse[nonZero].row = i;
                sparse[nonZero].col = j;
                sparse[nonZero].value = element;
                nonZero++;
            }
        }
    }

    printf("\nSparse Matrix  (value, row, column):\n");
    for (i = 0; i < nonZero; i++)
    {
        printf("%d\t%d\t%d\n", sparse[i].value, sparse[i].row, sparse[i].col);
    }

    return 0;
}
