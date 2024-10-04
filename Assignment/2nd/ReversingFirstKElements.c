#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
int stack[N];
int top = -1;
void enqueue(int element)
{
    if (front == (rear + 1) % N)
    {
        printf("Overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = element;
    }
}

int dequeue()
{
    int x;
    if (front == -1)
    {
        printf("Underflow");
    }
    else if (front == rear)
    {
        x = queue[front];
        front = -1;
        rear = -1;
    }
    else
    {
        x = queue[front];
        front = (front + 1) % N;
    }
    return x;
}

void push(int x)
{
    if (top == N - 1)
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
void reverse(int k)
{
    int value;
    while (front < k)
    {
        value = dequeue();
        push(value);
    }
    for (int i = 0; i < k; i++)
    {
        value = pop();
        enqueue(value);
    }
    for (int i = k; i < N; i++)
    {
        value = dequeue();
        enqueue(value);
    }
}
int main()
{
    int k = 3;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    reverse(k);
    for (int i = 0; i < N; i++)
    {
        printf("%d", queue[i]);
    }
}