#include <stdio.h>  
#include <string.h>   
#include <ctype.h> // toupper()
 
/*
* C strupr() function converts a string to uppercase letters.
*
* DEPRECATED MS WINDOWS FUNCTION
*
*/
void main()
{    
	char str[10] = "Hello C.";  
	for(int i = 0; str[i]; i++){
		str[i] = toupper(str[i]);
	}
	printf("%s", str);
	//printf("%s", strupr(str));    
}
