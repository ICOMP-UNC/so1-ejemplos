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
    
    // read string from user
    gets(name);     

    printf("Name: ");
    
    // display string
    puts(name);
    
    return 0;
}
