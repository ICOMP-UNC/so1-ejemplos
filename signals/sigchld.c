#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static volatile sig_atomic_t child_exit_status = 0;

/* Reaps a background job and stores its exit status. */
static void handle_sigchld(int signum)
{
    int status = 0;

    (void)signum;
    wait(&status);
    child_exit_status = status;
    printf("Parent: background job finished; exit status = %d\n",
           WEXITSTATUS(status));
}

int main(void)
{
    struct sigaction sa;
    pid_t pid;

    /* Register the handler for SIGCHLD. */
    sa.sa_handler = handle_sigchld;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        puts("Child: background job started.");
        puts("Child: exiting with code 3.");
        _exit(3);
    }

    puts("Parent: continuing other work while the background job runs.");
    pause();
    printf("Parent: child_exit_status=%d\n", WEXITSTATUS(child_exit_status));

    while (1) {
        puts("Parent: still doing work...");
        sleep(10);
    }

    return 0;
}
