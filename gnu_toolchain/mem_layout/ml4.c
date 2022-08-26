#include <stdio.h>

int global; /* Uninitialized variable stored in bss*/

int main(void)
{
  static int i = 100; /* Initialized static variable stored in DS*/
  return 0;
}
