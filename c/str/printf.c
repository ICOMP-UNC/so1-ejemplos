// To print Pi to five decimal places:

#include <math.h>
#include <stdio.h>
fprintf(stdout, "pi = %.5f\n", 4 * atan(1.0));

// To print a date and time in the form "Sunday,  July  3,  10:02",  where
// weekday and month are pointers to strings:

#include <stdio.h>
fprintf(stdout, "%s, %s %d, %.2d:%.2d\n", weekday, month, day, hour, min);

// Many  countries use the day-month-year order.  Hence, an international‐
// ized version must be able to print the arguments in an order  specified
// by the format:

#include <stdio.h>
fprintf(stdout, format,
       weekday, month, day, hour, min);

// where  format  depends  on locale, and may permute the arguments.  With
// the value:

// "%1$s, %3$d. %2$s, %4$d:%5$.2d\n"

// one might obtain "Sonntag, 3. Juli, 10:02".

// To allocate a sufficiently large string and print into it (code correct
// for both glibc 2.0 and glibc 2.1):

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *
make_message(const char *fmt, ...)
{
   int size = 0;
   char *p = NULL;
   va_list ap;

   /* Determine required size */

   va_start(ap, fmt);
   size = vsnprintf(p, size, fmt, ap);
   va_end(ap);

   if (size < 0)
       return NULL;

   size++;             /* For '\0' */
   p = malloc(size);
   if (p == NULL)
       return NULL;

   va_start(ap, fmt);
   size = vsnprintf(p, size, fmt, ap);
   va_end(ap);

   if (size < 0) {
       free(p);
       return NULL;
   }

   return p;
}

// If  truncation occurs in glibc versions prior to 2.0.6, this is treated
// as an error instead of being handled gracefully.
