#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* IPC can be used to enforce the order of the execution of processes.
*/

int main ()
{
    char *s, buf[1024];
    int fds[2];

    pipe(fds);

    if (fork() == 0) {
        printf("child\n");
        
        s = "hello world\n";
        write(fds[1], s, strlen(s));
        
        exit(0);
    }

    printf("father will block until read\n");
    
    read(fds[0], buf, 12);
    printf("father continues..\n");

    // write to std out
    write(1, buf, 12);

    return 1;
}
