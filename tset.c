#include <stdio.h>

// Function to be pointed to
int add(int a, int b)
{
    return a + b;
}

int main()
{
    // Define a function pointer for a function returning int and taking two int parameters
    int (*func_ptr)(int, int) = add;

    // Call the function using the pointer
    int result = (*func_ptr)(5, 3); // Result: 8
    printf("Sum: %d\n", result);

    return 0;
}
