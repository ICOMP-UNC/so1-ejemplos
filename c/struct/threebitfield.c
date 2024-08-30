#include <stdio.h>

/*
bit field
+++++++++

Declares a member with explicit , in bits. Adjacent bit field members
may bwidthe packed to share and straddle the individual bytes.

*/

struct S {
   // three-bit unsigned field, allowed values are 0...7
   unsigned int b : 3;
};

int main(void)
{
    struct S s = {7};
    
    // unsigned overflow
    ++s.b;
    
    // output: 0
    printf("%d\n", s.b);
}
