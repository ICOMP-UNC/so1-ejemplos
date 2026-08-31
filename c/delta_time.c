/* Program to measure time taken by a function */
#include <stdio.h>
#include <time.h>
 
/*A function that terminates when enter key is pressed*/
void critical_function()
{
    printf("critical_function() starts \n");
    printf("Press enter to stop critical_function \n");
    while (1) {
        printf("Press\n");
        if (getchar())
            break;
    }
    printf("critical_function() ends \n");
}
 
/*The main program calls critical_function() and measures time taken by critical_function()*/
int main()
{
    // Calculate the time taken by critical_function()
    clock_t t;
    t = clock();    //clock() is measured in ticks per second, and does not include the time the user takes to press the enter key
    critical_function();
    clock_t dt = clock() - t;

    /*
    * Clock ticks per second
    * This macro expands to an expression representing the number of clock ticks per second.
    * Clock ticks are units of time of a constant but system-specific length, as those returned by function clock.
    * Dividing a count of clock ticks by this expression yields the number of seconds.
    */
    double time_taken_sec = ((double)dt)/CLOCKS_PER_SEC; // CLOCKS_PER_SEC = 1000000, defined in time.h
 
    printf("CLOCKS_PER_SEC %ld \n", CLOCKS_PER_SEC);
    printf("critical_function() took %f seconds to execute \n", time_taken_sec);
    return 0;
}
