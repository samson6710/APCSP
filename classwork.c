/*
1)Write a  Program to calculate the sum of first n natural numbers given by the user
 (Example: n=5    sum=1+2+3+4+5)  Pseudocode first
2) Can you write the same with a different kind of loop?
3) if you want to make sure the n is positive and no greater than a 2 bytes number what would you do?
*/

/*
Pseudocode

Samson Shi

create a variable ans, set it to 0
loop to
    Get the number n
    make sure its positive and no greater than 2^16 - 1)

while loop or for loop
    sum  all the numbers from 1 to n to ans

print out the ans
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    int n, n2, ans = 0; // n stores the input number, n2 is the copy of n, ans is the sum of all numbers
    int flag = 1;
    do{
        do {
            n = get_int("n natural number");
        }
        while (n <= 0 || n > pow(2, 16)); // input again if n is less or equal than 0 or n is bigger than 2^16

        n2 = n; // save the number stores in n to another variable n2
        while (n > 0){ // if n is less than 0, break the loop
            ans += n; // sums up the ans each time
            n --; // reduce by 1
        }

        ans = 0; // set the ans back to 0, implement another loop
        for (int i = n2; i >= 0; i --){ // start from n2, end in 0, reduce 1 each time
            ans += i; // + the number
        }

        printf("%d\n", ans);
        flag = get_int("Do you want to calculate again? Yes:1, No:0");
    }
    while (flag != 0);
}
