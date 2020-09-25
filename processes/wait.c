#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int spawn (char* program, char** arg_list)
{
	pid_t child_pid;

	/* Duplicate this process. */
	child_pid = fork ();

	if (child_pid != 0) {
		return child_pid;
	}
	else {
		execvp (program, arg_list);
		/* returns only if an error occurs. */
		fprintf (stderr, "an error occurred in execvp\n");
		abort ();
	}
}

int main ()
{
	int child_status;
	/* The argument list to pass to the “ls” command. */
	
	char* arg_list[] = {
		"ls", /* argv[0], the name of the program. */
		"-l",
		"/",
		NULL /* The argument list must end with a NULL. */
	};

	/* Spawn a child process running the “ls” command. Ignore the
	returned child process ID. */
	spawn("ls", arg_list);

	/* Wait for the child process to complete. */
	wait(&child_status);
	
	if (WIFEXITED (child_status))
		printf ("the child process exited normally, with exit code %d\n",
		WEXITSTATUS (child_status));
	else
		printf ("the child process exited abnormally\n");
	
	return 0;
}
