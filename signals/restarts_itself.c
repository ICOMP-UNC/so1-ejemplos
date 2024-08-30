#include <stdio.h> 
#include <signal.h> 
#include <setjmp.h> 
#include <unistd.h> 

sigjmp_buf buf; 
 
void handler(int sig)
{
    siglongjmp(buf, 1);
}
 
// A program that restarts itself when ctrl-c’d
int main()
{
    signal(SIGINT, handler);

    if (!sigsetjmp(buf, 1)) 
        printf("starting\n");
    else
        printf("restarting\n");

    while(1) {
        sleep(1);
        printf("processing...\n");
    }
}
