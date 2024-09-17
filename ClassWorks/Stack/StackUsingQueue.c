#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter length of the stack ");
    scanf("%d", &n);
    int q1[n];
    int q2[n];
    int front1 = -1;
    int front2 = -1;
    int rear1 = -1;
    int rear2 = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter the element %d", i + 1);
        scanf("%d", &x);
        if (rear2 == n - 1)
        {
            printf("overflow");
        }
        else if (rear2 == -1 && front2 == -1)
        {
            rear2 = rear2 + 1;
            front2 = front2 + 1;
        }
        else
        {
            rear2 = rear2 + 1;
        }
        printf("%d", q)
    }
    return 0;
}
