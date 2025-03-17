#include <stdio.h>        // Include standard input/output library for printing
#include "../header/dev.h" // Include the header file for developer-related functions
#include "../header/logo.h" // Include the header file for logo-related functions

// Function declaration for the main loop
void loop();

int main(void) {
    // Print a stylized menu using ANSI escape codes to color the text
    printf("\033[4;92m========================\n");
    printf("Choose your action: \n");
    printf("List Developers \t[1]\n");
    printf("Print Group Logo \t[2]\n");
    printf("Print Group \t\t[3]\n");
    printf("Exit \t\t\t[4]\n");
    printf("========================\033[0m\n");

    // Call the loop function
    loop();
}

// The main loop that handles user input and selects actions
void loop() {
    int input;
    while (1) {  // Infinite loop until break
        printf("Enter your selection: ");
        scanf("%d", &input); // Read user input

        // Check if the input is within the valid range (1-4)
        if (input >= 1 && input <= 4) {
            if (input == 1) {
                list_developers(); // Call function to list developers from dev.h
            } else if (input == 2) {
                print_logo(); // Call function to print the group logo from logo.h
            } else if (input == 3) {
                list_developers();
                print_logo();
            } else if (input == 4) {
                printf("Exiting...\n");
                break;
            }
        } else {
            // If the input is not valid (not between 1 and 4), display an error message
            printf("Invalid selection! Please choose a number between 1 and 4.\n");
        }
    }
}
