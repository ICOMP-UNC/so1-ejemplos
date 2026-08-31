#include <stdio.h>  
#include <string.h>   
#include <ctype.h> // toupper()
 
/*
* C strupr() function converts a string to uppercase letters.
*
* DEPRECATED MS WINDOWS FUNCTION
*/

#define BUFFER_SIZE 1000

void main()
{
	char str[BUFFER_SIZE];
	printf("Enter a string: ");
	scanf("%[^\n]", str);

	for(int i = 0; str[i]; i++){
		str[i] = toupper(str[i]);
	}

	printf("%s\n", str);
	//printf("%s", strupr(str));

}
