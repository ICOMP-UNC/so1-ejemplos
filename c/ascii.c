#include <stdio.h>

/*
In C programming, a character variable holds an ASCII value 
(an integer number between 0 and 127) rather than character itself.

Example Output:
---------------
Enter a character: G
ASCII value of G = 71
*/

int main()
{
    char c;
    printf("Enter a character: ");

    // Reads character input from the user
    scanf("%c", &c);  
    
    // %d displays the integer value of a character
    // %c displays the actual character
    printf("ASCII value of %c = %d\n", c, c);
    return 0;
}
