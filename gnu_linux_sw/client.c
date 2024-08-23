/*Listing 2.4 (client.c) Part of a Network Client Program*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char* server_name = getenv ("SERVER_NAME");
	
	// char* user = getenv ("USER");
	// path = "/home/"
	// strcat(path, user)

	/* The SERVER_NAME environment variable was not set. Use the default. */
	if (server_name == NULL)
		server_name = "server.my-company.com";
		
	printf ("accessing server %s\n", server_name);
	
	/* Access the server here... */

	return 0;
}
