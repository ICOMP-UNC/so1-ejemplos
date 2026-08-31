#include <stdio.h>

/*
Compute the length of a string manually without using strlen() function.

Example:
	Enter a string: Sistemas_Operativos_I
	Length of string: 21
*/

#define BUFFER_SIZE 1000	//1 KB

int main()
{
	char s[BUFFER_SIZE];	// s = {unknown data filling the buffer...}
	unsigned i;

    printf("Enter a string: ");
	//scanf("%s", s) Reads a string until a whitespace is found, basically only 1 word
    //scanf("%[^\n]", s) Reads a string until a newline is found
    scanf("%[^\n]", s);
    // After scanf s = {'S','i','s','t','e','m','a','s',' ','O','p','e','r','a','t','i','v','o','s',' ','I','\0','unknown data filling the buffer...'}

    for(i = 0; s[i] != '\0'; ++i);

    printf("Length of string: %d\n", i);

    return 0;
}
