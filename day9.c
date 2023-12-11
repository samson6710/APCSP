#include <stdio.h>

// Samson Shi 

// Function prototype
double half(double bill, double tax, double tip);

int main(void)
{
    double bill, tax, tip;

    // Get input from the user
    printf("Bill before tax and tip: ");
    scanf("%lf", &bill);
    
    printf("Sale Tax Percent: ");
    scanf("%lf", &tax);
    
    printf("Tip percent: ");
    scanf("%lf", &tip);
    
    double eachOwe = half(bill, tax, tip);
    
    printf("You will owe $%.2lf each!\n", eachOwe);

    return 0;
}

// Function implementation
double half(double bill, double tax, double tip)
{
    double taxAmount = (tax / 100) * bill;  // calculate tax amount
    double totalBill = bill + taxAmount;    // add tax to bill
    double tipAmount = (tip / 100) * totalBill;  // calculate tip based on total bill (after tax)
    double finalAmount = totalBill + tipAmount;  // final amount after tax and tip

    return finalAmount / 2;  // return half of the final amount
}
