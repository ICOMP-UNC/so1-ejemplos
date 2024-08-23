// Example program
#include <stdio.h>

int main()
{
    /*
     * in standard IEEE 754 division by zero is allowed
     * output: -nan
    */
    //double a = 0.0/0.0;

    /*
     * in standard IEEE 754 division by zero is allowed
     * output: inf
    */
    double a = 3.0/0;

    /*
     * Floating point exception (core dumped)
     *
    */
    // int a = 3/0;
    // int a = 0/0;

    printf("%f", a);
}
