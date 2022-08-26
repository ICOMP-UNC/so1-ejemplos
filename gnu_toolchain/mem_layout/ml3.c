#include <stdio.h>

int global; /* Uninitialized variable stored in bss*/

int main(void)
{
  static int i; /* Uninitialized static variable stored in bss */
  return 0;
}
