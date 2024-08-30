/*
Square root of a number (square.c)
++++++++++++++++++++++++++++++++++
*/

#include <stdio.h>
#include <math.h>

int main()
{
   float num, root;
   printf("Enter a number: ");
   
   // Reads character input from the user
   scanf("%f", &num);
   
   root = sqrt(num);
   printf("Square root of %.2f = %.2f", num, root);
  
  return 0;
}

/*
Compile
--------
gcc square.c -lm -o square

Output
------
Enter a number: 12
Square root of 12.00 = 3.46

*/


