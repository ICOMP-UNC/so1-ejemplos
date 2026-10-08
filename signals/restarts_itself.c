/* Habilita la API POSIX para que sigsetjmp/siglongjmp y las señales
   queden declaradas de forma estándar en Linux. */
#define _POSIX_C_SOURCE 200809L

#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// para guardar el contexto de ejecución y poder volver a ese punto más adelante
static sigjmp_buf env;

/* Restarts the execution point when SIGINT arrives. */
static void handle_sigint(int signum)
{
    int restart_code = 1; //valor que se devuelve a sigsetjmp para indicar que se ha recibido SIGINT

    (void)signum;
    siglongjmp(env, restart_code);
}

int main(void)
{
    int save_mask = 1;

    signal(SIGINT, handle_sigint);

    /* save_mask = 1 indica que se guarda la máscara de señales actual. */
    if (sigsetjmp(env, save_mask) == 0) {
        puts("Starting.");
    } else {
        puts("Restarting after SIGINT.");
    }

    while (1) {
        puts("Processing...");
        sleep(1);
    }

    return 0;
}
