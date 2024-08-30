#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;


    int x = 1;
    
    pid = fork();
    
    if (pid != 0) {
        printf("parent: x = %d\n", --x);
        exit(0);
    } 
    else {
        printf("child:  x = %d\n", ++x);
        exit(0);
    }
}
