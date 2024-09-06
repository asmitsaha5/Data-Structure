#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

int main()
{
    int n;
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    printf("Enter the highest degree: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        int coeff;
        printf("Enter the coefficient for x^%d in polynomial 1: ", i);
        scanf("%d", &coeff);

        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->coeff = coeff;
        new_node->pow = i;
        new_node->next = NULL;

        if (poly1 == NULL)
        {
            poly1 = new_node;
        }
        else
        {
            struct Node *temp = poly1;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        int coeff;
        printf("Enter the coefficient for x^%d in polynomial 2: ", i);
        scanf("%d", &coeff);

        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->coeff = coeff;
        new_node->pow = i;
        new_node->next = NULL;

        if (poly2 == NULL)
        {
            poly2 = new_node;
        }
        else
        {
            struct Node *temp = poly2;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
    }

    struct Node *p1 = poly1, *p2;

    while (p1 != NULL)
    {
        p2 = poly2;
        while (p2 != NULL)
        {
            int coeff = p1->coeff * p2->coeff;
            int pow = p1->pow + p2->pow;

            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->coeff = coeff;
            new_node->pow = pow;
            new_node->next = NULL;

            if (result == NULL)
            {
                result = new_node;
            }
            else
            {
                struct Node *temp = result;
                struct Node *prev = NULL;

                while (temp != NULL && temp->pow > pow)
                {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp != NULL && temp->pow == pow)
                {
                    temp->coeff += coeff;
                    free(new_node);
                }
                else
                {

                    if (prev == NULL)
                    {
                        new_node->next = result;
                        result = new_node;
                    }
                    else
                    {
                        new_node->next = temp;
                        prev->next = new_node;
                    }
                }
            }

            p2 = p2->next;
        }
        p1 = p1->next;
    }
    printf("The product of the two polynomials is: ");
    struct Node *temp = result;
    while (temp != NULL)
    {
        printf("%d", temp->coeff);
        if (temp->pow != 0)
            printf("x^%d", temp->pow);
        if (temp->next != NULL && temp->next->coeff >= 0)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}