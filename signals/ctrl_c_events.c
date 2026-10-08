/* Habilita la API POSIX para que sigaction, signal y otras funciones
   de señales queden declaradas de forma estándar en Linux. */
#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static volatile sig_atomic_t interrupted = 0;

/* Handles Ctrl+C by setting a flag. */
static void handle_sigint(int signum)
{
    (void)signum;
    interrupted = 1;
    write(STDOUT_FILENO, "Ctrl+C received\n", 16);
}

int main(void)
{
    /* Install the signal handler for SIGINT. */
    signal(SIGINT, handle_sigint);

    while (!interrupted) {
        puts("Waiting for Ctrl+C...");
        sleep(1);
    }

    puts("Program ended by signal.");
    
    return 0;
}
