#include <stdio.h>

/*
 * Bss (aka: Better save space). 
 * The bss variables are not copied into the section. 
 * Instead, memory addresses are reserved.
 *
*/

int global; /* Uninitialized variable stored in bss*/
// int global1; /* Uninitialized variable stored in bss*/
//int global2; /* Uninitialized variable stored in bss*/
//int global3; /* Uninitialized variable stored in bss*/

int main(void)
{
  return 0;
}
