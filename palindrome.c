#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a given string is a palindrome
bool isPalindrome(char str[]) {
    int left = 0;                  // Initialize a pointer for the left end of the string
    int right = strlen(str) - 1;  // Initialize a pointer for the right end of the string
    
    while (left < right) {
        if (str[left] != str[right])
            return false;  // If characters at the left and right positions don't match, it's not a palindrome
        left++;            // Move the left pointer to the right
        right--;           // Move the right pointer to the left
    }
    
    return true;  // If the loop completes without returning false, the string is a palindrome
}

int main() {
    char str[] = "racecar";  // Define the string to be checked
    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);  // Print the result if it's a palindrome
    else
        printf("%s is not a palindrome.\n", str);  // Print the result if it's not a palindrome
    return 0;
}
