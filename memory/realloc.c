#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void foo (int len, int extra)
{
  int i, *p;
  
  /* allocate a block of len ints */
  if ((p = (int *) malloc(len * sizeof(int))) == NULL) {
    fprintf(stderr, "malloc failed: %s\n", strerror(errno));
    exit(1);
  }

  for (i = 0; i < len; i++)
    p[i] = i;

  /* add m ints to end of p block */
  if ((p = (int *) realloc(p, (len+extra) * sizeof(int))) == NULL) {
    fprintf(stderr, "realloc failed: %s\n", strerror(errno));
    exit(1);
  }

  for (i = len; i < len+extra; i++)
    p[i] = i;

  /* print new array */  
  for (i = 0; i < len+extra; i++)
    printf("%d\n", p[i]);

  free(p); /* return p to available memory pool */
}

int main()
{
  foo(10, 15);
}
