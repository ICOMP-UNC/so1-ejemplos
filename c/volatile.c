/*
 * volatile, const and volatile
 *
 * volatile: tells the compiler that a value may change outside the normal
 * flow of this function. Therefore, each access must be performed
 * "Compilador, no optimices este acceso, porque el valor puede cambiar en cualquier momento"
 *
 * const: tells the compiler that this program cannot modify the object through
 * its name. The object may still be volatile if an external agent can change
 * it, for example a hardware device.
 */

#include <stdio.h>

volatile int value = 10;
const volatile int status_register = 20;

void show_volatile(void)
{
    printf("volatile value: %d\n", value);
}

void show_const_volatile(void)
{
    printf("const volatile value: %d\n", status_register);

    /*
     * This assignment is invalid:
     *
     * status_register = 30;
     *
     * const prevents this program from modifying the object.
     * volatile does not make the object writable.
     */
}

void show_volatile_loop(void)
{
    volatile int counter = 5;

    printf("Starting volatile loop with counter = %d\n", counter);

    while (counter > 0) {
        --counter;
    }

    printf("Volatile loop finished with counter = %d\n", counter);
}

int main(void)
{
    show_volatile();
    show_const_volatile();
    show_volatile_loop();

    return 0;
}
