#include <stdio.h>
#define n 5
int q1[n];
int front1 = -1;
int rear1 = -1;
int q2[n];
int front2 = -1;
int rear2 = -1;
int stack[n];
int top = -1;

void enqueue_q1(int x)
{
    if (rear1 == n - 1)
    {
        printf("Overflow in q1\n");
    }
    else if (front1 == -1 && rear1 == -1)
    {
        front1 = 0;
        rear1 = 0;
    }
    else
    {
        rear1 = rear1 + 1;
    }
    q1[rear1] = x;
}

void enqueue_q2(int x)
{
    if (rear2 == (n - 1))
    {
        printf("Overflow in q2\n");
    }
    else if (front2 == -1 && rear2 == -1)
    {
        front2 = 0;
        rear2 = 0;
    }
    else
    {
        rear2 = rear2 + 1;
    }
    q2[rear2] = x;
}

int dequeue_q1()
{
    int x = -1;
    if (front1 == -1)
    {
        printf("Underflow in q1\n");
    }
    else if (front1 == rear1)
    {
        x = q1[front1];
        front1 = -1;
        rear1 = -1;
    }
    else
    {
        x = q1[front1];
        front1++;
    }
    return x;
}

void push(int x)
{
    if (top == n - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

int pop()
{
    int x = -1;
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = stack[top];
        top = top - 1;
    }
    return x;
}

int cansort()
{
    int expected = 1;

    while (front1 != -1 || top != -1)
    {
        if (front1 != -1 && q1[front1] == expected)
        {
            int val = dequeue_q1();
            printf("Enqueueing %d to q2\n", val);
            enqueue_q2(val);
            expected++;
        }
        else if (top != -1 && stack[top] == expected)
        {
            int val = pop();
            printf("Enqueueing %d to q2 from stack\n", val);
            enqueue_q2(val);
            expected++;
        }
        else if (front1 != -1)
        {
            int val = dequeue_q1();
            printf("Pushing %d to stack\n", val);
            push(val);
        }
        else
        {
            break;
        }
    }

    if (expected == n + 1)
    {
        printf("Sorting is possible!\n");
        return 1;
    }
    else
    {
        printf("Sorting is not possible\n");
        return 0;
    }
}

int main()
{

    enqueue_q1(2);
    enqueue_q1(3);
    enqueue_q1(1);
    enqueue_q1(5);
    enqueue_q1(6);

    cansort();

    return 0;
}
