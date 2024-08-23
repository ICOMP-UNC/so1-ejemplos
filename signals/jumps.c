#include <setjmp.h>

jmp_buf buf;

//setjmp/longjmp example
int main()
{
	if (setjmp(buf) != 0) {
	  printf(“back in main due to an error\n”);
	else
	  printf(“first time through\n”);

	p1(); /* p1 calls p2, which calls p3 */
} 

void p3()
{
   //<error checking code>
   if (error)
      longjmp(buf, 1)
} 
