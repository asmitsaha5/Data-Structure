#include <stdio.h>
#include <stdlib.h>

// Node structure for the 2D linked list
typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *down;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

// Function to convert a 2D array to a 2D linked list
Node *convertTo2DLinkedList(int rows, int cols, int arr[rows][cols])
{
    if (rows == 0 || cols == 0)
        return NULL;

    // Create the head of the linked list
    Node *head = createNode(arr[0][0]);
    Node *rowHead = head;
    Node *prevRowHead = NULL;

    // Create the linked list row by row
    for (int i = 0; i < rows; i++)
    {
        Node *current = rowHead;
        for (int j = 1; j < cols; j++)
        {
            current->right = createNode(arr[i][j]);
            current = current->right;
        }

        // Link down from the previous row
        if (prevRowHead != NULL)
        {
            Node *above = prevRowHead;
            Node *below = rowHead;
            while (above != NULL && below != NULL)
            {
                above->down = below;
                above = above->right;
                below = below->right;
            }
        }

        // Move to the next row
        prevRowHead = rowHead;
        if (i + 1 < rows)
        {
            rowHead = createNode(arr[i + 1][0]);
        }
    }

    return head;
}

// Function to print data from the 2D linked list at (i, j)
void printData(Node *head, int i, int j)
{
    Node *currentRow = head;
    for (int row = 0; row < i; row++)
    {
        if (currentRow == NULL)
        {
            printf("Invalid row index\n");
            return;
        }
        currentRow = currentRow->down;
    }

    Node *currentCol = currentRow;
    for (int col = 0; col < j; col++)
    {
        if (currentCol == NULL)
        {
            printf("Invalid column index\n");
            return;
        }
        currentCol = currentCol->right;
    }

    if (currentCol != NULL)
    {
        printf("Data at (%d, %d): %d\n", i, j, currentCol->data);
    }
    else
    {
        printf("Invalid indices\n");
    }
}

// Main function for testing
int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Node *head = convertTo2DLinkedList(3, 3, arr);

    printData(head, 1, 1); // Should print 5
    printData(head, 2, 2); // Should print 9
    printData(head, 0, 0); // Should print 1

    return 0;
}
