#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the Linked List
struct Node
{
    char data;
    struct Node *next;
};

// Utility function to create a new node
struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a sublist from start to end is a palindrome
int isPalindrome(struct Node *start, struct Node *end)
{
    char str[100]; // Temporary array to store the characters
    int index = 0;

    // Copy characters from the linked list to the array
    while (start != end->next)
    {
        str[index++] = start->data;
        start = start->next;
    }

    // Check if the array is a palindrome
    for (int i = 0; i < index / 2; i++)
    {
        if (str[i] != str[index - i - 1])
        {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Function to find all palindromic sublists in the linked list
void findAllPalindromes(struct Node *head)
{
    struct Node *start = head;
    struct Node *end;

    // Iterate over all possible starting points
    while (start != NULL)
    {
        end = start;
        // Iterate over all possible ending points
        while (end != NULL)
        {
            if (isPalindrome(start, end))
            {
                struct Node *temp = start;
                // Print the palindrome sublist
                while (temp != end->next)
                {
                    printf("%c ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
            }
            end = end->next;
        }
        start = start->next;
    }
}

// Main function to create the linked list based on user input and test the program
int main()
{
    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("The linked list must have at least one node.\n");
        return 0;
    }

    struct Node *head = NULL;
    struct Node *current = NULL;

    printf("Enter the characters for the linked list:\n");
    for (int i = 0; i < n; i++)
    {
        char ch;
        printf("Node %d: ", i + 1);
        scanf(" %c", &ch);

        struct Node *newNode = createNode(ch);

        if (head == NULL)
        {
            // First node
            head = newNode;
            current = head;
        }
        else
        {
            // Subsequent nodes
            current->next = newNode;
            current = current->next;
        }
    }

    printf("\nAll palindromic sublists in the linked list are:\n");
    findAllPalindromes(head);

    return 0;
}
