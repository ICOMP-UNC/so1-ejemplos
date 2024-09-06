#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>  // For chown
#include <string.h>  // For strerror
#include <assert.h>
#include <sys/types.h>

/*
	Explanation of Error Codes:

	EPERM: Permission denied (insufficient privileges to change ownership).
	EROFS: The file is on a read-only file system.
	ENAMETOOLONG: The file path exceeds the system's limit for path lengths.
	ENOENT: The file or a component of the path does not exist.
	ENOTDIR: A component of the path was expected to be a directory but wasn't.
	EACCES: Permission denied for a component of the path (e.g., directory traversal).
*/

// The program accepts two arguments: the file path and the user ID.

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file_path> <user_id>\n", argv[0]);
        return 1;
    }

    const char *path = argv[1];
    uid_t user_id = atoi(argv[2]);
    int rval;

    // Attempt to change ownership, keeping group ID unchanged with -1.
    rval = chown(path, user_id, -1);

    if (rval != 0) {
        // Save errno because it’s clobbered by the next system call.
        int error_code = errno;

        // The operation didn’t succeed; chown should return -1 on error.
        assert(rval == -1);

        // Check the value of errno, and take appropriate action.
        switch (error_code) {
            case EPERM: 
                /* Permission denied.
                 * The user doesn’t have permission to change ownership of the file. 
                 * This can occur if the user is not the superuser or does not have the required privileges.
                 */

            case EROFS: 
                /* Read-only file system.
                 * The file resides on a read-only file system, and you cannot modify its ownership.
                 */

            case ENAMETOOLONG: 
                /* Filename too long.
                 * The path specified exceeds the allowed maximum length for file paths.
                 */

            case ENOENT: 
                /* File or directory does not exist.
                 * The file at the specified path does not exist, or a component in the path was not found.
                 */

            case ENOTDIR: 
                /* Not a directory.
                 * A component of the path provided is not a directory, but it was expected to be one.
                 */

            case EACCES: 
                /* Permission denied.
                 * A component of the path cannot be accessed because of insufficient permissions, 
                 * such as lacking read or search permission on a parent directory.
                 */

				// Something’s wrong with the file. Print an error message.
				fprintf(stderr, "error changing ownership of %s: %s\n", path, strerror(error_code));
				break;

            case EFAULT:
                /* Invalid address.
                 * The path points to an invalid memory address, which likely indicates a bug.
                 */
                abort();

            case ENOMEM:
                /* Out of memory.
                 * The system has run out of kernel memory to complete the operation.
                 */
                fprintf(stderr, "%s\n", strerror(error_code));
                exit(1);

            default:
                /* Unexpected error.
                 * This handles any other errors that are not explicitly covered by the previous cases.
                 */
                abort();
        }
    } 
	else {
        printf("Ownership of file '%s' successfully changed to user ID %d\n", path, user_id);
    }

    return 0;
}


/*

# README


To get the user id:

```
id -u
id -u <username>
```

To run the example:


```
gcc -o chown_example errors_from_sycalls.c
./chown_example /path/to/file <uid>
```

*/