// Listing 3.5 (sigusr1.c) Using a Signal Handler
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void handler (int signal_number)
{
	++sigusr1_count;
}



/*
*  example shows: sigaction,  SIGUSR1 
*/
int main ()
{
	// signal(SIGUSR1, handler);
	
	struct sigaction sa;
	memset(&sa, 0, sizeof (sa));
	
	sa.sa_handler = &handler;
	

	sigaction(SIGUSR1, &sa, NULL);

	/* Do some lengthy stuff here. */
	
	/* ... */
	
	kill(getpid(), SIGUSR1);
	
	/* ... */
	
	kill(getpid(), SIGUSR1);

	printf ("SIGUSR1 was raised %d times\n", sigusr1_count);

	return 0;
}
