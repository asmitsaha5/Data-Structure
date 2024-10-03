#include <stdio.h>
#include <stdlib.h>
#define max 10

int arr[max];
int top1 = -1;
int top2 = max;
void push1(int value)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow for Stack 1\n");
    }
    else
    {
        top1++;
        arr[top1] = value;
        printf("Pushed %d in Stack1 :\n", value);
    }
}
void push2(int value)
{
    if (top2 - 1 == top1)
    {
        printf("Stack Overflow for Stack 2\n");
    }
    else
    {
        top2--;
        arr[top2] = value;
        printf("Pushed %d in Stack2 :\n", value);
    }
}

int pop1()
{
    if (top1 == -1)
    {
        printf("Stack Underflow for Stack 1\n");
        return 0;
    }
    else
    {
        int value = arr[top1];
        top1--;
        return value;
    }
}
int pop2()
{
    if (top2 == max)
    {
        printf("Stack Underflow for Stack 2\n");
        return 0;
    }
    else
    {
        int value = arr[top2];
        top2++;
        return value;
    }
}
int main()
{
    int value;

    printf("Enter numbers to push to Stack 1 (enter -1 to stop):\n");
    while (1)
    {
        printf("Enter a value: ");
        scanf("%d", &value);
        if (value == -1)
            break;
        push1(value);
    }

    printf("Enter numbers to push to Stack 2 (enter -1 to stop):\n");
    while (1)
    {
        printf("Enter a value: ");
        scanf("%d", &value);
        if (value == -1)
            break;
        push2(value);
    }

    printf("Popped from Stack 1: %d\n", pop1());
    printf("Popped from Stack 2: %d\n", pop2());

    return 0;
}