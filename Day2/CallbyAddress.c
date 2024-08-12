#include <stdio.h>
int compare(int *a, int *b)
{
    if (*a > *b)
    {
        printf("A is greater than B");
    }
    else if (*a == *b)
    {
        printf("A is Equal to B");
    }
    else
    {
        printf("A is less than B");
    }
}
int main()
{
    int x, y;
    printf("Enter the value for A :");
    scanf("%d", &x);

    printf("Enter the value for B : ");
    scanf("%d", &y);

    compare(&x, &y);
}