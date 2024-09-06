#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>  // For printf(), perror()

char* read_from_file(const char* filename, size_t length) {
    char* buffer;
    int fd;
    ssize_t bytes_read;

    /* Allocate the buffer. */
    buffer = (char*) malloc(length + 1);  // +1 for the null terminator
    if (buffer == NULL) {
        perror("Failed to allocate buffer");
        return NULL;
    }

    /* Open the file. */
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        /* open failed. Deallocate buffer before returning. */
        perror("Failed to open file");
        free(buffer);
        return NULL;
    }

    /* Read the data. */
    bytes_read = read(fd, buffer, length);
    if (bytes_read == -1) {
        /* read failed. Deallocate buffer and close fd before returning. */
        perror("Failed to read file");
        free(buffer);
        close(fd);
        return NULL;
    }

    /* Ensure null termination for string operations. */
    buffer[bytes_read] = '\0';

    /* Close the file. */
    close(fd);

    return buffer;
}

int main(int argc, char* argv[]) {
    const char* filename = "/proc/cpuinfo";  // Use a valid file path
    size_t length = 150;  // Adjust buffer size for demonstration

    /* Read from file */
    char* content = read_from_file(filename, length);
    if (content == NULL) {
        fprintf(stderr, "Error reading from file\n");
        return EXIT_FAILURE;
    }

    /* Print the content */
    printf("File content:\n%s\n", content);

    /* Free the allocated buffer */
    free(content);

    return EXIT_SUCCESS;
}
