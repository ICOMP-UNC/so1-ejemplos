#include <stdio.h> 
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int beeps = 0; 

/* SIGALRM handler */
void handler(int sig)
{ 
  printf("BEEP\n"); 
  fflush(stdout); 
 
  if (++beeps < 5)  alarm(1); 
  else { 
    printf("BOOM!\n"); 
    exit(0); 
  }
} 

int main()
{ 
  signal(SIGALRM, handler);  

  /* send SIGALRM in 1 second */
  alarm(5); 

  while (1) { 
    /* handler returns here */ 
  } 
}

/*
$ a.out  
BEEP 
BEEP 
BEEP 
BEEP 
BEEP 
BOOM! 
*/
