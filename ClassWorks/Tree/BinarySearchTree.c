#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, char data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{

    struct Node *root = NULL;

    char name[] = "ASMIT";

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] != ' ')
        {
            root = insert(root, name[i]);
        }
    }
    printf("Inorder traversal of the BST:\n");
    inorderTraversal(root);

    return 0;
}
