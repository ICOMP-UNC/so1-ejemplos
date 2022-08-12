#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

/* Print the contents of the home page for the server’s socket.
Return an indication of success. */
void get_home_page (int socket_fd)
{
	char buffer[10000];
	ssize_t number_characters_read;

	/* Send the HTTP GET command for the home page. */
	sprintf (buffer, “GET /\n”);
	write (socket_fd, buffer, strlen (buffer));

	/* Read from the socket. The call to read may not
	return all the data at one time, so keep
	trying until we run out. */
	while (1) {
		number_characters_read = read (socket_fd, buffer, 10000);
		if (number_characters_read == 0)
			return;
		
		/* Write the data to standard output. */
		fwrite (buffer, sizeof (char), number_characters_read, stdout);
	}
}
/*
This program takes the hostname of the Web server on the command line (not a
URL—that is, without the “http://”). It calls gethostbyname to translate the hostname
into a numerical IP address and then connects a stream (TCP) socket to port 80 on
that host.Web servers speak the Hypertext Transport Protocol (HTTP), so the program
issues the HTTP GET command and the server responds by sending the text of the
home page.
*/
int main (int argc, char* const argv[])
{
	int socket_fd;
	struct sockaddr_in name;
	struct hostent* hostinfo;

	/* Create the socket. */
	socket_fd = socket (PF_INET, SOCK_STREAM, 0);
	
	/* Store the server’s name in the socket address. */
	name.sin_family = AF_INET;
	
	/* Convert from strings to numbers. */
	hostinfo = gethostbyname (argv[1]);
	if (hostinfo == NULL)
		return 1;
	else
		name.sin_addr = *((struct in_addr *) hostinfo->h_addr);
	
	/* Web servers use port 80. */
	name.sin_port = htons (80);
	
	/* Connect to the Web server */
	if (connect (socket_fd, &name, sizeof (struct sockaddr_in)) == -1) {
		perror (“connect”);
		return 1;
	}

	/* Retrieve the server’s home page. */
	get_home_page (socket_fd);

	return 0;
}

/*
For example, to retrieve the home page from the Web site
invoke this:
www.codesourcery.com ,
% ./socket-inet www.codesourcery.com
*/
