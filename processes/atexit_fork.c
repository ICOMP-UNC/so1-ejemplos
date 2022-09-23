#include <stdlib.h> // exit
#include <stdio.h> // printf
#include <unistd.h> // fork


void cleanup(void)
{
   printf("cleaning up\n");
}

void main()
{
   atexit(cleanup);
   
   if (fork() == 0) {
      printf("hello from child\n");
   } 
   else { 
      printf("hello from parent\n");
   } 

   exit(EXIT_SUCCESS);
}
