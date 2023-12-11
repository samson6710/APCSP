#include <stdio.h>

/*
Samson Shi
*/


// Function to perform linear search
int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to perform binary search
int binarySearch(int arr[], int size, int value) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int size, value, result, searchType;

    // Ask the user for the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input the array
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the value to search for
    printf("Enter the number to find: ");
    scanf("%d", &value);

    // Ask the user which search to use
    printf("Type 1 for Linear Search or 2 for Binary Search: ");
    scanf("%d", &searchType);

    if (searchType == 1) {
        // Perform linear search
        result = linearSearch(arr, size, value);
    } else if (searchType == 2) {
        // Perform binary search
        // Note: The array should be sorted for binary search
        result = binarySearch(arr, size, value);
    } else {
        printf("Invalid search type.\n");
        return 1;
    }

    // Output the result
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
