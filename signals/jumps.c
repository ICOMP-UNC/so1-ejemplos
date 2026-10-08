/* Habilita la API POSIX para que setjmp/longjmp y otras funciones
   del entorno POSIX estén disponibles de forma estándar. */
#define _POSIX_C_SOURCE 200809L

#include <setjmp.h>
#include <stdio.h>

static jmp_buf env;

/* Simulates a nested function that jumps back to main. */
static void child(void)
{
    puts("Inside child() and jumping back.");
    longjmp(env, 1);
}

int main(void)
{
    /* setjmp saves the execution point. */
    if (setjmp(env) == 0) {
        puts("First time through.");
        child();
    } else {
        puts("Returned by longjmp().");
    }

    puts("Program finished.");
    return 0;
}
