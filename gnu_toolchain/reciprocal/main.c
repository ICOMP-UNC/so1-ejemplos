#include <stdio.h>

/*
warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
    9 |  i = atoi(argv[1]);
      |      ^~~~
*/
#include <stdlib.h>

#include "reciprocal.hpp"


int main (int argc, char **argv)
{

	if (argc < 2) {
               fprintf(stderr, "Usage: %s str [base]\n", argv[0]);
               exit(EXIT_FAILURE);
    }

	int j;
	j = atoi(argv[1]);
	printf("The reciprocal of %d is %g\n", j, reciprocal(j));
	
  return 0;
}


/*
Bugs

1) no arg1
----------

./reciprocal 
Segmentation fault (core dumped)

Fix
---
if (argc < 2) {
               fprintf(stderr, "Usage: %s str [base]\n", argv[0]);
               exit(EXIT_FAILURE);
           }

2) arg1 is 0
------------

./reciprocal 0
reciprocal: reciprocal.cpp:7: double reciprocal(int): Assertion `i != 0' failed.
Aborted (core dumped)

*/