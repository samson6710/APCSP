#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Samson Shi
//

#define MAX_SIZE 50000  // Maximum size for array

// Function Declarations
// ... [Your existing function declarations]

int main(void)
{
    // Variable declarations
    int choice, size;
    int *array = NULL;
    char fileName[50];

    do {
        // Display the menu and get user choice
        menu();
        choice = get_int("Please enter your choice 1-5: ");

        switch(choice) {
            case 1:
                // Read a file: Get file name and size from user, read data into array
                printf("Enter file name: ");
                scanf("%49s", fileName);
                printf("Enter size of array: ");
                scanf("%d", &size);
                if (size > MAX_SIZE) size = MAX_SIZE;  // Limit array size
                array = readFile(fileName, size);
                break;
            case 2:
                // Sort the array: User chooses sorting method, array is sorted accordingly
                if (array != NULL) {
                    int sortChoice;
                    printf("Choose sorting method (1 for Bubble Sort, 2 for Selection Sort): ");
                    scanf("%d", &sortChoice);
                    if (sortChoice == 1) {
                        bubbleSort(array, size);
                    } else {
                        selectionSort(array, size);
                    }
                    printf("Array sorted.\n");
                } else {
                    printf("Please read a file first.\n");
                }
                break;
            case 3:
                // Search in the array: User provides number to search and method, search is performed
                if (array != NULL) {
                    int searchChoice, guess, result;
                    printf("Enter number to search: ");
                    scanf("%d", &guess);
                    printf("Choose search method (1 for Linear Search, 2 for Binary Search): ");
                    scanf("%d", &searchChoice);
                    if (searchChoice == 1) {
                        result = linearSearch(array, guess, size);
                    } else {
                        result = binarySearch(array, 0, size - 1, guess);
                    }
                    if (result != -1) {
                        printf("Element found at index: %d\n", result);
                    } else {
                        printf("Element not found.\n");
                    }
                } else {
                    printf("Please read a file first.\n");
                }
                break;
            case 4:
                // Write array to file: If array exists, write its contents to a file
                if (array != NULL) {
                    writeArray(array, size);
                } else {
                    printf("Please read a file first.\n");
                }
                break;
            case 5:
                // Exit the program
                printf("Exiting...\n");
                break;
            default:
                // Handle invalid choice
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);  // Continue until user chooses to exit

    // Free allocated memory, if any
    if (array != NULL) {
        free(array);
    }

    return 0;
}

// Function Definitions
// ... [Your existing function definitions with added pseudocode as comments]
