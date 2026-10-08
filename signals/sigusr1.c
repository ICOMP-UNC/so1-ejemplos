#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static volatile sig_atomic_t sigusr1_count = 0;

/* Counts the times SIGUSR1 is received. */
static void handle_sigusr1(int signum)
{
    (void)signum;
    ++sigusr1_count;
}

int main(void)
{
    struct sigaction sa;

    /* Register the handling function. */
    sa.sa_handler = handle_sigusr1;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    kill(getpid(), SIGUSR1);
    kill(getpid(), SIGUSR1);

    printf("SIGUSR1 was raised %d times\n", sigusr1_count);
    return 0;
}
