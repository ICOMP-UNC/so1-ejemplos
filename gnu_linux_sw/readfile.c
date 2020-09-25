// readfile.c
// Listing 2.6 (readfile.c) Freeing Resources During Abnormal Conditions

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char* read_from_file (const char* filename, size_t length)
{
	char* buffer;
	int fd;
	ssize_t bytes_read;

	/* Allocate the buffer. */
	buffer = (char*) malloc (length);
	if (buffer == NULL)
		return NULL;

	/* Open the file. */
	fd = open (filename, O_RDONLY);

	if (fd == -1) {
		/* open failed. Deallocate buffer before returning. */
		free (buffer);
		
		return NULL;
	}

	/* Read the data. */
	bytes_read = read (fd, buffer, length);
	if (bytes_read != length) {
		/* read failed. Deallocate buffer and close fd before returning. */
		free (buffer);
		close (fd);
		
		return NULL;
	}

	/* Everything’s fine. Close the file and return the buffer. */
	close (fd);

	return buffer;
}

