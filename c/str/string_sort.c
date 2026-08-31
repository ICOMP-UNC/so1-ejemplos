#include<stdio.h>
#include <string.h>

/*
Sort Strings in Dictionary Order
++++++++++++++++++++++++++++++++

Code a program that sorts N strings (entered by the user)
in lexicographical order (dictionary order).

Example Output:
--------------
    
    Enter 10 words:
    C
    C++
    Java
    PHP
    Python
    Perl
    Ruby
    R
    JavaScript
    PHP

    In lexicographical order: 
    C
    C++
    Java
    JavaScript
    PHP
    PHP
    Perl
    Python
    R
    Ruby

*/

int main()
{
    int i, j;
    char str[10][50], temp[50];

    printf("Enter 10 words:\n");


    for(i=0; i<10; ++i) {
        scanf("%[^\n]", str[i]);
    }
    
    for (i=0; i<9; ++i) {
        for (j=i+1; j<10 ; ++j) {
            if (strcmp(str[i], str[j])>0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nIn lexicographical order: \n");
    for (i=0; i<10; ++i) {
        puts(str[i]);            // Accepts only one string and adds a newline
    //  printf("%s\n", str[i]);     Accepts multiple data types, newline is added manually, more versatile
    }
    return 0;
}
