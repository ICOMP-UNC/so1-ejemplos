/*
 * Listing 2.2 (getopt_long.c) Using getopt_long
 * ---------------------------------------------
 * 
 * Listing shows an example of how you might use getopt_long to process your arguments.
*/

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* The name of this program.*/
const char* program_name;
/* Prints usage information for this program to STREAM (typically
stdout or stderr), and exit the program with EXIT_CODE. Does not
return. */
void print_usage (FILE* stream, int exit_code)
{
	fprintf (stream, "Usage: %s options [ inputfile ... ]\n", program_name);
	fprintf (stream,
			" -h --help  Display this usage information.\n"
			" -o --output filename Write output to file.\n"
			" -v --verbose Print verbose messages.\n");

	exit (exit_code);
}

/* Main program entry point. ARGC contains number of argument list
elements; ARGV is an array of pointers to them. */
int main (int argc, char* argv[])
{
	int next_option;

	/* A string listing valid short options letters.*/
	const char* const short_options = "ho:v";

	/* An array describing valid long options. */
	const struct option long_options[] = {
		{ "help", 0, NULL, 'h' },
		{ "output", 1, NULL, 'o' },
		{ "verbose", 0, NULL, 'v' },
		{ NULL, 0, NULL, 0} /* Required at end of array.*/
	};

	/* The name of the file to receive program output, or NULL for
	standard output. */
	const char* output_filename = NULL;
	
	/* Whether to display verbose messages. */
	int verbose = 0;
	
	/* Remember the name of the program, to incorporate in messages.
	The name is stored in argv[0]. */
	program_name = argv[0];
	
	do {
		next_option = getopt_long (argc, argv, short_options, long_options, NULL);
	
		printf ("next_option: %c optind: %d\n", next_option, optind);
		switch (next_option) {
			/* -h or --help */
			case 'h': 
				/* User has requested usage information. Print it to standard
				output, and exit with exit code zero (normal termination). */
				print_usage (stdout, 0);
				/* try echo $?*/

			/* -o or --output */
			case 'o': 
				/* This option takes an argument, the name of the output file.*/
				output_filename = optarg;
				break;
			/* -v or --verbose */
			case 'v':
				verbose = 1;
				break;
			/* The user specified an invalid option. */
			case '?':
				/* Print usage information to standard error, and exit with exit
				code one (indicating abnormal termination). */
				print_usage (stderr, 1);
				/* try echo $?*/
			/* Done with options.*/
			case -1:
				break;
			/* Something else: unexpected.*/
			default:
				abort ();
		}
	}
	while (next_option != -1);

	/* Done with options. OPTIND points to first nonoption argument.
	For demonstration purposes, print them if the verbose option was
	specified. */
	if (verbose) {
		int i;
		for (i = 0; i < argc; i++)
			printf ("Argument: %s %d\n", argv[i], optind);
	}

	/* The main program goes here.
	*/

	return 0;
}
