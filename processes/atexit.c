#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
bye(void)
{
   printf("That was all, folks\n");
}

int
main(void)
{
    long a;
    int i;
    
    /*
    POSIX  allows  an application to test at compile or run time whether certain options are supported,
    or what the value is of certain configurable constants or limits.
    */
    a = sysconf(_SC_ATEXIT_MAX);
    printf("ATEXIT_MAX = %ld\n", a);
    
    i = atexit(bye);
    if (i != 0) {
        fprintf(stderr, "cannot set exit function\n");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}

