#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int coeff;
    int pow;
    struct node *next;
};
int main()
{
    int n;
    struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    printf("Enter the highest degree :  ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int coeff;
        printf("Enter the coeffecient for x^%d in polynomial no. 1 : ");
        scanf("%d", &coeff);

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = coeff;
        newnode->pow = i;
        newnode->next = NULL;
    }
}