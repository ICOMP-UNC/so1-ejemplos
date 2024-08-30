#include <stdio.h>

/*
Compute the length of a string manually without using strlen() function.

Example:
	Enter a string: Sistemas Operativos I
	Length of string: 21
*/
int main()
{
	char s[1000]; //1KB
	unsigned i;

    printf("Enter a string: ");
    scanf("%s", s);

    for(i = 0; s[i] != '\0'; ++i);

    printf("Length of string: %d\n", i);
    
    return 0;
}
