#include <stdio.h>

int main(void)
{
    char name[100], location[100];
    
    printf("What is your name? ");
    scanf("%99s", name);  // Limit input to 99 characters to leave space for the null terminator
    
    printf("Where do you live? ");
    scanf("%99s", location); // Limit input to 99 characters to leave space for the null terminator
    
    printf("Hello, %s, from %s!\n", name, location);
    return 0;
}
