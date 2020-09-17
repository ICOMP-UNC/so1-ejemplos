/*
 * The following trivial example program uses getopt() to handle two  pro‐
 * gram  options:  -n, with no associated value; and -t val, which expects
 * an associated value.
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
   int flags, opt;
   int nsecs, tfnd;

   nsecs = 0;
   tfnd = 0;
   flags = 0;
   
   while ((opt = getopt(argc, argv, "nt:")) != -1) {
       switch (opt) {
         case 'n':
             flags = 1;
             break;
         case 't':
             nsecs = atoi(optarg);
             tfnd = 1;
             break;
         default: /* '?' */
             fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
             exit(EXIT_FAILURE);
       }
   }
   printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n",
           flags, tfnd, nsecs, optind);

   if (optind >= argc) {
       fprintf(stderr, "Expected argument after options\n");
       exit(EXIT_FAILURE);
   }

   printf("name argument = %s\n", argv[optind]);

   /* Other code omitted */

   exit(EXIT_SUCCESS);
}
