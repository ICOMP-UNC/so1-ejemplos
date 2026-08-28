/*
 * volatile y señales
 *
 * Este ejemplo muestra una variable que puede cambiar mientras main()
 * está ejecutando un while (sobre una variable global).
 * La variable es modificada por un manejador de señales.
 *
 * La señal SIGINT se envía al presionar Ctrl+C. El manejador de señales
 * cambia el valor de stop_requested.
 *
 * volatile le avisa al compilador que la variable puede cambiar en cualquier
 * momento. Por eso debe leerla cada vez que evalúa la condición del while.
 * sig_atomic_t es un tipo adecuado para compartir una variable con una señal.
 *
 * Para compilar y ejecutar:
 *
 *     cd c
 *     gcc volatile_signals.c -o volatile_signals
 *     ./volatile_signals
 *
 * El programa queda ejecutando el while. Para terminarlo, apretá Ctrl+C.
 */

#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t stop_requested = 0;

void handle_sigint(int signal_number)
{
    (void)signal_number;
    stop_requested = 1;
}

int main(void)
{
    signal(SIGINT, handle_sigint);

    printf("Running. Press Ctrl+C to stop.\n");

    while (!stop_requested) {
        /* El manejador puede cambiar stop_requested mientras estamos acá. */
    }

    printf("SIGINT received. Loop finished.\n");

    return 0;
}
