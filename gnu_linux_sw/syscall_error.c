#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <stdlib.h>


int main() {

    int fd = open ("inputfile.txt", O_RDONLY);
    if (fd == -1) {
        /* The open failed. Print an error message and exit. */
        fprintf (stderr, "error opening file: %s\n", strerror (errno));
        exit (1);
    }
}
