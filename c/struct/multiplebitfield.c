#include <stdio.h>

/*
bit field
+++++++++

Multiple adjacent bit fields are permitted
to be (and usually are) packed together
*/

struct S {
    // sizeof(unsigned) is 4 bytes = 32 bits
    unsigned b1 : 5,         // b1 occupies 5 bits
                : 11,        // 11 bits unused
             b2 : 6,         // b2 occupies 6 bits
             b3 : 3;         // b3 occupies 3 bits
            //  : 7;         // 8 bits unused, no need to explicit as they are the last bits
};

int main(void)
{
    // prints 4
    printf("%zu\n",sizeof(struct S));

    struct S s = {5, 10, 13};
    printf("b1: %d\n", s.b1);
    printf("b2: %d\n", s.b2);
    printf("b3: %d\n", s.b3);        // 13 is 1101 in binary, but b3 will store 101 = 5 as it has 3 bits only

}
