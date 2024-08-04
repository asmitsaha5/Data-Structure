#include <stdio.h>
int main()
{
    int n;
    int count = 0;

    printf("Enter The Value of n : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count++;
        }
    }
    printf("%d", count);
}