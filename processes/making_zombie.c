/*
* Making a Zombie Process
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	pid_t child_pid;

	/* Create a child process. */
	child_pid = fork ();

	if (child_pid > 0) {
		/* This is the parent process. Sleep for a minute. */
		sleep (30);
	}

	else {
		/* This is the child process. Exit immediately. */
		exit (0);
	}

	return 0;
}


/*

$ ps -A | grep a.out
   8135 pts/1    00:00:00 a.out
   8136 pts/1    00:00:00 a.out <defunct>

# ..process finish..

$ ps -A | grep a.out
$

*/

/*
Run it, and while it’s still running, list the processes on the system by invoking the following command in another window:
	ps -e -o pid,ppid,stat,cmd

PROCESS STATE CODES
	Z    defunct ("zombie") process, terminated but not reaped by its parent

$ ps -e -o pid,ppid,stat,cmd | grep a.out
   8381    4055 S+   ./a.out
   8382    8381 Z+   [a.out] <defunct>


*/

/*
You cannot kill a zombie

$ ps -e -o pid,ppid,stat,cmd | grep a.out
   8422    4055 S+   ./a.out
   8423    8422 Z+   [a.out] <defunct>
   8428    3996 S+   grep --color=auto a.out

# try to kill the zombie
$ kill -9 8423
$ ps -e -o pid,ppid,stat,cmd | grep a.out
   8422    4055 S+   ./a.out
   8423    8422 Z+   [a.out] <defunct>
   8430    3996 S+   grep --color=auto a.out
*/

/* Kill the parent

The zombie gets clean by init

$ ps -e -o pid,ppid,stat,cmd | grep a.out
   8465    4055 S+   ./a.out
   8466    8465 Z+   [a.out] <defunct>
   8468    3996 S+   grep --color=auto a.out

$ kill -9 8465
$ ps -e -o pid,ppid,stat,cmd | grep a.out
   8483    3996 S+   grep --color=auto a.out

*/
