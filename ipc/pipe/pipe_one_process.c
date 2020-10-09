#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char *s, buf[1024];
    int fds[2];
    
    s = "hello world\n";
    
    pipe(fds);

    // write to pipe's input
    write(fds[1], s, strlen(s));
    
    // write to pipe's output
    read(fds[0], buf, strlen(s));

    printf("fds[0] = %d, fds[1] = %d\n", fds[0], fds[1]);
    
    // write to std out
    write(1, buf, strlen(s));

    return 1;
}
