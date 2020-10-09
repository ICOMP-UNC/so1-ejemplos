#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

/* Write TEXT to the socket given by file descriptor SOCKET_FD.
*/
void write_text (int socket_fd, const char* text)
{
	/* Write the number of bytes in the string, including
	NUL-termination. */
	int length = strlen (text) + 1;
	write (socket_fd, &length, sizeof (length));

	/* Write the string. */
	write (socket_fd, text, length);
}

int main (int argc, char* const argv[])
{
	const char* const socket_name = argv[1];
	const char* const message = argv[2];

	int socket_fd;
	struct sockaddr_un name;

	/* Create the socket. */
	socket_fd = socket (PF_LOCAL, SOCK_STREAM, 0);

	/* Store the server’s name in the socket address. */
	name.sun_family = AF_LOCAL;
	strcpy (name.sun_path, socket_name);

	/* Connect the socket. */
	connect (socket_fd, &name, SUN_LEN (&name));

	/* Write the text on the command line to the socket. */
	write_text (socket_fd, message);
	close (socket_fd);

	return 0;
}

/*
To try this example, start the server program in one window. 
Specify a path to a socket—for example, /tmp/socket .

	% ./socket-server /tmp/socket

In another window, run the client a few times, specifying the same socket path plus
messages to send to the client:

	% ./socket-client /tmp/socket “Hello, world.”
	% ./socket-client /tmp/socket “This is a test.”5.5

The server program receives and prints these messages.

To close the server, send the message “quit” from a client:

	% ./socket-client /tmp/socket “quit”

The server program terminates.
*/
