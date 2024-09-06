/*
 * Example program using getopt() to handle two program options:
 * -n: A flag with no associated value.
 * -t <val>: Expects an associated value (number of seconds).
 *
 * Usage:
 *   ./program [-n] [-t <nsecs>] [name]
 * 
 * If only -n is provided, the name argument is optional.
 */

#include <unistd.h>  // for getopt()
#include <stdlib.h>  // for atoi(), exit()
#include <stdio.h>   // for printf(), fprintf()

int main(int argc, char *argv[]) {
    int flag_n = 0;         // Set when -n is provided
    int seconds = 0;        // Value provided by -t <nsecs>
    int t_option_provided = 0; // Flag to track if -t was given
    int opt;                // To hold options from getopt()

    // Parse command-line options
    while ((opt = getopt(argc, argv, "nt:")) != -1) {
        switch (opt) {
            case 'n':
                flag_n = 1; // Set flag when -n is provided
                break;
            case 't':
                seconds = atoi(optarg); // Convert the argument to an integer
                if (seconds <= 0) { // Check for valid input
                    fprintf(stderr, "Invalid value for -t: %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
                t_option_provided = 1;
                break;
            default: // '?' case for unknown options
                fprintf(stderr, "Usage: %s [-n] [-t <nsecs>] [name]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Display parsed options and their values
    printf("Flag -n: %d\n", flag_n);
    printf("Option -t: %d (provided: %d)\n", seconds, t_option_provided);
    printf("optind (index of first non-option argument): %d\n", optind);

    // If the -n option is not provided, ensure at least one non-option argument (name) is required
    if (optind >= argc && !flag_n) {
        fprintf(stderr, "Expected a name argument after options\n");
        exit(EXIT_FAILURE);
    }

    // Display the non-option argument (name) if provided
    if (optind < argc) {
        printf("Name argument: %s\n", argv[optind]);
    } else if (flag_n) {
        printf("No name provided, but -n option was given.\n");
    }

    // Other code logic can be added here

    // Exit successfully
    return EXIT_SUCCESS;
}


/*

```bash
./program -n -t 5 myname
```

argv[0] = "./program"
argv[1] = "-n"
argv[2] = "-t"
argv[3] = "5"
argv[4] = "myname"

### optind

optind is used to indicate the index in argv[] where the
first non-option argument is located after option processing.

### How `optind` Works:

- **Initially**: `optind` is set to 1, as the first element (`argv[0]`) is the program name.
- **During Parsing**: Each time `getopt()` processes an option (e.g., `-n` or `-t`), it increments `optind`.
- **After Parsing**: When `getopt()` finishes processing all options,
 `optind` will point to the first argument that is **not** an option (i.e., not starting with `-`).

*/