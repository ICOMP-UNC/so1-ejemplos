/*
 * Ejemplo incorrecto: una variable compartida con una señal sin volatile
 *
 * Este programa es parecido a volatile_signals.c, pero la variable
 * stop_requested NO está declarada como volatile.
 *
 * Para probarlo:
 *
 *     cd c
 *     gcc -O0 volatile_signals_bad.c -o volatile_signals_bad
 *     ./volatile_signals_bad
 *
 * Apretá Ctrl+C. Con -O0, normalmente el loop termina.
 *
 * Ahora compilalo con optimizaciones:
 *
 *     gcc -O2 volatile_signals_bad.c -o volatile_signals_bad
 *     ./volatile_signals_bad
 *
 * Apretá Ctrl+C otra vez. El programa puede quedar ejecutando el loop,
 * porque el compilador puede leer stop_requested una sola vez y asumir que
 * no cambia dentro de main().
 *
 * Para cerrar el programa si Ctrl+C no funciona, presioná:
 *
 *     Ctrl+\\
 *
 * Eso envía SIGQUIT, que termina el proceso por defecto.
 *
 * Este comportamiento no es válido para usarlo en un programa real. La
 * variable compartida con un manejador de señales debe ser volatile
 * sig_atomic_t, como en volatile_signals.c.
 */

#include <signal.h>
#include <stdio.h>

sig_atomic_t stop_requested = 0;

void handle_sigint(int signal_number)
{
    (void)signal_number;
    stop_requested = 1;
}

int main(void)
{
    signal(SIGINT, handle_sigint);

    printf("Ejecutando. Apretá Ctrl+C para terminar.\n");

    while (!stop_requested) {
        /* Sin volatile, el compilador puede optimizar este acceso. */
    }

    printf("SIGINT recibida. El loop terminó.\n");

    return 0;
}
