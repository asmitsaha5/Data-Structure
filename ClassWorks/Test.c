#include <stdio.h>

// Structure to represent a sparse matrix
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

    // Input the dimensions of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input matrix elements and store only non-zero elements in the sparse array
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

    // Output the sparse matrix representation
    printf("\nSparse Matrix Representation (row, column, value):\n");
    for (i = 0; i < nonZero; i++)
    {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}
