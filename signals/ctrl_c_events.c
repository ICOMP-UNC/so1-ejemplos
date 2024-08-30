#include <stdlib.h> 
#include <stdio.h>
#include <signal.h> 
#include <unistd.h> 

static void handler(int sig)
{
    printf("You think hitting ctrl-c will stop the bomb?\n");
    sleep(2);
    printf("Well...");

    fflush(stdout);
    sleep(1);
    printf("OK\n");
    exit(0);
} 

// A program that reacts to externally generated events (ctrl-c)
int main()
{ 
    /* installs ctl-c handler */
    signal (SIGINT, handler);

    while (1) {
    } 
}
