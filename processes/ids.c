#include <stdio.h>
#include <unistd.h>

/*
Always use the pid_t typedef, which is defined in <sys/types.h>.

getpid 
======
returns the identifier of the calling process. 
        pid _t getpid(void);

- This is often used by routines that generate unique temporary filenames.

getppid 
======
returns the identifier of the parent. 
             pid_t getppid(void);

*/
int main ()
{
    printf ("The process ID is %d\n", (int) getpid());
    printf ("The parent process ID is %d\n", (int) getppid());

    return 0;
}
