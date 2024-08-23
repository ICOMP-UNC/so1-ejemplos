#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{

   if (fork() == 0) {
      execl("/usr/bin/touch", "touch", "foo", NULL); 

      abort();
      execl("/usr/bin/cp", "cp", "foo", "bar", NULL);
   }

   wait(NULL);

   printf("copy completed\n");
   
   exit(EXIT_SUCCESS);
}
