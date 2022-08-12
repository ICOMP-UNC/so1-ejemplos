# include <stdio.h>

/* 
 * Factorial of a non-negative integer, is multiplication of all integers 
 * smaller than or equal to n. 
 * For example factorial of 6 is 6*5*4*3*2*1 which is 720.
*/
int main()
{
    int i, num, j;
    printf ("Enter the number: ");
    scanf ("%d", &num );

    for (i=1; i<num; i++)
        j=j*i;    

    printf("The factorial of %d is %d\n",num,j);
}

/*
$ gcc factorial.c
$ ./a.out
Enter the number: 3
The factorial of 3 is 12548672
*/