#include <stdio.h>
int swap(int *a, int *b)
{
    int s;
    s = *a;
    *a = *b;
    *b = s;
}

int main()
{
    int x, y;
    printf("Enter a value for x : ");
    scanf("%d", &x);
    printf("Enter a value for y : ");
    scanf("%d", &y);

    swap(&x, &y);

    printf("After Swaping x = %d , y = %d \n", x, y);
}