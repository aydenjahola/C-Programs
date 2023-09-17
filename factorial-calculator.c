#include <stdio.h>

// Function to calculate the factorial of a number recursively
int factorial(int n) {
    if (n == 0)
        return 1; // Base case: Factorial of 0 is 1
    return n * factorial(n - 1); // Recursive case: Multiply n by factorial of (n-1)
}

int main() {
    int num = 5; // The number for which we want to calculate the factorial
    printf("Factorial of %d is %d\n", num, factorial(num)); // Print the result
    return 0;
}
