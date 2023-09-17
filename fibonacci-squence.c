#include <stdio.h>

// Function to generate and print the Fibonacci series up to 'n' terms
void fibonacci(int n) {
    int a = 0, b = 1, c; // Initialize variables for the first two terms
    printf("Fibonacci Series up to %d terms:\n", n);
    
    // Iterate through the series and print each term
    for (int i = 1; i <= n; i++) {
        printf("%d, ", a); // Print the current term
        c = a + b; // Calculate the next term by adding the previous two terms
        a = b;     // Update 'a' to be the previous term
        b = c;     // Update 'b' to be the current term
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &num); // Read the user's input for the number of terms
    fibonacci(num); // Call the fibonacci function to generate and print the series
    return 0;
}
