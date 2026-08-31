#include <stdio.h>

/*
gets() and puts()
+++++++++++++++++

Functions gets() and puts() are two string functions
	gets() to take string input from the user
	puts() to display string output to the user
*/

int main()
{
    char name[30];
    
    printf("Enter name: ");
    
    // read string from user until \n is encountered
    fgets(name, sizeof(name), stdin);
    // gets(name);	Dangerous function, doesn't check for buffer overflow

    printf("Name: ");
    
    // display string
    puts(name);
    
    return 0;
}
