#include <stdio.h>

/*
In this program, the sizeof operator is used to find the size of int, long, long long, float, double and long double variables.
As you can see, the size of long int and long double variables are larger than int and double variables, respectively.
By the way, the sizeof operator returns size_t (unsigned integral type).
The size_t data type is used to represent the size of an object. The format specifier used for size_t is %zu.

Note: The long keyword cannot be used with float and char types.*/

int main() {
    int a;            // %d         [4 bytes - 1 word - architecture dependent]
    long b;           // %ld        (equivalent to long int b;)
    long long c;      // %lld       (equivalent to long long int c;)
    float d;          // %f         [4 bytes]
    double e;         // %lf        [8 bytes]
    long double f;    // %Lf

    printf("Size of int = %zu bytes \n", sizeof(a));
    printf("Size of long int = %zu bytes\n", sizeof(b));
    printf("Size of long long int = %zu bytes\n", sizeof(c));
    printf("Size of float = %zu bytes\n", sizeof(d));
    printf("Size of double = %zu bytes\n", sizeof(e));
    printf("Size of long double = %zu bytes\n", sizeof(f));
    
    return 0;
}