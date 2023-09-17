#include <stdio.h>
#include <string.h>

// Define a maximum number of users and their credentials
#define MAX_USERS 99
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

// User database
char usernames[MAX_USERS][MAX_USERNAME_LENGTH] = {""};
char passwords[MAX_USERS][MAX_PASSWORD_LENGTH] = {""};
int numUsers = 3;

// Function to check if the entered username and password are valid
int authenticate(char *username, char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0) {
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}

int main() {
    char enteredUsername[MAX_USERNAME_LENGTH];
    char enteredPassword[MAX_PASSWORD_LENGTH];
    int choice;

    printf("Welcome to the Login System\n");

    while (1) {
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter your username: ");
            scanf("%s", enteredUsername);

            printf("Enter your password: ");
            scanf("%s", enteredPassword);

            if (authenticate(enteredUsername, enteredPassword)) {
                printf("Authentication successful. Welcome, %s!\n", enteredUsername);
                break;
            } else {
                printf("Authentication failed. Please try again.\n");
            }
        } else if (choice == 2) {
            if (numUsers >= MAX_USERS) {
                printf("Maximum number of users reached. Cannot register new users.\n");
            } else {
                printf("Enter a new username: ");
                scanf("%s", enteredUsername);

                // Check if the username is already taken
                int usernameTaken = 0;
                for (int i = 0; i < numUsers; i++) {
                    if (strcmp(enteredUsername, usernames[i]) == 0) {
                        usernameTaken = 1;
                        break;
                    }
                }

                if (usernameTaken) {
                    printf("Username already taken. Please choose a different username.\n");
                } else {
                    printf("Enter a new password: ");
                    scanf("%s", enteredPassword);

                    // Add the new user to the database
                    strcpy(usernames[numUsers], enteredUsername);
                    strcpy(passwords[numUsers], enteredPassword);
                    numUsers++;

                    printf("Registration successful. You can now login with your new account.\n");
                }
            }
        } else if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
