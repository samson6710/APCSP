// Practice using structs
// Practice writing a linear search function

/**
 * Samson Shi
 * Main Algorithm: Selection using strcmp and return struct elements
 * define the struct, there are two elements in the struct: name (string), price (float)
 * manually add the items and their price using struct
 * print out the menu for the customers using for loop
 * using while true to prompt the user for their desired items
    * if the input length is zero, break out from the loop
    * for loop to select which item the user wants using strcmp
    * input change to lower case
    * if find, return its price element
    * if not, return 0.0
 * if the output is 0.0, print "Invalid item"
 * else, add the output to the variable "total"
 * print out the variable total when the program break out from the while loop
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 10

// Menu itmes have item name and price
typedef struct
{
    string item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }
        float p = get_cost(item);
        if (p == 0.0){
            printf("Invalid item!\n ");
        }
        else{
            total += p;
        }
    }

    printf("Your total cost is: $%.2f\n", total);
}

// Add at least the first for items to the menu array
void add_items(void)
{
    menu[0].item = "burger";
    menu[1].item = "vegan burger";
    menu[2].item = "hot dog";
    menu[3].item = "cheese dog";
    menu[4].item = "fries";
    menu[5].item = "cheese fries";
    menu[6].item = "cold pressed juice";
    menu[7].item = "cold brew";
    menu[8].item = "water";
    menu[9].item = "soda";

    menu[0].price = 9.5;
    menu[1].price = 11.00;
    menu[2].price = 5.00;
    menu[3].price = 7.00;
    menu[4].price = 5.00;
    menu[5].price = 6.00;
    menu[6].price = 7.00;
    menu[7].price = 3.00;
    menu[8].price = 2.00;
    menu[9].price = 2.00;

    return;
}

// Search through the menu array to find an item's cost
float get_cost(string food)
{
    for(int i = 0; food[i]; i++){
        food[i] = tolower(ood[i]);
    }
    for (int i = 0; i <= 9; i ++){
        string c = menu[i].item;
        if (strcmp(c, food) == 0){
            return menu[i].price;
        }
    }
    return 0.0;
}
