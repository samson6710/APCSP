/*
Samson Shi
The program sorts cities based on their average high temperatures in descending order using insertion sort.
It defines a struct City to represent city data, including the name and temperature.
It initializes an array of City structs with the city names and temperatures.
It uses the insertion sort algorithm to sort the cities based on their temperatures in descending order.
It prints the sorted city temperatures.
*/

#include <stdio.h>
#include <string.h>

// Max number of cities
#define MAX 10

// Define a struct to hold city data
typedef struct {
    char name[50];
    int temp;
} City;

// City data
City cities[MAX] = {
    {"Phoenix", 107},
    {"Las Vegas", 105},
    {"Austin", 97},
    {"Miami", 97},
    {"Denver", 90},
    {"Chicago", 85},
    {"New York", 85},
    {"Boston", 82},
    {"Los Angeles", 82},
    {"San Francisco", 66}
};

// Function prototypes
void sort_cities(City cities[], int n);
void print_cities(City cities[], int n);

int main() {
    // Sort the cities
    sort_cities(cities, MAX);
    
    // Print the sorted cities
    print_cities(cities, MAX);
    
    return 0;
}

// Function to sort the cities using insertion sort
void sort_cities(City cities[], int n) {
    for (int i = 1; i < n; i++) {
        City key = cities[i];
        int j = i - 1;
        
        // Compare temperature, move elements that are smaller than the key to one position ahead
        while (j >= 0 && cities[j].temp < key.temp) {
            cities[j + 1] = cities[j];
            j = j - 1;
        }
        cities[j + 1] = key;
    }
}

// Function to print the sorted cities
void print_cities(City cities[], int n) {
    printf("Average July Temperatures by City\n\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", cities[i].name, cities[i].temp);
    }
}
