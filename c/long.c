#include <stdio.h>

/*
In this program, the sizeof operator is used to find the size of int, long, long long, double and long double variables.
As you can see, the size of long int and long double variables are larger than int and double variables, respectively.
By the way, the sizeof operator returns size_t (unsigned integral type).
The size_t data type is used to represent the size of an object. The format specifier used for size_t is %zu.

Note: The long keyword cannot be used with float and char types.
*/
int main() {
    int a;
    long b;   // equivalent to long int b;
    long long c;  // equivalent to long long int c;
    double e;
    long double f;

    printf("Size of int = %zu bytes \n", sizeof(a));
    printf("Size of long int = %zu bytes\n", sizeof(b));
    printf("Size of long long int = %zu bytes\n", sizeof(c));
    printf("Size of double = %zu bytes\n", sizeof(e));
    printf("Size of long double = %zu bytes\n", sizeof(f));
    
    return 0;
}